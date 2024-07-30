/*
** EPITECH PROJECT, 2024
** bs_sokoban.h
** File description:
** header file my_sokoban
*/

#ifndef MY_SOKOBAN_H
    #define MY_SOKOBAN_H
    #include <unistd.h>
    #include <ncurses.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <sys/stat.h>

/* structure */

typedef struct storage_location_s {
    int pos_x;
    int pos_y;
    char char_storage;
} storage_location_t;

/* print_str.c */

int my_putchar(char c);
void my_putstr(char *str);

/* load_map.c */

int size_map(char *filepath);
char *create_buffer(char *filepath);
char **load_map(char *buffer);

/* swaps.c */

void my_swap(char *a, char *b);
void my_swap_three(char *a, char *b, char *c);

/* move_player.c */

int *pos_player(char **map);
char **reset_map(char **map, char **original);
char **replace_storage(char **map, char **original);
char **move_player(char **map, int key_pressed, char **original);

/* check_lose.c */

int is_blocked_walls(char **map, int i, int j, int nb_blocked);
int is_blocked_box(char **map, int i, int j, int nb_blocked);
int check_lose(char **map);

/* main.c */

char *my_strdup(char *str);
int my_strlen(char *str);
char **display_map(char **map, char *buffer);
int game(int ac, char **av);

#endif /* MY_SOKOBAN_H */
