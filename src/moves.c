/*
** EPITECH PROJECT, 2018
** moves.c
** File description:
** Manage the moves of my_sokoban project
*/

#include "../include/sokoban.h"

void moves(info_t *s)
{
    s->c = getch();
    if (s->c == 'A' || s->c == 'B' || s->c == 'C') {
        if (s->c == 'A')
            upp_key(s);
        else if (s->c == 'B')
            down_key(s);
        else
            right_key(s);
    } else if (s->c == 'D')
        left_key(s);
}

void upp_key(info_t *s)
{
    if (s->map[s->p_y - 1][s->p_x] != '#' &&
    s->map[s->p_y - 1][s->p_x] != 'X')
        s->p_y = s->p_y - 1;
    else if (s->map[s->p_y - 1][s->p_x] == 'X' &&
    s->map[s->p_y - 2][s->p_x] != 'X' &&
    s->map[s->p_y - 2][s->p_x] != '#') {
        s->p_y = s->p_y - 1;
        s->map[s->p_y][s->p_x] = ' ';
        s->map[s->p_y - 1][s->p_x] = 'X';
    }
    reput_o(s);
    end(s);
}

void down_key(info_t *s)
{
    if (s->map[s->p_y + 1][s->p_x] != '#' &&
    s->map[s->p_y + 1][s->p_x] != 'X')
        s->p_y = s->p_y + 1;
    else if (s->map[s->p_y + 1][s->p_x] == 'X' &&
    s->map[s->p_y + 2][s->p_x] != 'X' &&
    s->map[s->p_y + 2][s->p_x] != '#') {
        s->p_y = s->p_y + 1;
        s->map[s->p_y][s->p_x] = ' ';
        s->map[s->p_y + 1][s->p_x] = 'X';
    }
    reput_o(s);
    end(s);
}

void right_key(info_t *s)
{
    if (s->map[s->p_y][s->p_x + 1] != '#' &&
    s->map[s->p_y][s->p_x + 1] != 'X')
        s->p_x = s->p_x + 1;
    else if (s->map[s->p_y][s->p_x + 1] == 'X' &&
    s->map[s->p_y][s->p_x + 2] != 'X' &&
    s->map[s->p_y][s->p_x + 2] != '#') {
        s->p_x = s->p_x + 1;
        s->map[s->p_y][s->p_x] = ' ';
        s->map[s->p_y][s->p_x + 1] = 'X';
    }
    reput_o(s);
    end(s);
}

void left_key(info_t *s)
{
    if (s->map[s->p_y][s->p_x - 1] != '#' &&
    s->map[s->p_y][s->p_x - 1] != 'X')
        s->p_x = s->p_x - 1;
    else if (s->map[s->p_y][s->p_x - 1] == 'X' &&
    s->map[s->p_y][s->p_x - 2] != 'X' &&
    s->map[s->p_y][s->p_x - 2] != '#') {
        s->p_x = s->p_x - 1;
        s->map[s->p_y][s->p_x] = ' ';
        s->map[s->p_y][s->p_x - 1] = 'X';
    }
    reput_o(s);
    end(s);
}
