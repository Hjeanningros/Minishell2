/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** linked_list_to_tab
*/

#include "../../include/my.h"

int count_node(linked_list_t *list)
{
    linked_list_t *tmp = list;
    int count = 0;

    while (tmp->next != NULL) {
        tmp = tmp->next;
        count += 1;
    }
    return (count);
}

char **linked_list_to_tab(linked_list_t *lt)
{
    char **tab = malloc(sizeof(char *) * (count_node(lt) + 2));
    linked_list_t *tmp = lt;
    int i = 0;

    if (tab == NULL)
        exit(84);
    for (;tmp != NULL; i++) {
        tab[i] = my_strcat_env(tmp->tab_env[0], tmp->tab_env[1]);
        tmp = tmp->next;
    }
    tab[i] = NULL;
    return (tab);
}