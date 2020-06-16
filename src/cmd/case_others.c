/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** case_others
*/

#include "../../include/my.h"

int check_slash(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '/')
            return (0);
    }
    return (1);
}

int other_execve(info_shell_t *sh, char *path, linked_list_t *list)
{
    char **tab = my_str_to_word_array(path, ':');

    if (sh->tab[1] != NULL) {
        if (sh->tab[1][0] == '~' && sh->tab[1][1] == '\0')
            sh->tab[1] = get_path(list, "HOME");
    }
    for (int i = 0; tab[i] != NULL; i++) {
        if (sh->redir == TRUE) {
            dup2(sh->fd_file, 1);
        }
        if (execve(my_strcat_path(tab[i], sh->tab[0]), sh->tab, sh->env) == 0) {
            my_putchar ('\n');
            return (1);
        }
    }
    my_puter(sh->tab[0]);
    my_puter(": Command not found.\n");
    return (1);
}

int exec_with_slash(info_shell_t *info, linked_list_t *list)
{
    if (info->tab[1] != NULL) {
        if (info->tab[1][0] == '~' && info->tab[1][1] == '\0')
            info->tab[1] = get_path(list, "HOME");
    }
    if (execve(info->tab[0], info->tab, info->env) == -1)
        my_puter(info->tab[0]);
        my_puter(": Permission denied.\n");
}

void case_others(info_shell_t *info, linked_list_t *list)
{
    pid_t pid = fork();
    int ret = 0;

    if (pid == -1)
        perror("fork");
    else if (pid == 0) {
        if (check_slash(info->tab[0]) == 0)
            exec_with_slash (info, list);
        else {
            if (get_path(list, "PATH") == NULL) {
                my_puter(info->tab[0]);
                my_puter(": Command not found.\n");
            } else
                other_execve(info, get_path(list, "PATH"), list);
        }
        exit (0);
    } else
        my_wait(&pid);
}