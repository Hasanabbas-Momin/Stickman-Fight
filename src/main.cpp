#include"../include/Window.hpp"
#include"../include/Button.hpp"
#include"../include/Mouse.hpp"
#include"../include/leaderboard.hpp"
#include"../include/hero.hpp"
#include"../include/Enemy.hpp"
#include<vector>


 // Initilizes the sdl Library
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
void play_enemy(vector<Enemy*> elist,Window* window){

    for(int i = 0; i < elist.size() ;i++){
            Enemy* e =elist[i];
            e->gettexture();
            e->draw_player(0.11);
            e->update_position(0.11);
            window->display();
    }
}
Enemy * update_elist( Window* window){
    Enemy * n;
    n= new Enemy(window);
    n->changecount(0,/*rand()%2-1*/0);
    return n;
}
void main_game_loop(){
    // Main game loop 
    Window *window = new Window("Stickman-Fight", 1280, 720);
    bool gameRunning = true;
    SDL_Event event;
    const int FPS =40;
    const int framedelay = 10000/FPS;
    Uint32 frameStart ,frameend;
    Uint32 start,end;
    int frametime;
    float secondselapsed=0;
    // Loding the images
    SDL_Texture *Back_ground = (window->loadTexture("../images/back.jpg"));
    Button *b = new Button(1100,620,100,100,"../images/lead.png");
    Button *c = new Button(600,280,100,100,"../images/play.png");


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
    bool Play_screen_enemy = false;
    bool Leader_board_screen = false; 
    bool Exit_screen = false;

    int count=0;
    int degrees=0;
    vector <Enemy*> elist;
    
    Enemy* en;
    en= new Enemy(window);
    elist.push_back(en);
    elist[0]->changecount(0,0);
    Enemy w(window);
    while (gameRunning)
    {   
        frameStart = SDL_GetTicks();
        cout << m->get_mouse_x() << " " <<  m->get_mouse_y() << endl;
        if(SDL_PollEvent(&event) && event.type == SDL_QUIT)
            gameRunning = false;
        
        

        if(Leader_board_screen){
            leaderboard score(window);
            score.output();
            if(SDL_PollEvent(&event) && event.type == SDL_KEYDOWN){
                if(event.key.keysym.sym == SDLK_ESCAPE){
                    Leader_board_screen =false;
                    Home_screen=true;
                    score.destroy();
                }
            }
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
            //Play_screen = true;
                Leader_board_screen=true;
            }
            if(c->isClicked(m)){
                
                Home_screen =false;
                Play_screen=true;
                Play_screen_enemy=true;
            }
            window->display();

        }
        if(Play_screen){
        
            if(framedelay > frameend-frameStart){
                SDL_Delay(framedelay-(frameend-frameStart));
            }
            if(count==4){
                count=0;
            }
            if(count==9){
                count=5;
            }
            if(count==19){
                count=15;
            }
            window->clear();
            
            LTexture hero(window);
            
            hero.loadmedia();
            hero.display(count,degrees);
            count++;
            if(SDL_PollEvent(&event) && event.type == SDL_KEYDOWN){
                if(event.key.keysym.sym == SDLK_ESCAPE){
                    Play_screen =false;
                    Play_screen_enemy = false;
                    Home_screen=true;
                    hero.destroy();
                    while(!elist.empty()){
                        elist.pop_back();
                    }
                }
                if(event.key.keysym.sym== SDLK_e){
                    count=0;
                }
                if(event.key.keysym.sym== SDLK_q){
                    count=5;
                }
                if(event.key.keysym.sym== SDLK_w){
                    count=15;
                }
                if(event.key.keysym.sym== SDLK_a){
                    degrees=180;
                }
                if(event.key.keysym.sym== SDLK_d){
                    degrees=0;
                }

            }
            window->display();
        }
        if(Play_screen_enemy){
            if(elist[0]->getdirection()==0){
                if((elist[0]->getposx())>=420 && (elist[0]->getposx())<=450){
                    if(elist.size()<10)
                        elist.push_back((update_elist(window)));
                }
            }
            else{
                if((elist[0]->getposx())>=800 && (elist[0]->getposx())<=900){
                    if(elist.size()<1)
                        elist.push_back((update_elist(window)));
                }
            }
            cout<<endl<<elist.size()<<endl;
            play_enemy(elist,window);
            
        }
        frameend=SDL_GetTicks();
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
