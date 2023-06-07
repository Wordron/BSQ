/*
** EPITECH PROJECT, 2022
** is_square_of_size.c
** File description:
** find the square of a given size
*/
#include "include/my.h"
#include "include/my_bsq.h"
#include <stddef.h>

int check_line(char **map, int *init)
{
    for (int y = 0; y < init[SQUARE_SIZE]; y++) {
        if (map[init[ROW] + init[I]][init[COL] + y] != '.')
            return (0);
    }
}

int is_square_of_size(char **map, int row, int col, int square_size)
{
    int nb_col = my_strlen(map[0]);
    int nb_row = 0;
    int error = 0;
    int init[4] = {row, col, 0, square_size};

    for (nb_row = 0; map[nb_row] != NULL;)
        nb_row++;
    if (square_size > nb_col || square_size > nb_row ||
        (square_size + row) > nb_row || (square_size + col) > nb_col)
        return (0);
    for (int i = 0; i < square_size; i++) {
        init[I] = i;
        error = check_line(map, init);
        if (error == 0)
            return (0);
    }
    return (1);
}
