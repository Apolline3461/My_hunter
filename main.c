/*
** EPITECH PROJECT, 2021
** Hunter
** File description:
** main.c
*/

#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include "./include/hunter.h"
#include "./include/printf.h"

void destroy_my_sprite(duck_t *duck, opt_t *op)
{
    sfSprite_destroy(duck->sprite);
    sfSprite_destroy(duck->sprite_back);
    sfSound_destroy(op->kill);
    sfSoundBuffer_destroy(op->kill_buf);
}

void display_backgr(opt_t *option, duck_t *duck)
{
    duck->sprite_back = sfSprite_create();
    duck->background = sfTexture_createFromFile("./img/background.png", NULL);
    sfSprite_setTexture(duck->sprite_back, duck->background, sfFalse);
    sfRenderWindow_clear(option->window, sfTransparent);
    sfRenderWindow_drawSprite(option->window, duck->sprite_back, NULL);
}

void open_win(opt_t *option, sfIntRect rect, duck_t *duck)
{

    while (sfRenderWindow_isOpen(option->window)) {
        analyse_events(option, duck);
        display_backgr(option, duck);
        display_duck(duck, &rect, option);
        sfRenderWindow_display(option->window);
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
    opt_t option;
    sfIntRect rect = {0, 0, 110, 110};
    srand(time(0));

    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        help_option();
        return 0;
    }
    duck = init_duck_struct(duck);
    option = init_option_struct(option, (sfVideoMode){800, 600, 32});
    sfRenderWindow_setFramerateLimit(option.window, 30);
    open_win(&option, rect, &duck);
    destroy_my_sprite(&duck, &option);
    return 0;
}
