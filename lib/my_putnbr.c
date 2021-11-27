/*
** EPITECH PROJECT, 2021
** B-PSU-100-RUN-1-1-myprintf-apolline.fontaine
** File description:
** my_putnbr.c
*/

#include <stdarg.h>
#include "../include/printf.h"

int find_the_divisor(int nb)
{
    int i = 1;

    if (nb < 0) {
        nb *= -1;
    }
    while (nb > 0) {
        nb = nb / 10;
        i = i * 10;
    }
    return (i / 10);
}

void my_putnbr(int nb)
{
    int div = 0;
    int number_tmp = 0;

    if (nb == 0)
        my_putchar(48);
    if (nb < 0) {
        nb *= -1;
        my_putchar(45);
    }
    div = find_the_divisor(nb);
    while (div >= 1){
        number_tmp = (nb / div) % 10;
        my_putchar(48 + number_tmp);
        div /= 10;
    }
}

void disp_my_putnbr(va_list stock)
{
    my_putnbr(va_arg(stock, int));
}
