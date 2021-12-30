#pragma once

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include"../include/Window.hpp"
class LTexture
{
	public:
		//Initializes variables
		LTexture(Window *);

		//Deallocates memory
		~LTexture();


		//Renders texture at given point

		void loadmedia();
		void render(SDL_Texture*,SDL_Rect,SDL_Rect);
		//Gets image dimensions
		int getWidth();
		int getHeight();
		void display(int,int);
		void destroy();

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;
		SDL_Renderer* gRenderer;
		SDL_Window * window ;
		SDL_Texture* background;
		SDL_Texture* t;
		bool right =true;
		int cuangle=0;


		//Image dimensions
		int mWidth;
		int mHeight;
		int animations=4;
		SDL_Rect clips [4];
		SDL_Rect clips2 [4];
		SDL_Rect clips3[4];
};
