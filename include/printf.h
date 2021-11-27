/*
** EPITECH PROJECT, 2021
** B-PSU-100-RUN-1-1-myprintf-apolline.fontaine
** File description:
** printf.h
*/

#ifndef PRINTF_H_
    #define PRINTF_H_
    #include <stdarg.h>


typedef struct flags {
    char flag;
    void (*function)(va_list stock);
}flags_s;

void display_unsigned(va_list);
void my_hexa_b(unsigned long c);
void my_putchar(int c);
int my_strlen(char *str);
char *my_revstr(char *str);
void disp_my_binary(va_list stock);
void disp_no_printable_char(va_list stock);
void my_putstr(char const *str);
void disp_my_putstr(va_list stock);
void disp_my_putnbr(va_list stock);
void display_my_hexa_B(va_list stock);
void display_my_hexa_b(va_list stock);
void disp_my_octal_b(va_list stock);
void disp_my_putchar(va_list stock);
void disp_my_putcharmod(va_list stock);
int my_printf(const char *format, ...);
void disp_my_flag_pointer(va_list stock);

#endif
