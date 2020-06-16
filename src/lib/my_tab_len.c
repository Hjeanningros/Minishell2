/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** my_tablen
*/

#include "../../include/my.h"

int my_tab_len(char **tab)
{
    int count = 0;

    for (;tab[count] != NULL; count++);
    return (count);
}