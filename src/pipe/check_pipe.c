/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** main.c
*/

#include "../../include/my.h"

int check_pipe(char *command)
{
    char **tab = my_str_to_word_array(command, ' ');

    for (int i = 0; tab[i] != NULL; i++)
        if (my_strcmp(tab[i], "|") == 0)
            return (1);
    for (int i = 0; command[i] != '\0'; i++)
        if (command[i] == '|')
            return (1);
    return (0);
}