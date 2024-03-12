/*
** EPITECH PROJECT, 2024
** move_player.c
** File description:
** File where the functions allowing the player to move are located
*/

#include "../includes/my_sokoban.h"

int *pos_player(char **map)
{
    int *position = malloc(sizeof(int) * 2);
    int i = 0;
    int j = 0;

    for (; map[i]; j++) {
        if (map[i][j] == 'P')
            break;
        if (!map[i][j]) {
            i++;
            j = 0;
        }
    }
    position[0] = i;
    position[1] = j;
    return position;
}

static char **move_up(char **map)
{
    int *pos = pos_player(map);

    if (!map[pos[0] - 1][pos[1]] || map[pos[0] - 1][pos[1]] == '#')
        return map;
    if (map[pos[0] - 1][pos[1]] == 'O')
        map[pos[0] - 1][pos[1]] = ' ';
    if (map[pos[0] - 1][pos[1]] == 'X' && map[pos[0] - 2][pos[1]] == 'O')
        map[pos[0] - 2][pos[1]] = ' ';
    if (map[pos[0] - 1][pos[1]] == ' ')
        my_swap(&map[pos[0]][pos[1]], &map[pos[0] - 1][pos[1]]);
    if (map[pos[0] - 1][pos[1]] == 'X' && map[pos[0] - 2][pos[1]] == ' ')
        my_swap_three(&map[pos[0]][pos[1]], &map[pos[0] - 1][pos[1]],
                    &map[pos[0] - 2][pos[1]]);
    return map;
}

static char **move_down(char **map)
{
    int *pos = pos_player(map);

    if (!map[pos[0] + 1][pos[1]] || map[pos[0] + 1][pos[1]] == '#')
        return map;
    if (map[pos[0] + 1][pos[1]] == 'O')
        map[pos[0] + 1][pos[1]] = ' ';
    if (map[pos[0] + 1][pos[1]] == 'X' && map[pos[0] + 2][pos[1]] == 'O')
        map[pos[0] + 2][pos[1]] = ' ';
    if (map[pos[0] + 1][pos[1]] == ' ')
        my_swap(&map[pos[0]][pos[1]], &map[pos[0] + 1][pos[1]]);
    if (map[pos[0] + 1][pos[1]] == 'X' && map[pos[0] + 2][pos[1]] == ' ')
        my_swap_three(&map[pos[0]][pos[1]], &map[pos[0] + 1][pos[1]],
                    &map[pos[0] + 2][pos[1]]);
    return map;
}

static char **move_left(char **map)
{
    int *pos = pos_player(map);

    if (!map[pos[0]][pos[1] - 1] || map[pos[0]][pos[1] - 1] == '#')
        return map;
    if (map[pos[0]][pos[1] - 1] == 'O')
        map[pos[0]][pos[1] - 1] = ' ';
    if (map[pos[0]][pos[1] - 1] == 'X' && map[pos[0]][pos[1] - 2] == 'O')
        map[pos[0]][pos[1] - 2] = ' ';
    if (map[pos[0]][pos[1] - 1] == ' ')
        my_swap(&map[pos[0]][pos[1]], &map[pos[0]][pos[1] - 1]);
    if (map[pos[0]][pos[1] - 1] == 'X' && map[pos[0]][pos[1] - 2] == ' ')
        my_swap_three(&map[pos[0]][pos[1]], &map[pos[0]][pos[1] - 1],
                    &map[pos[0]][pos[1] - 2]);
    return map;
}

static char **move_right(char **map)
{
    int *pos = pos_player(map);

    if (!map[pos[0]][pos[1] + 1] || map[pos[0]][pos[1] + 1] == '#')
        return map;
    if (map[pos[0]][pos[1] + 1] == 'O')
        map[pos[0]][pos[1] + 1] = ' ';
    if (map[pos[0]][pos[1] + 1] == 'X' && map[pos[0]][pos[1] + 2] == 'O')
        map[pos[0]][pos[1] + 2] = ' ';
    if (map[pos[0]][pos[1] + 1] == ' ')
        my_swap(&map[pos[0]][pos[1]], &map[pos[0]][pos[1] + 1]);
    if (map[pos[0]][pos[1] + 1] == 'X' && map[pos[0]][pos[1] + 2] == ' ')
        my_swap_three(&map[pos[0]][pos[1]], &map[pos[0]][pos[1] + 1],
                    &map[pos[0]][pos[1] + 2]);
    return map;
}

static void print_map(char **map)
{
    clear();
    for (int i = 0; map[i]; i++)
        printw(map[i]);
    refresh();
}

char **reset_map(char **map, char **original)
{
    int i = 0;

    for (; original[i]; i++)
        map[i] = my_strdup(original[i]);
    return map;
}

char **replace_storage(char **map, char **original)
{
    int i = 0;
    int j = 0;

    for (; original[i]; j++) {
        if (original[i][j] == 'O' && map[i][j] == ' ')
            map[i][j] = 'O';
        if (original[i][j] == '\n') {
            j = 0;
            i++;
        }
    }
    return map;
}

char **move_player(char **map, int key_pressed, char **original)
{
    switch (key_pressed) {
    case KEY_DOWN:
        map = move_down(map);
        break;
    case KEY_UP:
        map = move_up(map);
        break;
    case KEY_LEFT:
        map = move_left(map);
        break;
    case KEY_RIGHT:
        map = move_right(map);
        break;
    case 32:
        map = reset_map(map, original);
    }
    map = replace_storage(map, original);
    print_map(map);
    return map;
}
