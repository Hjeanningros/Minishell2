/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** main.c
*/

#include "../../include/my.h"

int case_pipe(info_shell_t *sh, linked_list_t *list_env)
{
    char **tab = my_str_to_word_array(sh->command, '|');
    int ret;

    if (my_strcmp(sh->tab[0], "|") == 0) {
        my_putstr("Invalid null command.\n");
    }
    sh->nbr_pipe = my_tab_len(tab) - 1;

    for (int i = 0; tab[i] != NULL; i++) {
        which_pipe(tab[i], i, sh, list_env);
    }
    for (int i = 0; tab[i] != NULL; i++) {
        wait(&ret);
    }
}