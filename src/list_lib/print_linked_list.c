/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** print_linked_list
*/

#include "../../include/my.h"

void print_linked_list_revers(linked_list_t *head)
{
    if (head == NULL)
        return;
    print_linked_list_revers(head->next);
    my_putstr(head->tab_env[0]);
    my_putchar('=');
    my_putstr(head->tab_env[1]);
    my_putchar('\n');
}

void print_linked_list(linked_list_t *list, info_shell_t *shell)
{
    linked_list_t *current_node = list;

    while (current_node != NULL) {
        my_putstr(current_node->tab_env[0]);
        my_putchar('=');
        my_putstr(current_node->tab_env[1]);
        my_putchar('\n');
        current_node = current_node->next;
    }
}