/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main file my_sokoban
*/

#include "../includes/my_sokoban.h"

char *my_strdup(char *str)
{
    char *result;
    int size;

    size = 0;
    for (; str[size]; size++);
    if (!size) {
        result = malloc(sizeof(char));
        result[0] = '\0';
        return result;
    }
    result = malloc(sizeof(char) * (size + 1));
    for (int i = 0; i < size; i++) {
        result[i] = str[i];
    }
    result[size] = '\0';
    return result;
}

int my_strlen(char *str)
{
    int i;

    i = 0;
    for (; str[i]; i++);
    return i;
}

char **display_map(char **map, char *buffer)
{
    int i;
    char **original_map;

    i = 0;
    original_map = load_map(buffer);
    initscr();
    keypad(stdscr, TRUE);
    for (; map[i]; i++)
        printw(map[i]);
    refresh();
    return original_map;
}

static void free_all(char *buffer, char **map, char **original)
{
    int i;

    i = 0;
    endwin();
    free(buffer);
    for (; map[i]; i++) {
        free(map[i]);
        free(original[i]);
    }
    free(map);
    free(original);
}

/*
This function returns 0 if win (to break the while loop in function game),
else 1.
*/
static int check_win(char **map, char **original)
{
    int i = 0;
    int j = 0;

    for (; original[i]; j++) {
        if (original[i][j] == 'O' && map[i][j] != 'X')
            return 1;
        if (original[i][j] == '\n') {
            j = 0;
            i++;
        }
    }
    return 0;
}

static int check_lose(char **map)
{
    int i = 0;
    int j = 0;
    int nb_X = 0;
    int nb_blocked = 0;

    for (; map[i]; j++) {
        if (map[i][j] == 'X')
            nb_X++;
        if (map[i][j] == 'X' && ((map[i - 1][j] == '#' && map[i][j - 1] == '#')
        || (map[i - 1][j] == '#' && map[i][j + 1] == '#') ||
        (map[i + 1][j] == '#' && map[i][j + 1] == '#') ||
        (map[i + 1][j] == '#' && map[i][j - 1] == '#')))
            nb_blocked++;
        if (map[i][j] == '\n') {
            j = 0;
            i++;
        }
    }
    return nb_X == nb_blocked;
}

int game(int ac, char **av)
{
    char *buffer;
    char **map;
    char **original_map;
    int ch = 0;

    buffer = create_buffer(av[1]);
    if (!buffer)
        return 84;
    map = load_map(buffer);
    original_map = display_map(map, buffer);
    while (ch != 27 && check_win(move_player(map, ch, original_map),
        original_map)) {
        ch = getch();
        if (check_lose(map)) {
            free_all(buffer, map, original_map);
            return 1;
        }
    }
    free_all(buffer, map, original_map);
    return 0;
}

static int my_strcmp(char *s1, char *s2)
{
    int i;

    if (my_strlen(s1) != my_strlen(s2))
        return 0;
    for (i = 0; s1[i]; i++) {
        if (s1[i] != s2[i])
            return 0;
    }
    return 1;
}

static void print_help(void)
{
    my_putstr("USAGE\n\t./my_sokoban map\nDESCRIPTION\n\tmap\tfile ");
    my_putstr("representing the warehouse map, containing '#' for walls,\n");
    my_putstr("\t\t'P' for the player, 'X' for boxes and 'O' for storage ");
    my_putstr("locations.\n");
}

int main(int ac, char **av)
{
    int verify;

    if (ac != 2)
        return 84;
    if (my_strcmp(av[1], "-h") || my_strcmp(av[1], "--help")) {
        print_help();
        return 0;
    }
    verify = game(ac, av);
    if (verify == 84)
        return 84;
    else if (verify == 1)
        return 1;
    return 0;
}
