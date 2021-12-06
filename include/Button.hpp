#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include<iostream>
#include"Window.hpp"
#include"Mouse.hpp"


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
	bool isOnButton(Mouse *m); // returns if True if mouse is on the button
	bool isClicked(Mouse *m); // returs true if the Button is clicked

}; 