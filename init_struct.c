/*
** EPITECH PROJECT, 2021
** B-MUL-100-RUN-1-1-myhunter-apolline.fontaine
** File description:
** init_struct.c
*/

#include "./include/hunter.h"

duck_t init_duck_struct(duck_t duck)
{
    duck.sprite = sfSprite_create();
    duck.duck = sfTexture_createFromFile("./img/duck.png", NULL);
    duck.clock = sfClock_create();
    duck.sprite_back = sfSprite_create();
    duck.background = sfTexture_createFromFile("./img/background.png", NULL);
    duck.score = 0;
    duck.life = 3;
    duck.rect = (sfIntRect){0, 0, 110, 110};

    return duck;
}

opt_t init_option_struct(opt_t opt, sfVideoMode video_mode)
{
    opt.window = create_win(video_mode, WIN, sfClose | sfResize, NULL);
    opt.kill_buf = sfSoundBuffer_createFromFile("./sounds/kill.ogg");
    opt.kill = sfSound_create();
    opt.font = sfFont_createFromFile("./fonts/valuoldcaps.ttf");
    opt.score = sfText_create();
    opt.end_text = sfText_create();
    sfText_setFont(opt.score, opt.font);
    sfText_setFont(opt.end_text, opt.font);
    sfText_setPosition(opt.score, (sfVector2f){350, 5});
    sfText_setPosition(opt.end_text, (sfVector2f){40, 250});
    sfText_setCharacterSize(opt.end_text, 45);
    return opt;
}
