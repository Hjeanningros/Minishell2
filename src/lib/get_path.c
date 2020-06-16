/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** get_path
*/

#include "../../include/my.h"

char *get_path(linked_list_t *list, char *str)
{
    linked_list_t *head = list;

    while (head != NULL) {
        if (my_strcmp(head->tab_env[0], str) == 0)
            return (head->tab_env[1]);
        head = head->next;
    }
    return (NULL);
}