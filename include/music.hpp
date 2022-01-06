#pragma once
#include<SDL2/SDL.h>
#include<SDL2/SDL_mixer.h>
#include<iostream>
using namespace std;
class music{
    public:
        music();
        void playmusic(const char*,int);
};