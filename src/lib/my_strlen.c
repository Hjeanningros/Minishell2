/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** my_strlen
*/

#include "../../include/my.h"

int my_strlen(char *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    while (str[i] != '\0') {
        i += 1;
    }
    return (i);
}