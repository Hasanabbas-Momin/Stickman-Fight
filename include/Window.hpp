#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include<iostream>

using namespace std;


class Window
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;

public:
    Window(const char *title, int w, int h);
    void cleanUp();
};
