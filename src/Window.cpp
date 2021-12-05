
#include"../include/Window.hpp" 

Window :: Window(const char *title, int w, int h){

	this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            cout << "Window failed to init ERROR:" << SDL_GetError() << endl;
        }
    this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void Window :: cleanUp(){
	SDL_DestroyWindow(window);
}