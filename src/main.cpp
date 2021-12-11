#include"../include/Window.hpp"
#include"../include/Button.hpp"
#include"../include/Mouse.hpp"
#include"../include/leaderboard.hpp"

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
  
  // Loding the images
  SDL_Texture *Back_ground = (window->loadTexture("../images/Background.jpg"));
  Button *b = new Button(600,300,100,100,"../images/play.png");


  Mouse *m = new Mouse();
  SDL_StartTextInput();
  SDL_Rect *s = new SDL_Rect();
  s->x = 50;
  s->y = 50; 
  s->h = 50;
  s->w = 60;



  //** different screens
  bool Home_screen = true;
  bool Play_screen = false;
  bool Leader_board_screen = false; 
  bool Exit_screen = false;



  while (gameRunning)
  {   
      while (SDL_PollEvent(&event))
      {
          if (event.type == SDL_QUIT)
              gameRunning = false;
      }
      cout << m->get_mouse_x() << " " <<  m->get_mouse_y() << endl;
      

      if(Leader_board_screen){
       window->clear();
       leaderboard* score=new leaderboard(window);
       int temp=score->display_score();
       if(temp){
        Leader_board_screen=false;
        Home_screen=true;
       }
       score->destroy();
      }
      if(Home_screen){

       window->clear();
       SDL_PumpEvents();
       SDL_SetTextInputRect(s);
       window->Render_texture(Back_ground);
       b->draw_button(window);

       if(b->isClicked(m)){
        Home_screen = false; 
        //Play_screen = true;
        Leader_board_screen=true;
       }

       window->display();

      }

      if(Play_screen){
         window->clear();
         window->display();
       }

  }

  window->cleanUp();
  SDL_Quit();

}

int main()
{
    Initilize();
    main_game_loop();
}
