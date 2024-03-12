/*
** EPITECH PROJECT, 2024
** print_str.c
** File description:
** File where the functions print a char or a string in shell (not in ncurses)
*/

#include "../includes/my_sokoban.h"

int my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int i;

    for (i = 0; str[i]; i++)
        my_putchar(str[i]);
}
