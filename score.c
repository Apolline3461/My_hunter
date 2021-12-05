/*
** EPITECH PROJECT, 2021
** B-MUL-100-RUN-1-1-myhunter-apolline.fontaine
** File description:
** score.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "./include/printf.h"

int count_score(int score)
{
    score += 5;
    return score;
}

int len_of_int(int nb_score)
{
    int len;

    if (nb_score == 0)
        return 1;
    for (len = 0; nb_score > 0; len++)
        nb_score = nb_score / 10;
    return len;
}

char *int_to_string(int score)
{
    int i = 0;
    int len = len_of_int(score) + 1;
    char *str = malloc(sizeof(char) * len);

    for (; i < len - 1; i++) {
        str[i] = score % 10 + 48;
        score = score / 10;
    }
    str[i] = '\0';
    my_revstr(str);
    return str;
}

// afficher cadre pour mettre le score
// afficher compteur
