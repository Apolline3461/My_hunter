/*
** EPITECH PROJECT, 2021
** Hunter
** File description:
** main.c
*/

#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "./include/hunter.h"
#include "./include/printf.h"

void display_backgr(duck_t *duck)
{
    back_t back;

    back.sprite_back = sfSprite_create();
    back.background = sfTexture_createFromFile("./img/background.png", NULL);
    sfSprite_setTexture(back.sprite_back, back.background, sfFalse);
    sfRenderWindow_clear(duck->window, sfTransparent);
    sfRenderWindow_drawSprite(duck->window, back.sprite_back, NULL);
}

void open_win(duck_t *duck, sfIntRect rect)
{
    while (sfRenderWindow_isOpen(duck->window)) {
        analyse_events(duck->window, duck->event);
        display_backgr(duck);
        display_duck(duck, &rect);
        sfRenderWindow_display(duck->window);
    }
}

int main(int argc, char **argv)
{
    duck_t duck;
    sfIntRect rect = {0, 0, 110, 110};
    (void)argc;
    (void)argv;

    duck = init_duck_struct(duck, (sfVideoMode){800, 600, 32});
    sfRenderWindow_setFramerateLimit(duck.window, 120);
    open_win(&duck, rect);
    return 0;
}
