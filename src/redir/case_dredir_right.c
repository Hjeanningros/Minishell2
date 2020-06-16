/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** case_dredir
*/

#include "../../include/my.h"

void read_to_eof(int fd, char *fp)
{
    int ret;
    char *buff = NULL;
    struct stat st;
    ret = fstat(fd, &st);
    buff = malloc(sizeof(char) * st.st_size + 1);
    read(fd, buff, st.st_size);
}

int check_error_dright(info_shell_t *sh, char *fp)
{
    if (fp == NULL) {
        my_puter("Missing name for redirect.\n");
        return (0);
    }
    if ((sh->fd_file = open(fp, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR
                   | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)) == -1) {
        my_puter("Error while opening");
        my_puter(fp);
        my_puter(".\n");
        return (0);
    }
    return (1);
}

int case_redir_dright(info_shell_t *sh, linked_list_t *list_env)
{
    char **tab = my_str_to_word_array(sh->command, '>');
    char *fp = search_fp(sh->command, '>');
    if (my_strcmp(fp, "no command") == 0) {
        my_putstr("Invalid null command.\n");
        return (0);
    }
    sh->tab = my_str_to_word_array(tab[0], ' ');
    sh->redir = TRUE;
    if (check_error_dright(sh, fp) == 0)
        return (0);
    read_to_eof(sh->fd_file, fp);
    if (check_pipe(sh->command) == 1) {
        sh->pipe_redir = TRUE;
        sh->redir = FALSE;
        sh->command = tab[0];
        case_pipe(sh, list_env);
    } else
        case_others(sh, list_env);
    close(sh->fd_file);
    return (1);
}