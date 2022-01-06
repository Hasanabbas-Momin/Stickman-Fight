#pragma once

#include<iostream> 
#include<vector> 
#include"hero.hpp"
#include"enemy.hpp"
#include"Rect_point.hpp"
#include"Window.hpp"

using namespace std;

// Both enemy and the hero
class Player{

   protected: 
	SDL_Texture *sprite_sheet; 
   float animation_time; 
   Rect_point *src; // curr_pos on sprite sheet
   Rect_point *dest; // curr_pos on destination
   Rect_point *sprite_points;
   SDL_Rect p_collider; // collision box of a player.
   int direction; // 0 means facing left and 1 means facing right.
   SDL_Renderer* gRenderer;

    

   public: 
       //virtual void gettexture()=0;
       
       int collision(Enemy enemy,LTexture hero);
       void destroy();

};
