#pragma once
 
#include "../include/Player.hpp"

#include "../include/Window.hpp"


class Enemy : public Player{
private:
	float count;
	SDL_Renderer *gRenderer;
	int direction;

public:
	Enemy(Window* );
	void setter(int health,SDL_Texture *sprite_sheet,float animation_time);
	void animate(float secondsElapsed);
	void draw_player(float secondsElapsed);
	void update_position(float secondsElapsed);
	void gettexture();
	float getcount();
	void changecount(int ch, int d );
	int getposx();
	int getdirection();



};