/*
** EPITECH PROJECT, 2018
** my_sokoban.c
** File description:
** Main file of my_sokoban project
*/

#include "../include/sokoban.h"

void win_or_fail(short int success)
{
    if (success == 0)
        my_printf("\n========\nYou win!\n========\n\n");
    else
        my_printf("\n===========\nYou fail...\n===========\n\n");
}

void loop(info_t *s)
{
    initscr();
    curs_set(0);
    s->c = 'w';
    s->success = 1;
    while (s->c != 'q' && s->c != ' ' && s->success == 1) {
        clear();
        small_window(s);
        for (int i = 0; i < s->height; i = i + 1)
            mvprintw(i, 0, s->map[i]);
        mvprintw(s->p_y, s->p_x, "P");
        refresh();
        moves(s);
    }
    endwin();
}

int main(int ac, char **av)
{
    info_t s;

    s.c = ' ';
    if (read_and_errors(ac, av, &s) == 84)
        return (s.r);
    else if (map_size(&s) == 84) {
        write(2, "Invalid map.\n", 13);
        return (84);
    }
    while (s.c == ' ') {
        to_double_array(&s);
        player_position(&s);
        loop(&s);
    }
    destroys(&s);
    win_or_fail(s.success);
    return (s.success);
}