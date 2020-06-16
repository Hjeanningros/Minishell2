/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** my_strcat
*/

#include "../../include/my.h"

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    char *result = malloc(sizeof(char) * my_strlen(dest) + my_strlen(src) + 3);

    if (dest == NULL || result == NULL || src == NULL)
        return (NULL);
    for (; dest[i] != '\0'; i++)
        result[i] = dest[i];
    for (int y = 0; src[y] != '\0'; y++, i++)
        result[i] = src[y];
    result[i] = '\0';
    return (result);
}

char *my_strcat_bn(char *dest, char *src)
{
    int i = 0;
    char *result = malloc(sizeof(char) * my_strlen(dest) + my_strlen(src) + 3);

    if (dest == NULL || result == NULL || src == NULL)
        return (NULL);
    for (; dest[i] != '\0'; i++)
        result[i] = dest[i];
    result[i] = '\n';
    i++;
    for (int y = 0; src[y] != '\0'; y++, i++)
        result[i] = src[y];
    result[i] = '\0';
    return (result);
}

char *my_strcat_env(char *dest, char *src)
{
    int i = 0;
    char *result = malloc(sizeof(char) * my_strlen(dest) + my_strlen(src) + 3);
    if (dest == NULL || result == NULL)
        return (NULL);
    if (src == NULL) {
        for (; dest[i] != '\0'; i++)
            result[i] = dest[i];
        result[i] = '=';
        return (result);
    }
    else {
        for (; dest[i] != '\0'; i++)
            result[i] = dest[i];
        result[i] = '=';
        i++;
        for (int y = 0; src[y] != '\0'; y++, i++)
            result[i] = src[y];
        result[i] = '\0';
        return (result);
    }
}

char *my_strcat_path(char *dest, char *src)
{
    int i = 0;
    char *result = malloc(sizeof(char) * my_strlen(dest) + my_strlen(src) + 3);
    if (dest == NULL || result == NULL)
        return (NULL);
    if (src == NULL) {
        for (; dest[i] != '\0'; i++)
            result[i] = dest[i];
        result[i] = '/';
        return (result);
    }
    else {
        for (; dest[i] != '\0'; i++)
            result[i] = dest[i];
        result[i] = '/';
        i++;
        for (int y = 0; src[y] != '\0'; y++, i++)
            result[i] = src[y];
        result[i] = '\0';
        return (result);
    }
}