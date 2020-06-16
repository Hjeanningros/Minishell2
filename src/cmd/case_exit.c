/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** case_exit
*/

#include "../../include/my.h"

void case_exit(linked_list_t *env, info_shell_t *info_shell)
{
    int count = my_tab_len(info_shell->tab);

    if (count == 1) {
        info_shell->exit_value = 0;
        info_shell->status = 0;
        return;
    } else if (count > 2) {
        my_puter("exit: Expression Syntax.\n");
        return;
    }
    for (int i = 0; info_shell->tab[1][i] != '\0'; i++) {
        if (info_shell->tab[1][i] < '0' || info_shell->tab[1][i] > '9') {
            my_puter("exit: Expression Syntax.\n");
            return;
        }
    }
    my_putstr("exit\n");
    info_shell->exit_value = my_getnbr(info_shell->tab[1]);
    exit (info_shell->exit_value % 256);
}