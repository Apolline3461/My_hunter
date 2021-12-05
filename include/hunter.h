/*
** EPITECH PROJECT, 2021
** Hunter
** File description:
** hunter.h
*/

#ifndef HUNTER_H
    #define HUNTER_H
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include "printf.h"

    #define WIN "my_hunter"
    #define create_win sfRenderWindow_create
    #define button_press sfMouse_isButtonPressed
    #define corresp sfFloatRect_contains
    #define setTexture sfSprite_setTexture
    #define setT_fromfile sfTexture_createFromFile
    #define setPosS sfSprite_setPosition
    #define spritetar opt->target_sprite

    typedef struct menu_s
    {
        sfSprite *sprite_menu;
        sfTexture *menu;
        sfFont *font_menu;
        sfText *enter;
        sfText *quit;

    } menu_t;

    typedef struct pictures_s
    {
        sfSprite *sprite_back;
        sfTexture *background;
        sfSprite *sprite_black_backgr;
        sfTexture *black_back;

    } pict_t;

    typedef struct option_s
    {
        sfRenderWindow *window;
        sfEvent event;
        sfSoundBuffer *kill_buf;
        sfSound *kill;
        sfFont *font;
        sfText *score;
        sfText *end_text;
        pict_t pic;
        sfSprite *target_sprite;
        sfTexture *target;
        int menu;
        menu_t structM;

    }opt_t;

    typedef struct duck_s
    {
        int speed;
        int score;
        int life;
        sfTime time;
        sfClock *clock;
        sfIntRect rect;
        sfSprite *sprite;
        sfTexture *duck;

    }duck_t;

    duck_t init_duck_struct(duck_t duck);
    void analyse_events(opt_t *opt, duck_t *duck);
    int my_strcmp(char const *s1, char const *s2);
    opt_t init_option_struct(opt_t opt, sfVideoMode video_mode);
    pict_t init_pictures_struct(pict_t pic);
    void display_duck(duck_t *duck, opt_t *opt);
    int count_score(int score);
    char *int_to_string(int score);
    void game_loop(duck_t *duck, opt_t *option);
    void end_loop(opt_t *opt, duck_t *duck);
    void display_backgr(opt_t *option);
    void display_menu(opt_t *op);
    void display_backgr(opt_t *option);

#endif
