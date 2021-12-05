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
    sfRenderWindow_drawSprite(option->window, option->target_sprite, NULL);
    sfRenderWindow_display(option->window);
}

void analyse_event_of_end(opt_t *opt, duck_t *duck)
{
    while (sfRenderWindow_pollEvent(opt->window, &opt->event)) {
        if (opt->event.type == sfEvtClosed)
            sfRenderWindow_close(opt->window);
        if (opt->event.type == sfEvtKeyPressed &&
            opt->event.key.code == sfKeyEnter) {
            sfText_setCharacterSize(opt->score, 30);
            sfText_setPosition(opt->score, (sfVector2f){350, 7});
            duck->life = 3;
            duck->score = 0;
        }
        if (opt->event.type == sfEvtKeyPressed &&
            opt->event.key.code == sfKeyQ)
            sfRenderWindow_close(opt->window);
    }
}

void end_loop(opt_t *opt, duck_t *duck)
{
    sfRenderWindow_setMouseCursorVisible(opt->window, sfTrue);
    sfText_setPosition(opt->score, (sfVector2f){380, 300});
    sfText_setCharacterSize(opt->score, 40);
    analyse_event_of_end(opt, duck);
    sfRenderWindow_clear(opt->window, sfTransparent);
    sfRenderWindow_drawSprite(opt->window, black_backgr, NULL);
    set_str(opt->end_text, "Well done ! Your score is:");
    set_str(txt, "Press enter to restart\n                    or\n        Press Q to exit");
    sfRenderWindow_drawText(opt->window, opt->end_text, NULL);
    sfRenderWindow_drawText(opt->window, txt, NULL);
    sfRenderWindow_drawText(opt->window, opt->score, NULL);
    sfRenderWindow_display(opt->window);
}
