/*
** EPITECH PROJECT, 2018
** sokoban.h
** File description:
** Includes for my_sokoban project
*/

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

#include <ncurses.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "../lib/my/mylib.h"

typedef struct t_info{
    char *buff;
    int fd;
    int width;
    int height;
    char **map;
    char **save_map;
    int p_x;
    int p_y;
    char c;
    short int success;
    short int r;
} info_t;

/* src/my_sokoban.c */
void win_or_fail(short int success);
void loop(info_t *s);

/* src/set_map.c */
char *open_file(char *file);
int map_size(info_t *s);
void to_double_array(info_t *s);
void player_position(info_t *s);

/* src/moves.c */
void moves(info_t *s);
void upp_key(info_t *s);
void down_key(info_t *s);
void right_key(info_t *s);
void left_key(info_t *s);

/* src/errors.c */
int read_and_errors(int ac, char **av, info_t *s);
void h_flag(void);
void small_window(info_t *s);
int invalid_map(char *buff, int width, int height);

/* src/end.c */
void reput_o(info_t *s);
int verify_o(info_t *s, int x, int y, int *count);
void end(info_t *s);
short int blocked(info_t *s, int x, int y, short int *nb_x);
void destroys(info_t *s);

#endif
