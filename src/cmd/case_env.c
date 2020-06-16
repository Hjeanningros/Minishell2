/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** case_env
*/

#include "../../include/my.h"

void case_env(linked_list_t *list_env, info_shell_t *info_shell)
{
    if (my_tab_len(info_shell->tab) > 1) {
        my_puter("env: '");
        my_puter(info_shell->tab[1]);
        my_puter("': No such file or directory\n");
        return;
    }
    print_linked_list(list_env, info_shell);
}