/*
** EPITECH PROJECT, 2022
** find_biggest_square.c
** File description:
** find the biggest square in a file
*/
#include "include/my.h"
#include "include/my_bsq.h"

int find_biggest_square(char **map, int *square)
{
    int error = 8;

    for (square[SIZE] = square[SIZE_MAX]; square[SIZE] < square[NB_ROWS] &&
        square[SIZE] < square[NB_COLS]; square[SIZE]++) {
        error = is_square_of_size(map, square[ROW_BSQ], square[COL_BSQ],
            square[SIZE]);
        if (error == 0)
            return (0);
        if (square[SIZE_MAX] < square[SIZE]) {
            square[SIZE_MAX] = square[SIZE];
            square[ROW_BIGGEST] = square[ROW_BSQ];
            square[COL_BIGGEST] = square[COL_BSQ];
        }
    }
}
