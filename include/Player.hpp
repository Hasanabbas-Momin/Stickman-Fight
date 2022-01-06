#pragma once

#include<iostream> 
#include<vector> 
#include"Rect_point.hpp"
#include"Window.hpp"

using namespace std;

// Both enemy and the hero
class Player{

   protected: 
	int health; // health of the player
	SDL_Texture *sprite_sheet; 
    float animation_time; 
    Rect_point *src; // curr_pos on sprite sheet
    Rect_point *dest; // curr_pos on destination
    Rect_point *sprite_points;
    int num_sprites;

    

   public: 
   	 virtual void setter(int health,SDL_Texture *sprite_sheet,float animation_time)=0; 
   	 virtual void animate(float secondsElapsed)=0;
   	 virtual void draw_player(Window *w,float secondsElapsed)=0;

};
