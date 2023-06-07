/*
** EPITECH PROJECT, 2022
** core_of_bsq.c
** File description:
** get the biggest square, replace the '.' by 'x' and print the map
*/
#include <unistd.h>
#include "include/my.h"
#include "include/my_bsq.h"

int find_square(char **map, int *square)
{
    for (; square[ROW_BSQ] < square[NB_ROWS]; square[ROW_BSQ]++) {
        for (square[COL_BSQ] = 0; square[COL_BSQ] < square[NB_COLS];
            square[COL_BSQ]++)
            find_biggest_square(map, square);
    }
    return (0);
}

int modifi_map(char **map, int *square)
{
    for (int i = 0; i < square[SIZE_MAX]; i++) {
        for (int j = 0; j < square[SIZE_MAX]; j++)
            map[square[ROW_BIGGEST] + i][square[COL_BIGGEST] + j] = 'x';
    }
    return (0);
}

int print_map(char **map, int *square)
{
    for (int y = 0; y < square[NB_ROWS]; y++) {
        write(1, map[y], square[NB_COLS]);
        my_putchar('\n');
    }
    return (0);
}

int call_functions(char **map, int *square)
{
    if (square[NB_COLS] != 1 || square[NB_ROWS] != 1) {
        find_square(map, square);
        modifi_map(map, square);
    }
    if (square[NB_COLS] == 1 || square[NB_ROWS] == 1)
        map[0][0] = 'x';
    print_map(map, square);
}
