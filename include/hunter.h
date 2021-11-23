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

typedef struct duck_s
{
    sfTime time;
    sfEvent event;
    sfClock *clock;
    sfRenderWindow *window;
    sfSprite *sprite;
    sfTexture *duck;

}duck_t;

#endif