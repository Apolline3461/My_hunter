/*
** EPITECH PROJECT, 2021
** Hunter
** File description:
** main.c
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "include/hunter.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left = (rect->left + offset);
    if (rect->left >= max_value)
        rect->left = 0;
}

void display_sprite(sfRenderWindow *window, sfSprite *sprite)
{
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void analyse_events(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

void display_duck(duck_t duck)
{
    while (sfRenderWindow_isOpen(duck.window)) {
        analyse_events(duck.window, duck.event);
        sfSprite_setTextureRect(duck.sprite, (sfIntRect){0, 0, 110, 110});
        sfRenderWindow_clear(duck.window, sfBlack);
        display_sprite(duck.window, duck.sprite);
        duck.time = sfClock_getElapsedTime(duck.clock);
        if (sfTime_asMilliseconds(duck.time) >= 200) {
            move_rect(&(sfIntRect){0, 0, 110, 110}, 110, 330);
            sfClock_restart(duck.clock);
        }
        sfRenderWindow_display(duck.window);
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

int main()
{
    duck_t duck;
    duck = init_duck_struct(duck, (sfVideoMode){720, 480, 32});
    sfRenderWindow_setFramerateLimit(duck.window, 120);

    sfSprite_setTexture(duck.sprite, duck.duck, sfFalse);
    display_duck(duck);
}