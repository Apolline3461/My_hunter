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
    duck.score = 0;

    return duck;
}

opt_t init_option_struct(opt_t opt, sfVideoMode video_mode)
{
    opt.window = create_win(video_mode, WIN, sfClose | sfResize, NULL);
    opt.kill_buf = sfSoundBuffer_createFromFile("./sounds/kill.ogg");
    opt.kill = sfSound_create();

    return opt;
}
