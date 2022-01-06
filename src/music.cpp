#include"../include/music.hpp"
music::music(){
    SDL_Init(SDL_INIT_AUDIO);
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048)<0){
        cout<<"Error: "<<Mix_GetError()<<endl;
    }
}
void music::playmusic(const char* p,int loop){
    Mix_Music* m=Mix_LoadMUS(p);
    if(m==NULL){
        cout<<Mix_GetError();

    }
    Mix_PlayMusic(m,-1);
}