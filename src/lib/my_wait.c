/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** my_wait
*/

#include "../../include/my.h"

void my_wait(pid_t *pid)
{
    int status;
    pid_t w = waitpid(*pid, &status, WUNTRACED);

    if (WIFSIGNALED(status) != 0) {
        if (WTERMSIG(status) == 8 && WCOREDUMP(status) == 0)
            my_puter("Floating exception\n");
        else if (WTERMSIG(status) != 8 && WCOREDUMP(status) != 0)
            my_puter("Floating exception (core dumped)\n");
        if (WTERMSIG(status) == 11 && WCOREDUMP(status) == 0)
            my_puter("Segmentation fault\n");
        else if (WTERMSIG(status) != 11 && WCOREDUMP(status) != 0)
            my_puter("Segmentation fault (core dumped)\n");
    }
    if (WIFSTOPPED(status) != 0)
        if (WSTOPSIG(status) != 0)
            my_puter(strsignal(WSTOPSIG(status)));
}