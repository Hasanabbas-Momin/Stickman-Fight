#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

class Window
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;

public:
    Window(const char *title, int w, int h)
    {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            cout << "Window failed to init ERROR:" << SDL_GetError() << endl;
        }
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }
    void cleanUp()
    {
        SDL_DestroyWindow(window);
    }
};

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        cout << "SDL_init has failed ERROR:" << SDL_GetError() << endl;
    }
    if (!(IMG_Init(IMG_INIT_JPG)))
    {
        cout << "IMG-init has failed ERROR:" << SDL_GetError() << endl;
    }

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
    return 0;
}
