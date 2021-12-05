#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include<iostream>
#include"Window.hpp"



class Button{
private: 
	int x_pos;
	int y_pos; 
	const char* image_path;
	int width;
	int height;

public: 
	Button(int x_pos,int y_pos,int width,int height,const char* image_path);
	void draw_button(Window *w); 
	bool isOnButton(int mouse_x,int mouse_y); // returns if True if mouse is on the button
	bool isClicked(int mouse_x,int mouse_y); // returs true if the Button is clicked

}; 