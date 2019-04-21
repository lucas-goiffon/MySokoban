/*
** EPITECH PROJECT, 2018
** to_name.c
** File description:
** Following of my_sokoban project
*/

#include "../include/sokoban.h"

int read_and_errors(int ac, char **av, info_t *s)
{
    if (ac != 2) {
        write(2, "Where is the map ?\n", 19);
        s->r = 84;
        return (84);
    } else {
        if (av[1][0] == '-' && av[1][1] == 'h' &&
            av[1][2] == '\0') {
            h_flag();
            s->r = 0;
            return (84);
        } else if ((s->buff = open_file(av[1])) == 0) {
            write(2, "Invalid map\n", 12);
            s->r = 84;
            return (84);
        }
    }
    return (0);
}

void h_flag(void)
{
    my_printf("USAGE\n    ./my_sokoban [map]\n\nDESCRIPTION\n    ");
    my_printf("Map file representing the warehouse map, containing ");
    my_printf("'#' for walls, 'P' for the player, 'X' for boxes and");
    my_printf(" 'O' for storage locations.\n\nGOAL\n    ");
    my_printf("Push the boxes on storage locations. Move with ");
    my_printf("arrow keys. Press space to restart, and 'q' to quit\n");
}

void small_window(info_t *s)
{
    while ((s->height > LINES || s->width > COLS) && s->c != 'q') {
        clear();
        mvprintw(LINES / 2, COLS / 2 - 8, "Window too small!");
        usleep(1);
        refresh();
    }
}

int invalid_map(char *buff, int width, int height)
{
    int fail = 0;
    int count = 0;
    int p = 0;

    for (int i = 0; buff[i] != '\0' && fail == 0; i = i + 1) {
        count = count + 1;
        if (buff[i] == '\n' && count == (width + 1))
            count = 0;
        else if (buff[i] == '\n' && count != (width + 1))
            fail = 1;
        else if (buff[i] == 'P')
            p = p + 1;
    }
    if (p != 1)
        fail = 1;
    return (fail);
}
