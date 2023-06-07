/*
** EPITECH PROJECT, 2022
** bsq.c
** File description:
** find the biggest square in a given map
*/
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/my_bsq.h"


int check_char(char *filepath)
{
    struct stat stock;
    int error = stat(filepath, &stock);
    char *buffer = malloc(sizeof(char) * (stock.st_size + 1));
    int fd = open(filepath, O_RDONLY);
    int i = 0;

    if (fd < 0)
        return (84);
    error = read(fd, buffer, stock.st_size);
    for (i = 0; buffer[i] != '\n'; i++) {
        if (buffer[i] < '0' || buffer[i] > '9')
            return (84);
    }
    for (; buffer[i] != '\0'; i++) {
        if (buffer[i] != '.' && buffer[i] != 'o' && buffer[i] != '\n')
            return (84);
    }
    close(fd);
    free(buffer);
    return (0);
}

char **create_map(int ag, char **av, int *square)
{
    square[NB_ROWS] = my_getnbr(av[1]);
    square[NB_COLS] = square[NB_ROWS];
    char **map = malloc (sizeof(char *) * (square[NB_ROWS] + 1));
    char temp;
    int l = 0;
    for (int i = 0; i < square[NB_ROWS]; i++)
        map[i] = malloc(sizeof(char) * square[NB_COLS]);
    my_strcpy(map[0], av[2]);
    for (int k = my_strlen(av[2]); k < square[NB_COLS]; k++)
        map[0][k] = map[0][k - my_strlen(av[2])];
    map[0][square[NB_COLS] + 1] = '\0';
    for (int j = 1; j < square[NB_ROWS]; j++) {
        for (l = 0; l < square[NB_COLS]; l++) {
            temp = map[j - 1][0];
            map[j][l] = map[j - 1][l + 1];
        }
        map[j][l - 1] = temp;
    }
    for (int u = 0; u < square[NB_ROWS]; u++)
    return (map);
}

void destroy_map(char **map, int nb_rows)
{
    for (int b = 0; b < nb_rows; b++)
        free(map[b]);
    free(map);
}

int main(int ag, char **av)
{
    if (ag != 2 && ag != 3)
        return (84);
    int square[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    char **map;
    int error = 0;

    if (ag == 2) {
        error = check_char(av[1]);
        if (error != 0)
            return (84);
        square[NB_ROWS] = fs_get_number_from_first_line(av[1]);
        square[NB_COLS] = fs_count_first_line(av[1]);
        map = load_2d_arr_from_file(av[1], square[NB_ROWS], square[NB_COLS]);
    } else
        map = create_map(ag, av, square);
    error = call_functions(map, square);
    if (error != 0)
        return (84);
    destroy_map(map, square[NB_ROWS]);
    return (0);
}
