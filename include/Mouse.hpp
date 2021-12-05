#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include<iostream>
#include<inttypes.h>

using namespace std;


class Mouse{
private:
	int x_pos;
	int y_pos;
	

public: 
	int get_mouse_x();
	int get_mouse_y();
	bool isClicked(); // only Left click can be detected
	

};