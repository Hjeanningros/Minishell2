/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** main.c
*/

#include "../include/my.h"

int case_redir(info_shell_t *info_shell, linked_list_t *list_env)
{
    if (check_redir(info_shell->command) == 1) {
        case_redir_right(info_shell, list_env);
        return (1);
    }
    if (check_redir(info_shell->command) == 2) {
        case_redir_dright(info_shell, list_env);
        return (1);
    }
    if (check_redir(info_shell->command) == 3) {
        case_redir_left(info_shell, list_env);
        return (1);
    }
    if (check_redir(info_shell->command) == 4) {
        case_dredir_left(info_shell, list_env);
        return (1);
    }
    return (0);
}

void test(info_shell_t *info_shell, linked_list_t *list_env)
{
    char *com[] = {"cd", "exit", "env", "setenv", "unsetenv"};
    void (*funct[])(linked_list_t *, info_shell_t *) = {case_cd, case_exit,
        case_env, case_setenv, case_unsetenv};
    for (int i = 0; i < 5; i++) {
        if (my_strcmp(info_shell->tab[0], com[i]) == 0) {
            funct[i](list_env, info_shell);
            return;
        }
    }
    if (case_redir(info_shell, list_env) == 1) {
        return;
    }
    if (check_pipe(info_shell->command) == 1) {
        case_pipe(info_shell, list_env);
        return;
    }
    case_others(info_shell, list_env);
}

void shell_loop(info_shell_t *info_shell, linked_list_t *list_env)
{
    char **result = NULL;
    my_putstr("$> ");
    my_putstr(getcwd(NULL, 100));
    my_putchar(' ');

    result = get_line(info_shell);
    for (int i = 0; result[i] != NULL; i++) {
        info_shell->redir = FALSE;
        info_shell->pipe_redir = FALSE;
        info_shell->tab = my_str_to_word_array(result[i], ' ');
        info_shell->command = result[i];
        test(info_shell, list_env);
    }
}

int main(int argc, char **argv, char **env)
{
    info_shell_t *info_shell = NULL;
    linked_list_t *list_env = NULL;

    if (argc > 1)
        return (84);
    info_shell = malloc(sizeof(info_shell_t));
    if (info_shell == NULL)
        return (84);
    info_shell->status = 1;
    info_shell->env = env;
    list_env = initialisation(info_shell, env);
    while (info_shell->status != 0) {
        shell_loop(info_shell, list_env);
    }
    return (0);
}