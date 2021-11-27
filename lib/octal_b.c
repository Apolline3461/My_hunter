/*
** EPITECH PROJECT, 2021
** B-PSU-100-RUN-1-1-myprintf-apolline.fontaine
** File description:
** octal_b.c
*/

#include <stdlib.h>
#include <stdarg.h>
#include "../include/printf.h"

int get_power_b8(unsigned long nb)
{
    unsigned long power = 1;
    unsigned long result = 8;

    while (result <= nb) {
        result = result * 8;
        power++;
    }
    return (power + 1);
}

void my_octal_b(unsigned long nb)
{
    unsigned long i = 0;
    unsigned long power = get_power_b8(nb);
    char *str = malloc(sizeof(char) * power);

    while (nb != 0) {
        if (nb % 8 < 8)
            str[i] = (nb % 8) + 48;
        i++;
        nb = nb / 8;
    }
    str[i] = '\0';
    my_putstr(my_revstr(str));
    free(str);
}

void no_printable_char(char *str)
{
    for (unsigned long i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] == 127) {
            my_putchar('\\');
            my_octal_b((unsigned long)str[i]);
        }
        my_putchar(str[i]);
    }
}

void disp_no_printable_char(va_list stock)
{
    no_printable_char(va_arg(stock, char *));
}

void disp_my_octal_b(va_list stock)
{
    my_octal_b(va_arg(stock, unsigned long));
}
