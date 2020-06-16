/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** case_setenv
*/

#include "../../include/my.h"

int check_variable(char *str)
{
    if ((str[0] < 'a' || str[0] > 'z') && (str[0] < 'A' || str[0] > 'Z')) {
        my_puter("setenv: Variable name must begin with a letter.\n");
        return (-1);
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') &&
            (str[i] < '0' || str[i] > '9')) {
            my_puter("setenv: Variable name must contain ");
            my_puter("alphanumeric characters.\n");
            return (-1);
        }
    }
    return (0);
}

void case_setenv(linked_list_t *list_env, info_shell_t *info_shell)
{
    if (my_tab_len(info_shell->tab) == 1) {
        print_linked_list(list_env, info_shell);
        return;
    }
    if (check_variable(info_shell->tab[1]) == -1)
        return;
    add_node_at_end(list_env, info_shell);
    info_shell->env = linked_list_to_tab(list_env);
}