/*
** EPITECH PROJECT, 2018
** end.c
** File description:
** end of my_sokoban.c
*/

#include "../include/sokoban.h"

void reput_o(info_t *s)
{
    int count = 0;
    int ok = 0;

    for (int y = 0; y < s->height; y = y + 1) {
        for (int x = 0; x < s->width; x = x + 1)
            ok = ok + verify_o(s, x, y, &count);
    }
    if (count == ok && ok > 0)
        s->success = 0;
}

int verify_o(info_t *s, int x, int y, int *count)
{
    int ok = 0;

    if (s->save_map[y][x] == 'O') {
        *count = *count + 1;
        if (s->map[y][x] != 'X')
            s->map[y][x] = 'O';
        else
            ok = ok + 1;
    }
    return (ok);
}

void end(info_t *s)
{
    short int nb_x = 0;
    short int b = 0;

    for (int y = 0; y < s->height; y = y + 1) {
        for (int x = 0; x < s->width; x = x + 1)
            b = b + blocked(s, x, y, &nb_x);
    }
    if (nb_x == b && b != 0)
        s->c = 'q';
}

short int blocked(info_t *s, int x, int y, short int *nb_x)
{
    short int b = 0;

    for (int m = -1; m < 3; m = m + 2) {
        if (s->map[y][x] == 'X' && s->map[y][x + m] == '#' &&
        s->map[y + 1][x] == '#')
            b = b + 1;
    }
    for (int m = -1; m < 3; m = m + 2) {
        if (s->map[y][x] == 'X' && s->map[y][x + m] == '#' &&
        s->map[y - 1][x] == '#')
            b = b + 1;
    }
    if (s->map[y][x] == 'X')
        *nb_x = *nb_x + 1;
    return (b);
}

void destroys(info_t *s)
{
    free(s->buff);
    for (int i = 0; i < s->height; i = i + 1)
        free(s->map[i]);
    free(s->map);
    for (int i = 0; i < s->height; i = i + 1)
        free(s->save_map[i]);
    free(s->save_map);
}
