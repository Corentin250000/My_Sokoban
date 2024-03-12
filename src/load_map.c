/*
** EPITECH PROJECT, 2024
** load_map.c
** File description:
** File where the functions who loading the map into array of array of chars
*/

#include "../includes/my_sokoban.h"

int size_map(char *filepath)
{
    int verify;
    struct stat s;

    verify = stat(filepath, &s);
    if (verify == -1)
        return 0;
    return s.st_size;
}

static int verify_buffer(char *buffer)
{
    int i = 0;
    int nb_X = 0;
    int nb_O = 0;
    int nb_P = 0;

    for (; buffer[i]; i++) {
        if (buffer[i] != ' ' && buffer[i] != '\n' && buffer[i] != 'X'
            && buffer[i] != 'P' && buffer[i] != '#' && buffer[i] != 'O')
            return 84;
        if (buffer[i] == 'X')
            nb_X++;
        if (buffer[i] == 'O')
            nb_O++;
        if (buffer[i] == 'P')
            nb_P++;
    }
    if (nb_P == 1 || nb_O == nb_P)
        return 0;
    else
        return 84;
}

char *create_buffer(char *filepath)
{
    int fd;
    int size;
    char *buffer;
    int verify;

    if (!filepath)
        return NULL;
    size = size_map(filepath);
    buffer = malloc(sizeof(char) * size);
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return NULL;
    if (read(fd, buffer, size) == -1)
        return NULL;
    close(fd);
    verify = verify_buffer(buffer);
    if (verify == 84)
        return NULL;
    return buffer;
}

static int nb_char_in_line(int index_begin, char *str)
{
    int nb_char = 0;

    for (int i = index_begin; str[i - 1] != '\n'; i++) {
        nb_char++;
    }
    return nb_char;
}

static int nb_backslash_n(char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != 0; i++)
        nb += str[i] == '\n' ? 1 : 0;
    return nb;
}

char **load_map(char *buffer)
{
    char **result = malloc(sizeof(char *) * nb_backslash_n(buffer) +
        sizeof(NULL));
    int index = 0;
    int i = 0;
    int j = 0;

    for (int i = 0; i < nb_backslash_n(buffer); i++) {
        result[i] = malloc(nb_char_in_line(index + 1, buffer));
        index += nb_char_in_line(index, buffer);
    }
    for (index = 0; buffer[index] != 0; index++) {
        result[i][j] = buffer[index];
        j++;
        if (buffer[index] == '\n') {
            j = 0;
            i++;
        }
    }
    return result;
}
