/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** case_redir
*/

#include "../../include/my.h"

char *search_fp(char *str, char carac)
{
    int i = 0;
    char *fp = malloc(sizeof(char) * my_strlen(str));
    int y = 0;
    char **tab;

    for (; str[i] != '\0' && str[i] != carac; i++);
    i++;
    if (str[i] == '\0')
        return ("no command");
    if (str[i] == carac) {
        i += 1;
        if (str[i] == '\0')
            return ("no command");
    }
    for (; str[i] != '\0'; i++, y++)
        fp[y] = str[i];
    fp[y] = '\0';
    tab = my_str_to_word_array(fp, ' ');
    free(fp);
    return (tab[0]);
}

int check_error_right(info_shell_t *sh, char *fp)
{
    if (fp == NULL) {
        my_puter("Missing name for redirect.\n");
        return (0);
    }
    if ((sh->fd_file = open(fp, O_WRONLY | O_CREAT | O_TRUNC,
                    S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH
                    | S_IWOTH)) == -1) {
        my_puter("Error while opening");
        my_puter(fp);
        my_puter(".\n");
        return (0);
    }
    return (1);
}

int case_redir_right(info_shell_t *sh, linked_list_t *list_env)
{
    char **tab = my_str_to_word_array(sh->command, '>');
    char *fp = search_fp(sh->command, '>');
    if (my_strcmp(fp, "no command") == 0) {
        my_putstr("Invalid null command.\n");
        return (0);
    } else {
        sh->tab = my_str_to_word_array(tab[0], ' ');
        sh->redir = TRUE;
        if (check_error_right(sh, fp) == 0)
            return (0);
        if (check_pipe(sh->command) == 1) {
            sh->pipe_redir = TRUE;
            sh->redir = FALSE;
            sh->command = tab[0];
            case_pipe(sh, list_env);
        } else
            case_others(sh, list_env);
    }
    close(sh->fd_file);
    return (1);
}
