
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
// Loads the Texture
SDL_Texture* Window :: loadTexture(const char *file_path){
    SDL_Texture *tex = NULL;
    tex = IMG_LoadTexture(this->renderer,file_path);

    if(tex == NULL){
       cout << "Error : " << SDL_GetError() << endl;
    }

    return tex;

}

// clears the screen
void Window :: clear(){
    SDL_RenderClear(this->renderer);
}

// Renders the texture 
void Window :: Render_texture(SDL_Texture *tex){
   SDL_RenderCopy(this->renderer,tex,NULL,NULL);
}

void Window :: Render_texture(SDL_Texture *tex,int x,int y,int width,int height){
    

    SDL_Rect *end = (SDL_Rect *) malloc(sizeof(SDL_Rect));
    end->x = x;
    end->y = y;
    end->h= height;
    end->w = width;
    SDL_RenderCopy(this->renderer,tex,NULL,end);


}

// displays the texture (updates the display)
void Window :: display(){
    SDL_RenderPresent(this->renderer);
}


