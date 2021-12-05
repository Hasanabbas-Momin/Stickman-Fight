#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include<iostream>
#include<inttypes.h>


class Mouse{
private:
	int x_pos;
	int y_pos;
	

public: 
	int get_mouse_x(){
       SDL_GetMouseState(&x_pos,&y_pos);
       return this->x_pos;
	}

	int get_mouse_y(){
		SDL_GetMouseState(&x_pos,&y_pos);

		return this->y_pos;
	}

};