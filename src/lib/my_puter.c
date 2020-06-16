/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** my_puter
*/

#include "../../include/my.h"

void my_putcharer(char c)
{
    write(2, &c, 1);
}

int my_puter(char *str)
{
    int a = 0;

    if (str == NULL)
        return (84);
    while (str[a] != '\0') {
        my_putcharer(str[a]);
        a += 1;
    }
    return (0);
}