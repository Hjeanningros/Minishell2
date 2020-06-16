/*
** EPITECH PROJECT, 2019
** my_list
** File description:
** proto
*/

#include "info.h"
#ifndef MYLIST_H_
#define MYLIST_H_

typedef struct linked_list {
    char **tab_env;
    struct linked_list *next;
}   linked_list_t;

#endif