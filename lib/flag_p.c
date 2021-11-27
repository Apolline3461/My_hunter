/*
** EPITECH PROJECT, 2021
** B-PSU-100-RUN-1-1-myprintf-apolline.fontaine
** File description:
** display address
*/

#include <stdlib.h>
#include "../include/printf.h"

void my_flag_pointer(unsigned long nb)
{
    unsigned long c = nb;
    my_putstr("0x");
    my_hexa_b(c);
}

void disp_my_flag_pointer(va_list stock)
{
    my_flag_pointer(va_arg(stock, unsigned long));
}
