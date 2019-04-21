/*
** EPITECH PROJECT, 2019
** set_map.c
** File description:
** initialization of the map
*/

#include "../include/sokoban.h"

char *open_file(char *file)
{
    int fd = open(file, O_RDONLY);
    char *buff = malloc(sizeof(char) * 4096);
    int offset = 0;
    int len = 0;
    struct stat filestat;

    stat(file, &filestat);
    if (fd != -1 && filestat.st_size > 0) {
        while ((len = read(fd, buff + offset , 4096 - offset)) > 0) {
            offset = offset + len;
        }
        buff[offset] = '\0';
        if (len < 0)
            return (0);
        else
            return (buff);
    }
    return (0);
}

int map_size(info_t *s)
{
    s->height = 1;
    s->width = 0;
    for (int i = 0; s->buff[i] != '\0'; i = i + 1) {
        if (s->buff[i] == '\n')
            s->height = s->height + 1;
    }
    for (int j = 0; s->buff[j] != '\n'; j = j + 1)
        s->width = s->width + 1;
    if (s->width < 4 || s->height < 3 ||
    invalid_map(s->buff, s->width, s->height) == 1)
        return (84);
    else
        return (0);
}

void to_double_array(info_t *s)
{
    int array = 0;

    s->map = malloc(sizeof(*s->map) * s->height);
    for (int i = 0; i < s->height; i = i + 1) {
        s->map[i] = malloc(sizeof(char) * s->width + 2);
        for (int j = 0; j < (s->width + 1); j = j + 1) {
            s->map[i][j] = s->buff[array];
            array = array + 1;
        }
        s->map[i][s->width + 1] = '\0';
    }
    s->save_map = malloc(sizeof(*s->save_map) * s->height);
    for (int i = 0; i < s->height; i = i + 1) {
        s->save_map[i] = malloc(sizeof(char) * s->width + 2);
        for (int j = 0; j < (s->width + 1); j = j + 1)
            s->save_map[i][j] = s->map[i][j];
        s->save_map[i][s->width + 1] = '\0';
    }
}

void player_position(info_t *s)
{
    int x = 0;
    int y = 0;

    while (y < s->height) {
        if (s->map[y][x] == 'P') {
            s->p_x = x;
            s->p_y = y;
            s->map[y][x] = ' ';
            x = x + 1;
        } else if (x == s->width) {
            x = 0;
            y = y + 1;
        } else
            x = x + 1;
    }
}