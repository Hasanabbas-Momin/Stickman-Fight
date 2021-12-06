#include"../include/Button.hpp"


Button :: Button(int x_pos,int y_pos,int width,int height,const char* image_path){
	this->x_pos = x_pos; 
	this->y_pos = y_pos;
	this->width = width;
	this->height = height;
	this->image_path = image_path;
}

void Button :: draw_button(Window* w){
   SDL_Texture *texture = w->loadTexture(this->image_path);
   w->Render_texture(texture,this->x_pos,this->y_pos,this->width,this->height);
}


bool Button :: isOnButton(Mouse *m){
	int mouse_x = m->get_mouse_x(); 
	int mouse_y = m->get_mouse_y();

    if((mouse_x > this->x_pos)&&(mouse_x < this->x_pos + this->width)){
    	 if((mouse_y > this->y_pos)&&(mouse_y < this->y_pos + this->height)){
                return true;
    	 }

    	 return false;	
    }
    return false;
}

bool Button :: isClicked(Mouse *m){
	if(this->isOnButton(m) && m->isClicked()){
		return true;
	}

	return false;
}