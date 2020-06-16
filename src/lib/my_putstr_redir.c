/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** mathstick
*/

#include "../../include/my.h"

void my_putchar_redir(char c, int *tmp)
{
    write(tmp[1], &c, 1);
}

int my_putstr_redir(char const *str, int *tmp)
{
    int a = 0;

    if (str == NULL)
        return (84);
    while (str[a] != '\0') {
        my_putchar_redir(str[a], tmp);
        a += 1;
    }
    return (0);
}