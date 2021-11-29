/*
** EPITECH PROJECT, 2021
** B-MUL-100-RUN-1-1-myhunter-apolline.fontaine
** File description:
** my_duck.c
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "./include/hunter.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left = (rect->left + offset);
    if (rect->left >= max_value)
        rect->left = 0;
}

void click_to_kill(duck_t *duck)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(duck->window);
    sfFloatRect rect_duck = sfSprite_getGlobalBounds(duck->sprite);

    if (sfFloatRect_contains(&rect_duck, pos_mouse.x, pos_mouse.y))
        sfSprite_setPosition(duck->sprite, (sfVector2f){-250, rand() % 490});
}

void analyse_events(duck_t *duck)
{
    while (sfRenderWindow_pollEvent(duck->window, &duck->event)) {
        if (duck->event.type == sfEvtClosed)
            sfRenderWindow_close(duck->window);
        click_to_kill(duck);
    }
}

void display_duck(duck_t *duck, sfIntRect *rect)
{
    int speed = 3;
    sfVector2f pos_act = sfSprite_getPosition(duck->sprite);

    sfSprite_setTexture(duck->sprite, duck->duck, sfFalse);
    sfSprite_setTextureRect(duck->sprite, *rect);
    pos_act.x += speed;
    duck->time = sfClock_getElapsedTime(duck->clock);
    if (sfTime_asMilliseconds(duck->time) >= 400) {
        move_rect(rect, 110, 330);
        sfClock_restart(duck->clock);
    }
    if (pos_act.x >= 800) {
        pos_act.x = -50;
        pos_act.y = rand() % 490;
    }
    sfSprite_setPosition(duck->sprite, pos_act);
    sfRenderWindow_drawSprite(duck->window, duck->sprite, NULL);
}

duck_t init_duck_struct(duck_t duck, sfVideoMode video_mode)
{
    duck.sprite = sfSprite_create();
    duck.duck = sfTexture_createFromFile("./img/duck.png", NULL);
    duck.clock = sfClock_create();
    duck.window = sfRenderWindow_create(video_mode, "My Hunter", sfClose | sfResize, NULL);

    return duck;
}
