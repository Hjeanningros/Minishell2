/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** mathstick
*/

#ifndef MY_MATCHSTICK_H_
#define MY_MATCHSTICK_H_

typedef enum bool_s
{
    FALSE = 0,
    TRUE
} bool_t;

typedef struct info_shell_s {
    char **tab;
    char **env;
    char *command;
    int nbr_pipe;
    int status;
    int exit_value;
    int redir;
    int fd_file;
    int fd[2];
    int result_cmd;
    int pipe_redir;
}info_shell_t;


#endif /* MY_MATCHSTICK_H_ */