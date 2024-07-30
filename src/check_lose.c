/*
** EPITECH PROJECT, 2024
** check_lose.c
** File description:
** check lose
*/

#include "../includes/my_sokoban.h"

int is_blocked_box(char **map, int i, int j, int nb_blocked)
{
    if (map[i][j] == 'X' && ((map[i - 1][j] == 'X' && map[i][j - 1] == 'X')
        || (map[i - 1][j] == 'X' && map[i][j + 1] == 'X') ||
        (map[i + 1][j] == 'X' && map[i][j + 1] == 'X') ||
        (map[i + 1][j] == 'X' && map[i][j - 1] == 'X')))
            return nb_blocked + 1;
    if (map[i][j] == 'X' && ((map[i - 1][j] == '#' && map[i][j - 1] == 'X')
        || (map[i - 1][j] == '#' && map[i][j + 1] == 'X') ||
        (map[i + 1][j] == '#' && map[i][j + 1] == 'X') ||
        (map[i + 1][j] == '#' && map[i][j - 1] == 'X')))
            return nb_blocked + 1;
    if (map[i][j] == 'X' && ((map[i - 1][j] == 'X' && map[i][j - 1] == '#')
        || (map[i - 1][j] == 'X' && map[i][j + 1] == '#') ||
        (map[i + 1][j] == 'X' && map[i][j + 1] == '#') ||
        (map[i + 1][j] == 'X' && map[i][j - 1] == '#')))
            return nb_blocked + 1;
    return nb_blocked;
}

int is_blocked_walls(char **map, int i, int j, int nb_blocked)
{
    int temp = nb_blocked;

    temp = is_blocked_box(map, i, j, nb_blocked);
    if (temp != nb_blocked)
        return nb_blocked + 1;
    if (map[i][j] == 'X' && ((map[i - 1][j] == '#' && map[i][j - 1] == '#')
        || (map[i - 1][j] == '#' && map[i][j + 1] == '#') ||
        (map[i + 1][j] == '#' && map[i][j + 1] == '#') ||
        (map[i + 1][j] == '#' && map[i][j - 1] == '#')))
            return nb_blocked + 1;
    return nb_blocked;
}

int check_lose(char **map)
{
    int i = 0;
    int j = 0;
    int nb_X = 0;
    int nb_blocked = 0;

    for (; map[i]; j++) {
        if (map[i][j] == 'X')
            nb_X++;
        nb_blocked = is_blocked_walls(map, i, j, nb_blocked);
        if (map[i][j] == '\n') {
            j = 0;
            i++;
        }
    }
    return nb_X <= nb_blocked;
}
