/*
** EPITECH PROJECT, 2022
** fs_get_number_from_first_line.c
** File description:
** print the positive number on the first line
*/
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "include/my.h"

int check_number(char *buffer)
{
    int if_no_nb = 0;

    for (int i = 0; buffer[i] != '\n' && buffer[i] != '\0'; i++) {
        if (buffer[i] == '-' && (buffer[i + 1] > '0' ||
        buffer[i + 1] < '9')) {
            return (-1);
        }
        if (buffer[i] >= '0' && buffer[i] <= '9')
            if_no_nb = 1;
    }
    if (if_no_nb != 1)
        return (-1);
    return (my_getnbr(buffer));
}

int fs_get_number_from_first_line(char const *filepath)
{
    struct stat stock;
    int error = 0;
    int fd = open(filepath, O_RDONLY);
    char *buffer;
    int number = 0;

    stat(filepath, &stock);
    buffer = malloc(sizeof(char) * (stock.st_size + 1));
    if (fd < 0)
        return (-1);
    error = read(fd, buffer, 500);
    if (error < 0) {
        close(fd);
        return (-1);
    }
    close(fd);
    number = check_number(buffer);
    free(buffer);
    return (number);
}
