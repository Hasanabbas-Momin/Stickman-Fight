#include"../include/Window.hpp"
#include"../include/Button.hpp"
#include"../include/Mouse.hpp"

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
  Window *window = new Window("Stickman-Fight", 1280, 720);
  bool gameRunning = true;
  SDL_Event event;

  SDL_Texture *Back_ground = (window->loadTexture("../images/Background.jpg"));
  Button *b = new Button(600,300,100,100,"../images/play.png");
  Mouse *m = new Mouse();
  while (gameRunning)
  {   
      while (SDL_PollEvent(&event))
      {
          if (event.type == SDL_QUIT)
              gameRunning = false;
      }
      cout << m->get_mouse_x() << " " <<  m->get_mouse_y() << endl;

      window->clear();
      SDL_PumpEvents();
      window->Render_texture(Back_ground);
      b->draw_button(window);
      window->display();

  }

  window->cleanUp();
  SDL_Quit();

}

int main()
{
    Initilize();
    main_game_loop();
}
