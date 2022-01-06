#include"../include/Window.hpp"
#include"../include/Button.hpp"
#include"../include/Mouse.hpp"
#include"../include/leaderboard.hpp"
#include"../include/hero.hpp"
#include"../include/Enemy.hpp"
#include"../include/Game.hpp"
#include"../include/music.hpp"
#include<vector>
void Initilize(){
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        cout << "SDL_init has failed ERROR:" << SDL_GetError() << endl;
    }
    if (!(IMG_Init(IMG_INIT_JPG || IMG_INIT_PNG)))
    {
        cout << "IMG-init has failed ERROR:" << SDL_GetError() << endl;
    }

}
void main_game_loop(){
    // Main game loop 
    
    Window *window = new Window("Stickman-Fight", 1280, 720);
    bool gameRunning = true;
    Game *g = new Game(window);
    SDL_Event event;
    float secondselapsed=0;
    // Loding the images
    SDL_Texture *Back_ground = (window->loadTexture("images/back.jpg"));
    Button *b = new Button(1100,620,100,100,"images/lead.png");
    Button *c = new Button(600,280,100,100,"images/play.png");
    LTexture hero(window);

    Mouse *m = new Mouse();
    SDL_StartTextInput();
    SDL_Rect *s = new SDL_Rect();
    s->x = 50;
    s->y = 50; 
    s->h = 50;
    s->w = 60;
    music bgm1,bgm2,bgm3;
    bgm1.playmusic("music/mainmenu.mp3",-1);


    //** different screens
    bool Home_screen = true;
    bool Play_screen = false;
    bool Play_screen_enemy = false;
    bool Leader_board_screen = false; 
    bool Exit_screen = false;

    float count=0;
    int degrees=0;
    int sizeofenemy=(rand()%6)+1;
    g->spawn_random_enemys(sizeofenemy);
    cout<<"size of enemy" << sizeofenemy<<endl;
    bool stop=true;

    int scoreofplayer=0;
    while (gameRunning)
    {   
        //cout << m->get_mouse_x() << " " <<  m->get_mouse_y() << endl;
        while (SDL_PollEvent(&event))
      {
          if (event.type == SDL_QUIT)
              gameRunning = false;
          if (Leader_board_screen == true) {
                if (event.type == SDL_KEYDOWN) {
                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                        Leader_board_screen = false;
                        Home_screen = true;
                        Mix_PauseMusic();
                        bgm1.playmusic("music/mainmenu.mp3",-1);
                    }
                }
            }  
      }
        if(Leader_board_screen){
            leaderboard score(window);
            score.output();
            
        }
        if(Home_screen){
            
            window->clear();
            
            SDL_PumpEvents();
            SDL_SetTextInputRect(s);
            window->Render_texture(Back_ground);
            b->draw_button(window);
            c->draw_button(window);

            if(b->isClicked(m)){
                Home_screen = false; 
                Leader_board_screen=true;
                Mix_PauseMusic();
                bgm3.playmusic("music/leaderboard.mp3",-1);
            }
            if(c->isClicked(m)){
                
                Home_screen =false;
                Play_screen=true;
                Play_screen_enemy=true;
                Mix_PauseMusic();
                bgm2.playmusic("music/game.mp3",-1);
            }
            window->display();

        }
        if(Play_screen){
            Uint32 start = SDL_GetTicks();
            window->clear();
            
            
            hero.loadmedia();
            hero.startdisplay();
            if(count ==3){
                hero.cdis(count,degrees,secondselapsed);
                leaderboard final(g->window);
                //we awards points for killing each player;
                final.update_score("C++_project",scoreofplayer);
                Play_screen=false;
                Leader_board_screen=true;

                if(SDL_PollEvent(&event) && event.type == SDL_KEYDOWN){
                    if(event.key.keysym.sym == SDLK_ESCAPE){
                        Play_screen =false;
                        Play_screen_enemy = false;
                        Home_screen=true;
                        hero.destroy();
                        //count=0;
                    }
                }
            }
            else{  
                hero.display(count,degrees,secondselapsed,stop);
                if(SDL_PollEvent(&event) && event.type == SDL_KEYDOWN){
                    if(event.key.keysym.sym == SDLK_ESCAPE){
                        Play_screen =false;
                        Play_screen_enemy = false;
                        Home_screen=true;
                        hero.destroy();
                        count=0;
                        Mix_PauseMusic();
                        bgm1.playmusic("music/mainmenu.mp3",-1);
                    }
                    //cout<<"fortest " <<event.key.keysym.sym<<endl;
                    if(event.key.keysym.sym== SDLK_e){
                        count=0;
                    }
                    if(event.key.keysym.sym== SDLK_q){
                        count=1;
                    }
                    if(event.key.keysym.sym== SDLK_w){
                        count=2;
                    }
                    if(event.key.keysym.sym== SDLK_a){
                        degrees=180;
                    }
                    if(event.key.keysym.sym== SDLK_d){
                        degrees=0;
                    }
                    if(event.key.keysym.sym== SDLK_SPACE){
                        if(stop==false){
                            stop=true;
                        }
                        else if(stop==true){
                            stop=false;
                        }
                    }

                }
                int enemycount=0;
                for(Enemy *e : g->get_enemys()){
                    if(e==g->get_enemys()[0]){
                        enemycount=0;
                    }
                    e->draw_player(g->window,secondselapsed);
                    e->update_position(secondselapsed);
                    SDL_Rect b1=(e->getrect());
                    SDL_Rect b2=hero.getsourcerect();
                    if(SDL_HasIntersection(&b1,&b2)==SDL_TRUE){
                        if(e->getdirection()==0 &&degrees==180){
                            if(hero.ispause()==true){
                                cout<<"hero dies "<<endl;
                                count=3;
                                break;
                            }
                            else {
                                cout<<"enemy dies "<<endl;
                                scoreofplayer++;
                                cout<<"your score is "<<scoreofplayer<<endl;
                                g->removeadd(enemycount);
                                break;
                            }
                        }
                        else if(e->getdirection()==1 &&degrees==0){
                            if(hero.ispause()==true){
                                cout<<"hero dies "<<endl;
                                count=3;
                                break;
                            }
                            else {
                                cout<<"enemy dies "<<endl;
                                //cout<<"enemy dies "<<endl;
                                cout<<"your score is "<<scoreofplayer<<endl;
                                scoreofplayer++;
                                g->removeadd(enemycount);
                                break;
                            }  
                        }
                        else if(e->getdirection()==0 &&degrees==0){
                            cout<<"hero dies back attack "<<endl;
                            count=3;
                            break;
                        }
                        else if(e->getdirection()==1 && degrees ==180){
                            cout<<"hero dies back attack" <<endl;
                            count=3;
                            break;
                        }
                        cout<<"check collison yes" <<endl;
                    }
                    else{
                        cout<<"no collison"<<endl;
                    }
                    enemycount++;
                    //cout<<"direction in main "<<endl <<e->getdirection()<<endl;
                }
            }
            window->display();
            Uint32 end=SDL_GetTicks();
            secondselapsed=(end-start)/1000.0f;
        }
    }
    window->cleanUp();
    IMG_Quit();
    SDL_Quit();

}

int main()
{

    Initilize();
    main_game_loop();
}
