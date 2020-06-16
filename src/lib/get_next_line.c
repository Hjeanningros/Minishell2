/*
** EPITECH PROJECT, 2019
** get_next_line.c
** File description:
** A LED!!!!!!!!!!!!!!!!!
*/

#include <stdlib.h>
#include "../../include/get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

int my_strleng(char *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    for (; str[i] != '\0'; i++);
    return (i);
}

char *my_strcatg(char *dest, char *src, int *i)
{
    char *result = malloc(sizeof(char) *
                    my_strleng(dest) + my_strleng(src) + 1);
    int j = 0;

    if (result == NULL || my_strleng(src) == 0)
        return (NULL);
    for (j = 0; dest != NULL && dest[j] != '\0'; j++)
        result[j] = dest[j];
    for ((*i) =  0; src[*i] != '\0' && src[*i] != '\n'; j++, (*i)++)
        result[j] = src[(*i)];
    (*i)++;
    result[j] = '\0';
    return (result);
}

char *get_lineg(char *str, int fd, int *j)
{
    char *result = malloc(sizeof(char) * READ_SIZE + 1);
    int i = 0;

    if (result == NULL)
        return (NULL);
    i = read(fd, result, READ_SIZE);
    if (i > 0 && i != READ_SIZE)
        result[i] = '\0';
    if (i == -1)
        return (NULL);
    if (i == 0) {
        *j = 0;
        return (str);
    }
    result[READ_SIZE] = '\0';
    for (*j = 0; result[(*j)] != '\n' && result[(*j)] != '\0'; (*j)++);
    return (result);
}

static char *my_rest(char *str, int i)
{
    char *result = malloc(sizeof(char) * my_strleng(str));
    int j = 0;

    if (result == NULL || str == NULL)
        return (NULL);
    for (; str[i] != '\0'; j++, i++)
        result[j] = str[i];
    result[j] = '\0';
    return (result);
}

char *get_next_line(int fd)
{
    char *str = NULL; char *result = NULL;
    static char *rest = NULL;
    int i = 0; int j = 0;
    if (fd == -1 || READ_SIZE <= 0)
        return (NULL);
    if (rest != NULL)
        result = my_strcatg(result, rest, &i);
    if (my_strleng(result) < my_strleng(rest)) {
        rest = my_rest(rest, i);
        return (result);
    }
    str = get_lineg(str, fd, &j);
    for (; j == READ_SIZE; str = get_lineg(str, fd, &j))
        result = my_strcatg(result, str, &i);
    if (READ_SIZE == 1)
        return (result);
    result = my_strcatg(result, str, &i);
    free(rest);
    rest = my_rest(str, i);
    return (result);
}