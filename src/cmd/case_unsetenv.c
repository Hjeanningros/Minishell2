/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** case_unsetenv
*/

#include "../../include/my.h"

void case_unsetenv(linked_list_t *list_env, info_shell_t *info_shell)
{
    if (my_tab_len(info_shell->tab) == 1) {
        my_puter("unsetenv: Too few arguments.\n");
        return;
    }
    for (int i = 1; info_shell->tab[i] != NULL; i++)
        delete_a_node(list_env, info_shell->tab[i]);
    info_shell->env = linked_list_to_tab(list_env);
}