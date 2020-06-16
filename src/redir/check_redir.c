/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** mathstick
*/

#include "../../include/my.h"

int sec_redir(char *command)
{
    for (int i = 0; command[i] != '\0'; i++) {
        if (command[i] == '>' && command[i + 1] == '>')
            return (2);
        if (command[i] == '>')
            return (1);
        if (command[i] == '<' && command[i + 1] == '<')
            return (4);
        if (command[i] == '<')
            return (3);
    }
    return (0);
}

int check_redir(char *command)
{
    char **tab = my_str_to_word_array(command, ' ');
    int index = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        if (my_strcmp(tab[i], ">") == 0)
            return (1);
        if (my_strcmp(tab[i], ">>") == 0)
            return (2);
        if (my_strcmp(tab[i], "<") == 0)
            return (3);
        if (my_strcmp(tab[i], "<<") == 0)
            return (4);
    }
    index = sec_redir(command);
    if (index != 0)
        return (index);
    return (0);
}