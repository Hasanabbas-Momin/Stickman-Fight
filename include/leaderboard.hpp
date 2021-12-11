#pragma once
#include <stdlib.h>
#include<iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include<SDL2/SDL_image.h>
#include<fstream>
#include<vector>
#include<string.h>
#include"Window.hpp"
#undef main
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
using namespace std;
#pragma once
class leaderboard {
public:
    void update_score(string, int);
    void get_text_and_rect(SDL_Renderer*, int, int, char*, TTF_Font*, SDL_Texture**, SDL_Rect*);
    void destroy();
    int display_score();
    leaderboard(Window* win) {
        window = win->get_window();
        renderer = win->get_renderer();
    }
   

    
private:
    int number_of_players;
    SDL_Window* window;
    SDL_Rect rect[10];
    SDL_Rect rect_score[10];
    SDL_Rect rect_face[10];
    SDL_Rect rect_top[3];
    SDL_Rect rect_name_back[10];
    SDL_Texture* tex_face[10];
    SDL_Renderer* renderer;
    SDL_Texture* texture[10];
    SDL_Texture* tex_score[10];
    SDL_Texture* tex_top[3];
    SDL_Texture* tex_name_background[10];
    SDL_Texture* back_tex;
};
