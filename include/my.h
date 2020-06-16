/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** my.h
*/

#include "list.h"
#include "info.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include<stddef.h>
#include <stdarg.h>
#include <dirent.h>
#include <time.h>


//lib
int my_putstr(char const *);
void my_putchar(char);
int my_strlen(char *);
char *my_strcat(char *, char *);
int my_strcmp(char *, char *);
char **my_str_to_word_array(char *, char);
int my_getnbr(char const *);
int my_tab_len(char **);
char *my_strcat_env(char *, char *);
char *my_strcat_path(char *, char *);
int my_puter(char *);
char **get_line(info_shell_t *);
char *get_path(linked_list_t *, char *);
void my_wait(pid_t *);
char *get_line_left();
char *get_next_line(int);
char *my_strcat_bn(char *, char *);
int my_putstr_redir(char const *, int *);
char **my_str_to_word_array_com(char *str, char separator);

//cmd
void case_cd(linked_list_t *, info_shell_t *);
void cd_error(info_shell_t *);
void change_pwd(linked_list_t *, info_shell_t *);
void case_unsetenv(linked_list_t *, info_shell_t *);
void case_setenv(linked_list_t *, info_shell_t *);
void case_env(linked_list_t *, info_shell_t *);
void case_exit(linked_list_t *, info_shell_t *);
int check_slash(char *);
int other_execve(info_shell_t *, char *, linked_list_t *);
void case_others(info_shell_t *, linked_list_t *);

//linked list lib
void add_node_at_end(linked_list_t *, info_shell_t *);
void delete_a_node(linked_list_t *, char *);
int count_node(linked_list_t *);
char **linked_list_to_tab(linked_list_t *);
linked_list_t *initialisation(info_shell_t *, char **);
void print_linked_list_revers(linked_list_t *);
void print_linked_list(linked_list_t *, info_shell_t *);

//redir
int check_redir(char *);
int case_redir_dright(info_shell_t *, linked_list_t *);
char *search_fp(char *, char);
int case_redir_left(info_shell_t *, linked_list_t *);
int case_redir_right(info_shell_t *, linked_list_t *);
int case_dredir_left(info_shell_t *, linked_list_t *);

//pipe
int check_pipe(char *);
int case_pipe(info_shell_t *, linked_list_t *);
int first_exec(char *, info_shell_t *, linked_list_t *);
int middle_exec(char *, info_shell_t *, linked_list_t *);
int last_exec(char *, info_shell_t *, linked_list_t *);
int which_pipe(char *, int, info_shell_t *, linked_list_t *);