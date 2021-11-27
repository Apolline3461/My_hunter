/*
** EPITECH PROJECT, 2021
** B-PSU-100-RUN-1-1-myprintf-apolline.fontaine
** File description:
** display in hexa base
*/

#include <stdlib.h>
#include "../include/printf.h"

unsigned long get_power_hexa(unsigned long nb)
{
    unsigned long power = 1;
    unsigned long result = 16;

    while (result <= nb) {
        result = result * 16;
        power++;
    }
    return power + 1;
}

void my_hexa_B(unsigned long nb)
{
    unsigned long i = 0;
    unsigned long tmp = 0;
    unsigned long power = get_power_hexa(nb);
    char *str = malloc(sizeof(char) * power);

    while (nb != 0) {
        tmp = nb % 16;
        if (tmp < 10)
            str[i] = tmp + 48;
        else
            str[i] = tmp + 55;
        nb = nb / 16;
        i++;
    }
    str[i] = '\0';
    my_putstr(my_revstr(str));
    free(str);
}

void display_my_hexa_B(va_list stock)
{
    unsigned long nb = va_arg(stock, unsigned long);

    my_hexa_B(nb);
}

void my_hexa_b(unsigned long nb)
{
    unsigned long i = 0;
    unsigned long tmp = 0;
    unsigned long power = get_power_hexa(nb);
    char *str = malloc(sizeof(char) * power);

    while (nb != 0) {
        tmp = nb % 16;
        if (tmp < 10)
            str[i] = tmp + 48;
        else
            str[i] = tmp + 87;
        nb = nb / 16;
        i++;
    }
    str[i] = '\0';
    my_putstr(my_revstr(str));
    free(str);
}

void display_my_hexa_b(va_list stock)
{
    unsigned long nb = va_arg(stock, unsigned long);

    my_hexa_b(nb);
}
