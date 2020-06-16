/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** case_cd
*/

#include "../../include/my.h"

void cd_error(info_shell_t *info_shell)
{
    if (errno == ENOTDIR) {
        my_puter(info_shell->tab[1]);
        my_puter(": Not a directory.\n");
    }
    if (errno == ENOENT) {
        my_puter(info_shell->tab[1]);
        my_puter(": No such file or directory.\n");
    }
    if (errno == EACCES) {
        my_puter(info_shell->tab[1]);
        my_puter(": Permission denied.\n");
    }
}

int special_case_cd(linked_list_t *list, info_shell_t *shell, int count)
{
    if (count == 1 || shell->tab[1][0] == '~' && shell->tab[1][1] == '\0') {
        chdir(get_path(list, "HOME"));
        change_pwd(list, shell);
        return (1);
    } else if (shell->tab[1][0] == '-' && shell->tab[1][1] == '\0') {
        if (chdir(get_path(list, "OLDPWD")) == -1)
            my_puter(": No such file or directory.\n");
        change_pwd(list, shell);
        return (1);
    }
    return (0);
}

void case_cd(linked_list_t *info, info_shell_t *info_shell)
{
    int count = 0;
    int status = 0;

    for (; info_shell->tab[count] != NULL; count++);
    if (count > 2) {
        my_puter("cd: Too many arguments.\n");
        return;
    } else if (special_case_cd(info, info_shell, count) == 1)
        return;
    status = chdir(info_shell->tab[1]);
    if (status == -1)
        cd_error(info_shell);
    else if (status == 0) {
            change_pwd(info, info_shell);
    }
}

void change_pwd(linked_list_t *info, info_shell_t *info_shell)
{
    info_shell->tab[1] = "OLDPWD";
    info_shell->tab[2] = get_path(info, "PWD");
    info_shell->tab[3] = NULL;
    add_node_at_end(info, info_shell);
    info_shell->tab[1] = "PWD";
    info_shell->tab[2] = getcwd(NULL, 100);
    info_shell->tab[3] = NULL;
    add_node_at_end(info, info_shell);
}
