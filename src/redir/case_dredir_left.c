/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** mathstick
*/

#include "../../include/my.h"

void add_bn_at_end(char *str)
{
    str[my_strlen(str)] = '\n';
    str[my_strlen(str) + 1] = '\0';
}

int exec_with_text(info_shell_t *sh, linked_list_t *list_env, char *text)
{
    pid_t pid = fork();
    int ret;
    int tmp[2];

    pipe(tmp);
    my_putstr_redir(text, tmp);
    if (pid == -1)
        perror("fork");
    else if (pid == 0) {
        dup2(tmp[0], 0);
        close(tmp[1]);
        case_others(sh, list_env);
        exit (0);
    } else {
        close(tmp[0]);
        close(tmp[1]);
        my_wait(&pid);
    }
}

int check_error_dleft(info_shell_t *sh, char *fp, char ** tab)
{
    if (my_strcmp(fp, "no command") == 0) {
        my_putstr("Invalid null command.\n");
        return (0);
    }
    sh->tab = my_str_to_word_array(tab[0], ' ');
    if (fp == NULL) {
        my_puter("Missing name for redirect.\n");
        return (0);
    }
    return (1);
}

int case_dredir_left(info_shell_t *sh, linked_list_t *list_env)
{
    char **tab = my_str_to_word_array(sh->command, '<');
    char *fp = search_fp(sh->command, '<');
    char *text = NULL;
    char *str;

    if (check_error_dleft(sh, fp, tab) == 0)
        return (0);
    if ((str = get_next_line(0)) == NULL)
        return (0);
    while (my_strcmp(fp, str) != 0) {
        if (text == NULL)
            text = str;
        else
            text = my_strcat_bn(text, str);
        if ((str = get_next_line(0)) == NULL)
            return (0);
    }
    add_bn_at_end(text);
    exec_with_text(sh, list_env, text);
    return (1);
}