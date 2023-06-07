/*
** EPITECH PROJECT, 2022
** load_2d_arr_from_file.c
** File description:
** load a rectangle in a file in a 2d array
*/
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "include/my.h"

char **load_rectangle(char *buffer, char **file)
{
    int line = 0;
    int col = 0;
    int i = 0;

    for (i = 0; buffer[i] != '\n';)
        i++;
    i++;
    for (i; buffer[i] != '\0'; line++) {
        for (col = 0; buffer[i] != '\n' && buffer[i] != '\0'; i++) {
            file[line][col] = buffer[i];
            col++;
        }
        if (i != my_strlen(buffer))
            i++;
        file[line][col] = '\0';
    }
    file[line] = NULL;
    return (file);
}

char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols)
{
    struct stat stock;
    int error = stat(filepath, &stock);
    char **file = malloc(sizeof(char *) * (nb_rows + 1));
    char *buffer = malloc(sizeof(char) * (stock.st_size + 1));
    int fd = open(filepath, O_RDONLY);

    for (int i = 0; i != nb_rows; i++)
        file[i] = malloc(sizeof(char) * (nb_cols + 1));
    if (fd < 0) {
        free(buffer);
        return (0);
    }
    error = read(fd, buffer, stock.st_size);
    load_rectangle(buffer, file);
    close(fd);
    free(buffer);
    return (file);
}
