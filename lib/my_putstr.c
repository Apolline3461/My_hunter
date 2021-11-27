/*
** EPITECH PROJECT, 2021
** B-PSU-100-RUN-1-1-myprintf-apolline.fontaine
** File description:
** my_putstr.c
*/

#include <stdarg.h>
#include "../include/printf.h"

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}

void disp_my_putstr(va_list stock)
{
    my_putstr(va_arg(stock, char *));
}
