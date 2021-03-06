/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** my_str_to_word_array
*/

#include "../../include/my.h"

int count_words_com(char *str, char separator)
{
    int i = 0;
    int a = 0;
    int words = 0;

    while (str[i]) {
        if ((str[i] != separator) && a == 0) {
            words += 1;
            a = 1;
        } else if (str[i] == separator)
            a = 0;
        i++;
    }
    return (words);
}

char *count_letters_com(int *letters, char *s, char sep)
{
    int i = 0;
    int j = 0;
    char *word;
    *letters = 0;
    while (s[i] == sep)
        i++;
    while ((s[i] != sep) && s[i] != '\0') {
        i += 1;
        *letters += 1;
    }
    *letters = i;
    word = malloc(sizeof(char) * (*letters + 2));
    if (word == NULL)
        return (NULL);
    for (j; s[j] == sep; j++);
    for (i = j; (s[i] != sep && s[i] != '\n')
        && s[i] != '\0'; i++)
        word[i - j] = s[i];
    word[i - j] = '\0';
    return (word);
}

char **my_str_to_word_array_com(char *str, char separator)
{
    int words = 0;
    char *word = NULL; char **word_array = NULL;
    int letters = 0; int i = 0;
    if (!str || !str[0])
        return (NULL);
    words = count_words_com(str, separator);
    word_array = malloc(sizeof(char *) * (words + 2));
    for (i = 0; i < words; i++) {
        word = count_letters_com(&letters, str, separator);
        str += letters;
        word_array[i] = word;
    }
    for (int y = 0; word_array[i - 1][y] != '\0'; y++) {
        if (word_array[i - 1][y] != ' ') {
            word_array[i] = NULL;
            return (word_array);
        }
    }
    word_array[i - 1] = NULL;
    return (word_array);
}