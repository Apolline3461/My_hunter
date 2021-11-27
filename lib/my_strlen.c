/*
** EPITECH PROJECT, 2021
** B-PSU-100-RUN-1-1-myprintf-apolline.fontaine
** File description:
** my_strlen.c
*/

#include "../include/printf.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i = i + 1;
    return (i);
}
