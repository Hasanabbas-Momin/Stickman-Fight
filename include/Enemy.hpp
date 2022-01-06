#pragma once
 
#include "Player.hpp"


class Enemy : public Player{
private:
	float count;
	int speed;
	int direction;//0->0
				  //1->180

public:
	Enemy(int speed);
	void setter(int health,SDL_Texture *sprite_sheet,float animation_time);
	void animate(float secondsElapsed);
	void draw_player(Window *w,float secondsElapsed);
	void update_position(float secondsElapsed);
	SDL_Rect getrect();
	int getdirection();
	void setdirection(int);


};