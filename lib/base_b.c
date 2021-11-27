/*
** EPITECH PROJECT, 2021
** B-PSU-100-RUN-1-1-myprintf-apolline.fontaine
** File description:
** display binary flag
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "../include/printf.h"

int get_powerb2(int nb)
{
    int power = 1;
    int result_power = 2;

    while (result_power <= nb) {
        result_power = result_power * 2;
        power++;
    }
    return (power + 1);
}

void binary(int nb)
{
    int i = 0;
    int power = get_powerb2(nb);
    char *str = malloc(sizeof(char) * power);

    while (nb != 0) {
        if (nb % 2 < 2)
            str[i] = (nb % 2) + 48;
        i++;
        nb = nb / 2;
    }
    str[i] = '\0';
    my_putstr(my_revstr(str));
    free(str);
}

void disp_my_binary(va_list stock)
{
    binary(va_arg(stock, int));
}
