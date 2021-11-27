/*
** EPITECH PROJECT, 2021
** B-PSU-100-RUN-1-1-myprintf-apolline.fontaine
** File description:
** my_printf.c
*/

#include <stdarg.h>
#include <stdio.h>
#include "../include/printf.h"

flags_s FLAGS_LIST[] = {
    {'u', &display_unsigned},
    {'b', &disp_my_binary},
    {'S', &disp_no_printable_char},
    {'d', &disp_my_putnbr},
    {'i', &disp_my_putnbr},
    {'x', &display_my_hexa_b},
    {'s', &disp_my_putstr},
    {'X', &display_my_hexa_B},
    {'c', &disp_my_putchar},
    {'C', &disp_my_putchar},
    {'o', &disp_my_octal_b},
    {'%', &disp_my_putcharmod},
    {'p', &disp_my_flag_pointer},
    {'\0', NULL}
};

void check_flags(const char *format, int *i, va_list stock_var_disp)
{
    for (int f = 0; FLAGS_LIST[f].flag != '\0'; f++) {
        if (FLAGS_LIST[f].flag == format[*i + 1])
            FLAGS_LIST[f].function(stock_var_disp);
    }
    (*i)++;
}

int my_printf(const char *format, ...)
{
    int nb_display = 0;
    va_list stock_var_disp;
    va_start(stock_var_disp, format);

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            check_flags(format, &i, stock_var_disp);
            continue;
        }
        my_putchar(format[i]);
    }
    va_end(stock_var_disp);
    return nb_display;
}
