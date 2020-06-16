/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** getline.c
*/

#include "../../include/my.h"

char **get_line(info_shell_t *info_shell)
{
    char *line = NULL;
    size_t len = 0;
    int y = 0;
    char **result = NULL;

    if (getline(&line, &len, stdin) == -1) {
        my_putstr("exit\n");
        exit (0);
    }
    result = my_str_to_word_array_com(line, ';');
    return (result);
}

char *get_line_left(void)
{
    char *line = NULL;
    size_t len = 0;
    int y = 0;

    if (getline(&line, &len, stdin) == -1) {
        return (NULL);
    }
    return (line);
}