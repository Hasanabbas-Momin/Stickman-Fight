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
		void startdisplay();	
		void loadmedia();
		void render(SDL_Texture*,SDL_Rect,SDL_Rect);
		//Gets image dimensions
		int getWidth();
		int getHeight();
		void display(int,int ,float,bool);
		void destroy();
		int getcuangle();
		int getdestx();
		int cpaused();
		SDL_Rect animate(float,int );
		SDL_Rect getsourcerect();
		bool ispause();
		void cdis(int , int ,float);

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;
		SDL_Renderer* gRenderer;
		SDL_Window * window ;
		SDL_Texture* background;
		SDL_Texture* t;
		bool right =true;
		int cuangle=0;
		int destx;
		//Image dimensions
		int mWidth;
		int mHeight;
		int animations=4;
		SDL_Rect clips [4];
		SDL_Rect clips2 [4];
		SDL_Rect clips3[4];
		SDL_Rect clips4[4];
		SDL_Rect src ={580,500,200,200};
		float count=0;
		SDL_Rect dest;
		float animation_time = 0.15;
		float count2=0;
		int flag=1;
		bool gamepause;
};
