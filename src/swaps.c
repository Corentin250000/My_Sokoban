/*
** EPITECH PROJECT, 2023
** swaps.c
** File description:
** function for move ingame
*/

#include "../includes/my_sokoban.h"

void my_swap(char *a, char *b)
{
    char tempa = *a;
    char tempb = *b;

    *a = tempb;
    *b = tempa;
}

/*
a -> c
b -> a
c -> b
*/
void my_swap_three(char *a, char *b, char *c)
{
    char tempa = *a;
    char tempb = *b;
    char tempc = *c;

    *a = tempc;
    *b = tempa;
    *c = tempb;
}
