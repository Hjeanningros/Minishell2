/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** init linked_list
*/

#include "../../include/my.h"

int size_env(char **env)
{
    int count = 0;

    for (; env[count] != NULL; count++);
    return (count);
}

char *fill_first_part(char *env)
{
    int mall = 0;
    int fill = 0;
    char *result;

    for (int i = 0; env[i] != '='; i++, mall++);
    result = malloc(sizeof(char) * mall + 2);
    if (result == NULL)
        exit(84);
    for (; env[fill] != '='; fill++)
        result[fill] = env[fill];
    result[fill] = '\0';
    return (result);
}

char *fill_seconde_part(char *env)
{
    int mall = 0;
    char *result;
    int i = 0;
    int fill = 0;

    for (; env[i] != '='; i++, mall++);
    i++;
    result = malloc(sizeof(char) * (my_strlen(env) - (mall + 1) + 1));
    if (result == NULL)
        exit(84);
    for (; env[i] != '\0'; i++, fill++)
        result[fill] = env[i];
    result[fill] = '\0';
    return (result);
}

linked_list_t *initialisation(info_shell_t *info, char **env)
{
    linked_list_t *element;
    linked_list_t *list = NULL;
    int i = 0;
    int fill = 0;
    int loop = size_env(env) - 1;

    for (; loop >= 0; loop--) {
        element = malloc(sizeof(linked_list_t));
        if (element == NULL)
            exit(84);
        element->tab_env = malloc(sizeof(char *) * 3);
        if (element->tab_env == NULL)
            exit(84);
        element->tab_env[0] = fill_first_part(env[loop]);
        element->tab_env[1] = fill_seconde_part(env[loop]);
        element->tab_env[2] = NULL;
        element->next = list;
        list = element;
    }
    return (list);
}
