/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** my_putstr
*/

#include "../../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int a = 0;

    if (str == NULL)
        return (84);
    while (str[a] != '\0') {
        my_putchar(str[a]);
        a += 1;
    }
    return (0);
}