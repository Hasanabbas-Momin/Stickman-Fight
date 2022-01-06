
#include"../include/Game.hpp"
#include<stdlib.h> 

// constructor
Game :: Game(Window * win){

	window = win;
	Back_ground = (window->loadTexture("images/Background.jpg"));
    enemy_text = (window->loadTexture("images/Enemy.png"));
    //b = new Button(600,300,100,100,"../images/play.png");
    //m = new Mouse();
    Round_count = 0;
	
}
void Game:: spawn_random_enemys(int num){
	//for(int i=0 ;i<num;i++){
  int i=1;
  while(i<num*num+1){
    if(i%num==0){
      int speed =(rand()%101)+100;

		  this->enemys.push_back(new Enemy(speed));
    }
    i++;

	}
	for(Enemy * e :enemys){
    
		e->setter(100,enemy_text,0.07);
	}
}
void Game :: removeadd (int i){
  this->enemys.erase(enemys.begin()+i);
  cout<<"enemysize " <<this->enemys.size()<<endl;
  int speed = (rand()%101)+50;
  this->enemys.push_back(new Enemy(speed));
  Enemy *e =this->enemys[enemys.size()-1];
  e->setter(100,enemy_text,0.07);
}


vector<Enemy *> Game :: get_enemys(){
	return enemys;
}

// destructor
Game :: ~Game(){
	
}