#pragma once 
#include"Enemy.hpp" 
#include"Window.hpp"
#include<vector> 

using namespace std;

 class Game{

 public:
 	vector<Enemy *> enemys; // list of random Enemys (Enemys spwn in the group)
 	SDL_Texture *Back_ground;
  SDL_Texture *enemy_text;
  //Mouse *m;
  //Button *b;
  Window *window;
  int Round_count;
  void removeadd(int );


 public:
 	Game(Window *win); // constructor
  void spawn_random_enemys(int num);
  vector<Enemy *> get_enemys();
   ~Game(); // destructor



 };