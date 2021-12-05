#include"../include/Window.hpp"

 // Initilizes the sdl Library
void Initilize(){
  if (SDL_Init(SDL_INIT_VIDEO) > 0)
  {
      cout << "SDL_init has failed ERROR:" << SDL_GetError() << endl;
  }
  if (!(IMG_Init(IMG_INIT_JPG)))
  {
      cout << "IMG-init has failed ERROR:" << SDL_GetError() << endl;
  }

}

void main_game_loop(){
  // Main game loop 
  Window window("Stickman-Fight", 1280, 720);
  bool gameRunning = true;
  SDL_Event event;
  while (gameRunning)
  {
      while (SDL_PollEvent(&event))
      {
          if (event.type == SDL_QUIT)
              gameRunning = false;
      }
  }

  window.cleanUp();
  SDL_Quit();

}

int main()
{
    Initilize();
    main_game_loop();
}
