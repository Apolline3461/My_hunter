/*
** EPITECH PROJECT, 2021
** B-MUL-100-RUN-1-1-myhunter-apolline.fontaine
** File description:
** my_duck.c
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "./include/hunter.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left = (rect->left + offset);
    if (rect->left >= max_value)
        rect->left = 0;
}

void analyse_events(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

void display_duck(duck_t *duck, sfIntRect *rect)
{
        sfSprite_setTexture(duck->sprite, duck->duck, sfFalse);
        sfSprite_setTextureRect(duck->sprite, *rect);
        sfRenderWindow_drawSprite(duck->window, duck->sprite, NULL);
        duck->time = sfClock_getElapsedTime(duck->clock);
        if (sfTime_asMilliseconds(duck->time) >= 200) {
            move_rect(rect, 110, 330);
            sfClock_restart(duck->clock);
        }
}

duck_t init_duck_struct(duck_t duck, sfVideoMode video_mode)
{
    duck.sprite = sfSprite_create();
    duck.duck = sfTexture_createFromFile("./img/duck.png", NULL);
    duck.clock = sfClock_create();
    duck.window = sfRenderWindow_create(video_mode, "My Hunter", sfClose | sfResize, NULL);

    return duck;
}
