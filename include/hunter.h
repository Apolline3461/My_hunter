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

    typedef struct option_s
    {
        sfRenderWindow *window;
        sfEvent event;
        sfSoundBuffer *kill_buf;
        sfSound *kill;
        sfFont *font;
        sfText *score;
        sfText *end_text;

    }opt_t;

    typedef struct duck_s
    {
        int score;
        int life;
        sfTime time;
        sfClock *clock;
        sfIntRect rect;
        sfSprite *sprite;
        sfTexture *duck;
        sfSprite *sprite_back;
        sfTexture *background;

    }duck_t;

    duck_t init_duck_struct(duck_t duck);
    void analyse_events(opt_t *opt, duck_t *duck);
    int my_strcmp(char const *s1, char const *s2);
    opt_t init_option_struct(opt_t opt, sfVideoMode video_mode);
    void display_duck(duck_t *duck, opt_t *opt);
    int count_score(int score);
    char *int_to_string(int score);
    void game_loop(duck_t *duck, opt_t *option);
    void end_loop(opt_t *opt);
    void display_backgr(opt_t *option, duck_t *duck);

#endif
