/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** my_strcmp
*/

#include "../../include/my.h"

int	my_strcmp(char *s1, char *s2)
{
    int i = 0;

    for (; s1[i] == s2[i] && s1[i] != '\0'; i++);
    if (s1[i] == '\0' && s2[i] == '\0')
        return (0);
    else
        return (1);
}
