/*
** EPITECH PROJECT, 2021
** B-MUL-100-RUN-1-1-myhunter-apolline.fontaine
** File description:
** display_back.c
*/

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include "./include/hunter.h"

void display_menu(opt_t *op)
{
    sfRenderWindow_drawSprite(op->window, op->structM.sprite_menu, NULL);
    sfRenderWindow_display(op->window);
    while (sfRenderWindow_pollEvent(op->window, &op->event)) {
        if (op->event.type == sfEvtClosed)
            sfRenderWindow_close(op->window);
        if (op->event.type == sfEvtKeyPressed &&
            op->event.key.code == sfKeyEnter) {
            sfRenderWindow_clear(op->window, sfTransparent);
            op->menu = 1;
            }
    }
}

void display_backgr(opt_t *option)
{
    setTexture(option->pic.sprite_back, option->pic.background, sfFalse);
    sfRenderWindow_clear(option->window, sfTransparent);
    sfRenderWindow_drawSprite(option->window, option->pic.sprite_back, NULL);
}
