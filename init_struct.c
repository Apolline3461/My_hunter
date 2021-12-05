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
    duck.duck = setT_fromfile("./img/duck.png", NULL);
    duck.clock = sfClock_create();
    duck.score = 0;
    duck.life = 3;
    duck.speed = 10;
    duck.rect = (sfIntRect){0, 0, 110, 110};
    return duck;
}

menu_t init_menu_struct(menu_t menu)
{
    menu.sprite_menu = sfSprite_create();
    menu.menu = setT_fromfile("./img/menu.jpg", NULL);
    menu.font_menu = sfFont_createFromFile("./fonts/ChrustyRock-ORLA.ttf");
    menu.enter = sfText_create();
    menu.quit = sfText_create();
    setTexture(menu.sprite_menu, menu.menu, sfFalse);
    sfText_setFont(menu.enter, menu.font_menu);
    sfText_setFont(menu.quit, menu.font_menu);
    sfText_setPosition(menu.enter, (sfVector2f){200, 190});
    sfText_setPosition(menu.quit, (sfVector2f){220, 350});
    sfText_setColor(menu.enter, sfBlue);
    sfText_setColor(menu.quit, sfBlack);
    return menu;
}

pict_t init_pictures_struct(pict_t pic)
{
    pic.sprite_back = sfSprite_create();
    pic.background = setT_fromfile("./img/background.png", NULL);
    pic.sprite_black_backgr = sfSprite_create();
    pic.black_back = setT_fromfile("./img/black_background.png", NULL);
    setTexture(pic.sprite_black_backgr, pic.black_back, sfFalse);
    return pic;
}

void set_front_and_text(opt_t opt)
{
    setTexture(opt.target_sprite, opt.target, sfFalse);
    sfText_setFont(opt.score, opt.font);
    sfText_setFont(opt.end_text, opt.font);
    sfText_setPosition(opt.score, (sfVector2f){360, 7});
    sfText_setPosition(opt.end_text, (sfVector2f){32, 250});
    sfText_setCharacterSize(opt.end_text, 45);
    sfText_setCharacterSize(opt.score, 30);
    sfText_setColor(opt.end_text, sfBlack);
    sfText_setColor(opt.score, sfBlack);
}

opt_t init_option_struct(opt_t opt, sfVideoMode video_mode)
{
    opt.window = create_win(video_mode, WIN, sfClose | sfResize, NULL);
    opt.kill_buf = sfSoundBuffer_createFromFile("./sounds/kill.ogg");
    opt.kill = sfSound_create();
    opt.font = sfFont_createFromFile("./fonts/valuoldcaps.ttf");
    opt.score = sfText_create();
    opt.end_text = sfText_create();
    opt.target_sprite = sfSprite_create();
    opt.target = setT_fromfile("./img/red_target.png", NULL);
    set_front_and_text(opt);
    opt.pic = init_pictures_struct(opt.pic);
    opt.structM = init_menu_struct(opt.structM);
    opt.menu = 0;
    return opt;
}
