/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** mathstick
*/

#include "../../include/my.h"

void change_fd (info_shell_t *sh, linked_list_t *env)
{
    pid_t pid = fork();
    int ret;

    if (pid == -1)
        perror("fork");
    else if (pid == 0) {
        dup2(sh->fd_file, 0);
        case_others(sh, env);
        exit (0);
    } else
        my_wait(&pid);
}

int check_error_left(info_shell_t *sh, char *fp)
{
    if (fp == NULL) {
        my_puter("Missing name for redirect.\n");
        return (0);
    }
    if ((sh->fd_file = open(fp, O_RDONLY)) == -1) {
        my_puter("Error while opening");
        my_puter(fp);
        my_puter(".\n");
        return (0);
    }
    return (1);
}

int case_redir_left(info_shell_t *sh, linked_list_t *list_env)
{
    char **tab = my_str_to_word_array(sh->command, '<');
    char *fp = search_fp(sh->command, '<');

    if (my_strcmp(fp, "no command") == 0) {
        my_putstr("Invalid null command.\n");
        return (0);
    }
    sh->tab = my_str_to_word_array(tab[0], ' ');
    sh->redir = TRUE;
    if (check_error_left(sh, fp) == 0)
        return (0);
    else
        change_fd(sh, list_env);
    close(sh->fd_file);
    return (1);
}