/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** add_node_at_end
*/

#include "../../include/my.h"

int error_setenv(info_shell_t *info)
{
    if (my_tab_len(info->tab) > 3) {
        my_puter("setenv: Too many arguments.\n");
        return (1);
    }
    return (0);
}

void fill_node(linked_list_t *to_add, info_shell_t *info)
{
    to_add->tab_env = malloc(sizeof(char *) * 3);
    if (to_add->tab_env == NULL)
        exit (84);
    to_add->tab_env[0] = malloc(sizeof(char) * my_strlen(info->tab[1]) + 1);
    if (to_add->tab_env[0] == NULL)
        exit(84);
    to_add->tab_env[1] = malloc(sizeof(char) * my_strlen(info->tab[2]) + 1);
    if (to_add->tab_env[1] == NULL)
        exit(84);
    to_add->tab_env[0] = info->tab[1];
    to_add->tab_env[1] = info->tab[2];
    to_add->tab_env[2] = NULL;
}

int check_actual_node(linked_list_t *hd, info_shell_t *info)
{
    while (hd != NULL) {
        if (my_strcmp(hd->tab_env[0], info->tab[1]) == 0) {
            hd->tab_env[1] = malloc(sizeof(char) * my_strlen(info->tab[2]) + 1);
            if (hd->tab_env[1] == NULL)
                exit(84);
            hd->tab_env[1] = info->tab[2];
            return (1);
        }
        hd = hd->next;
    }
    return (0);
}

void add_node_at_end(linked_list_t *list, info_shell_t *info)
{
    linked_list_t *head = list;
    linked_list_t *to_add = malloc(sizeof(linked_list_t));

    if (to_add == NULL)
        exit(84);
    if (error_setenv(info) == 1)
        return;
    if (check_actual_node(head, info) == 1)
        return;
    head = list;
    fill_node(to_add, info);
    while (head->next != NULL)
        head = head->next;
    head->next = to_add;
    to_add->next = NULL;
}