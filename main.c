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
    sfSprite_destroy(op->pic.sprite_back);
    sfSound_destroy(op->kill);
    sfSoundBuffer_destroy(op->kill_buf);
    sfFont_destroy(op->font);
    sfText_destroy(op->score);
    sfSprite_destroy(op->target_sprite);
    sfSprite_destroy(op->structM.sprite_menu);
    sfFont_destroy(op->structM.font_menu);
    sfText_destroy(op->structM.enter);
    sfText_destroy(op->structM.quit);
}

void open_win(opt_t *option, duck_t *duck)
{
    while (sfRenderWindow_isOpen(option->window)) {
        if (option->menu == 1) {
            if (duck->life != 0)
                game_loop(duck, option);
            else
                end_loop(option, duck);
        } else
            display_menu(option);
    }
}

void help_option(void)
{
    char *help = "\n   MY HUNTER:\n\nThe goal of the game";
    char *help1 = " is  to shoot the ducks that appear on the screen.\n";
    char *help2 = "To do this, use your mouse to click on the ducks.\n\n";
    char *help3 = "             Becareful, you only have 3 lives...\n\n";

    my_printf("%s%s%s%s", help, help1, help2, help3);
}

int main(int argc, char **argv)
{
    duck_t duck;
    opt_t option;
    srand(time(0));

    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        help_option();
        return 0;
    }
    duck = init_duck_struct(duck);
    option = init_option_struct(option, (sfVideoMode){800, 600, 32});
    sfRenderWindow_setFramerateLimit(option.window, 30);
    open_win(&option, &duck);
    destroy_my_sprite(&duck, &option);
    return 0;
}
