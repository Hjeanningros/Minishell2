/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** my_getnbr
*/

#include "../../include/my.h"

int my_error(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
        i += 1;
    }
    return (i);
}

int my_getnbr(char const *str)
{
    int i = 0;
    long j = 0;
    int jf;
    int neg = 1;

    while ((str[i] == '+' || str[i] == '-') && str[i] != '\0') {
        if (str[i] == '-')
            neg *= -1;
        i += 1;
    }
    for (;str[i] != '\0' && str[i] >= '0' && str[i] <= '9'; i += 1)
        j = ((j * 10) + (str[i] - 48));
    if (my_error(str) > 10 )
        return (0);
    if (j > 2147483648)
        return (0);
    else {
        jf = j;
        return (jf * neg);
    }
}