/*
** EPITECH PROJECT, 2021
** B-MUL-100-RUN-1-1-myhunter-apolline.fontaine
** File description:
** game_loop.c
*/

#include <stdlib.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include "./include/hunter.h"

void game_loop(duck_t *duck, opt_t *option)
{
    analyse_events(option, duck);
    display_backgr(option);
    display_duck(duck, option);
    char *score = int_to_string(duck->score);
    sfText_setString(option->score, score);
    sfRenderWindow_drawText(option->window, option->score, NULL);
    free(score);
    sfRenderWindow_display(option->window);
}

void end_loop(opt_t *opt)
{
    sfText_setPosition(opt->score, (sfVector2f){380, 300});
    sfText_setCharacterSize(opt->score, 40);
    while (sfRenderWindow_pollEvent(opt->window, &opt->event)) {
        if (opt->event.type == sfEvtClosed)
            sfRenderWindow_close(opt->window);
        if (opt->event.type == sfEvtKeyPressed)
            sfRenderWindow_close(opt->window);
    }
    sfRenderWindow_clear(opt->window, sfTransparent);
    sfText_setString(opt->end_text, "Well done ! Your score is:");
    sfRenderWindow_drawText(opt->window, opt->end_text, NULL);
    sfRenderWindow_drawText(opt->window, opt->score, NULL);
    sfRenderWindow_display(opt->window);
}
