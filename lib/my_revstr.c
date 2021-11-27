/*
** EPITECH PROJECT, 2021
** B-PSU-100-RUN-1-1-myprintf-apolline.fontaine
** File description:
** my_revstr.c
*/

#include "../include/printf.h"

void my_swap(char *a, char *b)
{
    char tmp = *a;

    *a = *b;
    *b = tmp;
}

char *my_revstr(char *str)
{
    int end = my_strlen(str) - 1;
    int start = 0;

    while (start < end) {
        my_swap(&str[start], &str[end]);
        start = start + 1;
        end = end - 1;
    }
    return (str);
}
