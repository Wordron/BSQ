/*
** EPITECH PROJECT, 2022
** fs_print_first_line.c
** File description:
** print the first line of the file
*/
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "include/my.h"

int fs_count_first_line(char const *filepath)
{
    struct stat stock;
    int fd = open(filepath, O_RDONLY);
    int i = 0;
    int y = 0;
    char *buffer = malloc(sizeof(char) * (stock.st_size + 1));
    int error = read(fd, buffer, 500);

    if (error < 0 || fd < 0) {
        close(fd);
        return (-1);
    }
    for (y = 0; buffer[y] != '\n';)
        y++;
    y++;
    for (i = 0; buffer[y] != '\n'; y++)
        i++;
    close(fd);
    free(buffer);
    return (i);
}
