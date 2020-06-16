/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** delete_node
*/

#include "../../include/my.h"

void delete_a_node(linked_list_t *list, char *str)
{
    linked_list_t *tmp = list;

    while (tmp->next != NULL) {
        if (my_strcmp(tmp->next->tab_env[0], str) == 0) {
            tmp->next = tmp->next->next;
            return;
        }
        tmp = tmp->next;
    }
}