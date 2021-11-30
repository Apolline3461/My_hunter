/*
** EPITECH PROJECT, 2021
** B-MUL-100-RUN-1-1-myhunter-apolline.fontaine
** File description:
** score.c
*/

#include "./include/printf.h"

int count_score(int score)
{
    score += 5;
    return score;
}


// chaque fois qu'on touche un canard + 5
// fin du jeu avec un score total de 30

// afficher cadre pour mettre le score
// afficher compteur

// arrêter jeu: mettre filtre sur image et faire appaître un message gagner
// si au bout de 3min score != 30 perdu