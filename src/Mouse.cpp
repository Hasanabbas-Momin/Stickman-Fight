#include "../include/Mouse.hpp"

int Mouse :: get_mouse_x(){
       SDL_GetMouseState(&x_pos,&y_pos);
       return this->x_pos;
}

int Mouse :: get_mouse_y(){
	SDL_GetMouseState(&x_pos,&y_pos);

	return this->y_pos;
}

bool Mouse :: isClicked(){
	
	Uint32 cursors =  SDL_GetMouseState(&x_pos, &y_pos);

	if((cursors & SDL_BUTTON_LMASK) != 0){
        return true;
	}

	return false;
}
