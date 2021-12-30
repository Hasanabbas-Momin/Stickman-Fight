#include"../include/Enemy.hpp"
//#include"../include/Window.hpp"

Enemy :: Enemy(Window *win){
	gRenderer=win->get_renderer();
	count = 0;
	num_sprites = 8;
	
	dest = new Rect_point();
	dest->x_pos = 300;
	dest->y_pos = 520;
	

	// hardcoding all the values of sprite sheet
	sprite_points = new Rect_point[100];

	sprite_points[0].x_pos = 0;
	sprite_points[0].y_pos = 0;
	sprite_points[0].width = 156;
	sprite_points[0].height = 189;


	sprite_points[1].x_pos = 159;
	sprite_points[1].y_pos = 0;
	sprite_points[1].width = 162;
	sprite_points[1].height = 198;


	sprite_points[2].x_pos = 334;
	sprite_points[2].y_pos = 0;
	sprite_points[2].width = 163;
	sprite_points[2].height = 208;


	sprite_points[3].x_pos = 522;
	sprite_points[3].y_pos = 0;
	sprite_points[3].width = 157;
	sprite_points[3].height = 214;



	sprite_points[4].x_pos = 693;
	sprite_points[4].y_pos = 0;
	sprite_points[4].width = 149;
	sprite_points[4].height = 223;


	sprite_points[5].x_pos = 0;
	sprite_points[5].y_pos = 225;
	sprite_points[5].width = 147;
	sprite_points[5].height = 201;



	sprite_points[6].x_pos = 155;
	sprite_points[6].y_pos = 255;
	sprite_points[6].width = 176;
	sprite_points[6].height = 206;


	sprite_points[7].x_pos = 331;
	sprite_points[7].y_pos = 225;
	sprite_points[7].width = 175;
	sprite_points[7].height = 197;



  	sprite_points[8].x_pos = 517;
	sprite_points[8].y_pos = 225;
	sprite_points[8].width = 155;
	sprite_points[8].height = 207;



	sprite_points[9].x_pos = 703;
	sprite_points[9].y_pos = 225;
	sprite_points[9].width = 139;
	sprite_points[9].height = 201;


	// 
}

void Enemy :: setter(int health,SDL_Texture *sprite_sheet,float animation_time){
  this->health = health;
  this->sprite_sheet = sprite_sheet;
  this->animation_time = animation_time;
}
void Enemy:: gettexture()
{
	SDL_Surface* surface = IMG_Load("../images/Enemy.png");
	SDL_Texture* t;
	t=SDL_CreateTextureFromSurface(gRenderer,surface);
	SDL_FreeSurface(surface);
	this->setter(100,t,0.1);
	//return t;
}
void Enemy :: animate(float secondsElapsed){

    if(count < 1*animation_time){
        src = &(this->sprite_points[0]);
    }

    else if((count >= 1*animation_time) && (count < 2*animation_time)){
    	src = &(this->sprite_points[1]);
    }

    else if((count >= 2*animation_time) && (count < 3*animation_time)){
    	src = &(this->sprite_points[2]);
    }

    else if((count >= 3*animation_time) && (count < 4*animation_time)){
    	src = &(this->sprite_points[3]);
    }

    else if((count >= 4*animation_time) && (count < 5*animation_time)){
    	src = &(this->sprite_points[4]);
    }

    else if((count >= 5*animation_time) && (count < 6*animation_time)){
    	src = &(this->sprite_points[5]);
    }

    else if((count >= 6*animation_time) && (count < 7*animation_time)){
    	src = &(this->sprite_points[6]);
    }

    else if((count >= 7*animation_time) && (count < 8*animation_time)){
    	src = &(this->sprite_points[7]);
    }


    else if((count >= 8*animation_time) && (count < 9*animation_time)){
    	src = &(this->sprite_points[8]);
    }
     
    else if((count >= 9*animation_time) && (count < 10*animation_time)){
    	src = &(this->sprite_points[9]);
    }

    else if(count >= 10*animation_time){
    	count = 0;
    }

     
    count += secondsElapsed;
	cout<<"count "<<count/animation_time<<endl;

}
void Enemy :: changecount(int ch, int d=0){
	count =ch;
	dest->x_pos=ch*100;
	direction =d;
}
int Enemy :: getposx(){
	return dest->x_pos;
}
void Enemy :: draw_player(float secondsElapsed){
  this->animate(secondsElapsed);
  SDL_Rect start; 
  start.x = src->x_pos;
  start.y = src->y_pos;
  start.w = src->width; 
  start.h = src->height;

  SDL_Rect dest_;
  dest_.x = dest->x_pos;
  dest_.y = dest->y_pos;
  dest_.w = 100;
  dest_.h = 150;
  if(direction==0){
	SDL_RenderCopyEx(gRenderer,this->sprite_sheet,&start,&dest_,0,NULL,SDL_FLIP_NONE);
  	SDL_RenderPresent(gRenderer);
  }
  else{
	SDL_RenderCopyEx(gRenderer,this->sprite_sheet,&start,&dest_,180,NULL,SDL_FLIP_VERTICAL);
  	SDL_RenderPresent(gRenderer);
  }
  
  //w->Render_texture(this->sprite_sheet,&start,&dest_);
}

void Enemy :: update_position(float secondsElapsed){
	if(direction==0){
		dest->x_pos += 300*secondsElapsed;
    	if(dest->x_pos > 640){
    		dest->x_pos = 0;
    	}
	}
	else{
		dest->x_pos -= 300*secondsElapsed;
    	if(dest->x_pos <640){
    		dest->x_pos = 1280;
    	}
	}
    
}
float Enemy::getcount(){
	return count;
}
int Enemy:: getdirection(){
	return direction;
}
