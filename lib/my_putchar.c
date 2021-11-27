/*
** EPITECH PROJECT, 2021
** B-PSU-100-RUN-1-1-myprintf-apolline.fontaine
** File description:
** my_putchar.c
*/

#include <stdarg.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include "../include/printf.h"

void my_putchar(int c)
{
    write(1, &c, 1);
}

void disp_my_putchar(va_list stock)
{
    my_putchar(va_arg(stock, int));
}

void disp_my_putcharmod(va_list stock)
{
    (void)stock;
    my_putchar('%');
}
