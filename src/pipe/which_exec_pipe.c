/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** main.c
*/

#include "../../include/my.h"

int which_pipe(char *cmd, int i, info_shell_t *sh, linked_list_t *list_env)
{
    if (i < sh->nbr_pipe)
        pipe(sh->fd);
    if (i == 0) {
        if (first_exec(cmd, sh, list_env) == 0)
            return (0);
    } else if (i == sh->nbr_pipe) {
        if (last_exec(cmd, sh, list_env) == 0)
            return (0);
    } else {
        if (middle_exec(cmd, sh, list_env) == 0)
            return (0);
    }
}

int first_exec(char *cmd, info_shell_t *sh, linked_list_t *list_env)
{
    pid_t pid = fork();

    sh->tab = my_str_to_word_array(cmd, ' ');
    if (pid == -1)
        perror("fork");
    else if (pid == 0) {
        dup2(sh->fd[1], 1);
        close(sh->fd[0]);
        case_others(sh, list_env);
        exit(0);
    } else {
        close(sh->fd[1]);
        sh->result_cmd = sh->fd[0];
    }
    return (1);
}

int middle_exec(char *cmd, info_shell_t *sh, linked_list_t *list_env)
{
    pid_t pid = fork();

    sh->tab = my_str_to_word_array(cmd, ' ');
    if (pid == -1)
        perror("fork");
    else if (pid == 0) {
        dup2(sh->result_cmd, 0);
        dup2(sh->fd[1], 1);
        close(sh->fd[0]);
        case_others(sh, list_env);
        exit(0);
    } else {
        close(sh->fd[1]);
        close(sh->result_cmd);
        sh->result_cmd = sh->fd[0];
    }
    return (1);
}

int last_exec(char *cmd, info_shell_t *sh, linked_list_t *list_env)
{
    pid_t pid = fork();

    sh->tab = my_str_to_word_array(cmd, ' ');
    if (pid == -1)
        perror("fork");
    else if (pid == 0) {
        if (sh->pipe_redir == TRUE)
            sh->redir = TRUE;
        dup2(sh->fd[0], 0);
        close(sh->result_cmd);
        close(sh->fd[1]);
        case_others(sh, list_env);
        exit(0);
    } else {
        close(sh->fd[0]);
        close(sh->fd[1]);
        close(sh->result_cmd);
    }
    return (1);
}
