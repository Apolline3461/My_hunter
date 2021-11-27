/*
** EPITECH PROJECT, 2021
** Hunter
** File description:
** hunter.h
*/

#ifndef HUNTER_H
    #define HUNTER_H
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include "printf.h"

    typedef struct duck_s
    {
        sfTime time;
        sfEvent event;
        sfClock *clock;
        sfRenderWindow *window;
        sfSprite *sprite;
        sfTexture *duck;

    }duck_t;

    typedef struct back_s
    {
        sfSprite *sprite_back;
        sfTexture *background;

    }back_t;

    duck_t init_duck_struct(duck_t duck, sfVideoMode video_mode);
    void analyse_events(sfRenderWindow *window, sfEvent event);
    void display_duck(duck_t *duck, sfIntRect *rect);
    int my_strcmp(char const *s1, char const *s2);

#endif