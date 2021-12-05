/*
** EPITECH PROJECT, 2021
** B-MUL-100-RUN-1-1-myhunter-apolline.fontaine
** File description:
** my_duck.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "./include/hunter.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left = (rect->left + offset);
    if (rect->left >= max_value)
        rect->left = 0;
}

void click_to_kill(duck_t *duck, opt_t *opt)
{
    sfVector2i p_mouse = sfMouse_getPositionRenderWindow(opt->window);
    sfFloatRect rec_d = sfSprite_getGlobalBounds(duck->sprite);

    if (corresp(&rec_d, p_mouse.x, p_mouse.y) && button_press(sfMouseLeft)) {
        sfSprite_setPosition(duck->sprite, (sfVector2f){-250, rand() % 490});
        duck->score = count_score(duck->score);
    }
    sfSound_setBuffer(opt->kill, opt->kill_buf);
    sfSound_play(opt->kill);
}

void analyse_events(opt_t *opt, duck_t *duck)
{
    while (sfRenderWindow_pollEvent(opt->window, &opt->event)) {
        if (opt->event.type == sfEvtClosed)
            sfRenderWindow_close(opt->window);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            click_to_kill(duck, opt);
    }
}

void display_duck(duck_t *duck, opt_t *opt)
{
    int speed = 10;
    sfVector2f pos_act = sfSprite_getPosition(duck->sprite);

    sfSprite_setTexture(duck->sprite, duck->duck, sfFalse);
    sfSprite_setTextureRect(duck->sprite, duck->rect);
    pos_act.x += speed;
    duck->time = sfClock_getElapsedTime(duck->clock);
    if (sfTime_asMilliseconds(duck->time) >= 100) {
        move_rect(&duck->rect, 110, 330);
        sfClock_restart(duck->clock);
    }
    if (pos_act.x >= 800) {
        duck->life--;
        pos_act.x = -50;
        pos_act.y = rand() % 490;
    }
    sfSprite_setPosition(duck->sprite, pos_act);
    sfRenderWindow_drawSprite(opt->window, duck->sprite, NULL);
}
