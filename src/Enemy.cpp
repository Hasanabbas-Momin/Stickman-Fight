#include"../include/Enemy.hpp"

Enemy :: Enemy(int speed){
	count = 0;
	num_sprites = 8;
	//int direction =1;
	//cout<<"direction" <<direction<<endl;
	int a=(rand()%2);
    cout<<"direction ==" <<a <<endl;
	setdirection(a);
	dest = new Rect_point();
	if(direction==0)
		dest->x_pos = (-1*(rand()%1000))-(rand()%500);
	else if(direction==1)
		dest->x_pos = (rand()%500)+1750;
	dest->y_pos = 520;
	cout<<"Starting postion of enemy " <<dest->x_pos<<endl;
	

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

	this->speed = speed;


	// 
}
void Enemy :: setdirection(int a){
	this->direction = a;
}
void Enemy :: setter(int health,SDL_Texture *sprite_sheet,float animation_time){
  this->health = health;
  this->sprite_sheet = sprite_sheet;
  this->animation_time = animation_time;
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
	

}

void Enemy :: draw_player(Window *w,float secondsElapsed ){
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
  //cout<<"direction at draw_player "<<direction<<endl;
  if(direction==0){
	  w->Render_texture(this->sprite_sheet,&start,&dest_);
  }
  else if(direction ==1){
	  w->rend(this->sprite_sheet,&start,&dest_);
  }

  
}
int Enemy :: getdirection(){
	return direction;
}
SDL_Rect Enemy::getrect(){
	SDL_Rect t;
	t.x=dest->x_pos;
	t.y=dest->y_pos;
	t.w=100;
	t.h=150;
	return t;
}
void Enemy :: update_position(float secondsElapsed){
    //cout<<"directino at update_position " <<direction<<endl;
	if(direction==0){
		if(dest->x_pos > 650){
    		dest->x_pos = -200;
    	}
		dest->x_pos += this->speed*secondsElapsed;
	}
    else if(direction==1){
		if(dest->x_pos < 500){
    		dest->x_pos = 1500;
    	}
		dest->x_pos -= this->speed*secondsElapsed;
	}
}
