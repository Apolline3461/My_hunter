/*
** EPITECH PROJECT, 2021
** Hunter
** File description:
** main.c
*/

#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
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
        analyse_events(duck);
        display_backgr(duck);
        display_duck(duck, &rect);
        sfRenderWindow_display(duck->window);
    }
}

void help_option()
{
    char *help = "\n   MY HUNTER:\n\nThe goal of the game";
    char *help1 = " is  to shoot the ducks that appear on the screen.\n";
    char *help2 = "To do this, use your mouse to click on the ducks.\n\n";

    my_printf("%s%s%s", help, help1, help2);
}

int main(int argc, char **argv)
{
    duck_t duck;
    sfIntRect rect = {0, 0, 110, 110};
    srand(time(0));

    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        help_option();
        return 0;
    }
    duck = init_duck_struct(duck, (sfVideoMode){800, 600, 32});
    sfRenderWindow_setFramerateLimit(duck.window, 120);
    open_win(&duck, rect);
    return 0;
}
