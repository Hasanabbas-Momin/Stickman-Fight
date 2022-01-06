#include"../include/leaderboard.hpp"

void leaderboard::output(){
    fstream f;
    f.open("data/Data.txt");
    int n;
    f>>n;
    f.close();
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    /* Use TTF textures. */
    SDL_RenderCopy(renderer, back_tex, NULL, NULL);

    for (int i = 0; i < n; i++) {
        SDL_RenderCopy(renderer, tex_name_background[i], NULL, &rect_name_back[i]);
        SDL_RenderCopy(renderer, texture[i], NULL, &rect[i]);
        SDL_RenderCopy(renderer, tex_score[i], NULL, &rect_score[i]);
        SDL_RenderCopy(renderer, tex_face[i], NULL, &rect_face[i]);
        if (i < 3) {
            SDL_RenderCopy(renderer, tex_top[i], NULL, &rect_top[i]);
        }
    }
   
    

    SDL_RenderCopy(renderer, tex_for_escape, NULL, &rect_for_escape);
    SDL_RenderPresent(renderer);
}



void leaderboard::update_score(string player_name, int player_score) {
    fstream file;
    file.open("data/Data.txt");
    file >> number_of_players;
    vector<pair<int, string>> game(number_of_players + 1);
    for (int i = 0; i < number_of_players; i++) {
        int score;
        string name;
        file >> game[i].second >> game[i].first;
    }
    file.close();
    file.open("data/Data.txt", ios::trunc | ios::out | ios::in);
    game[number_of_players].second = player_name;
    game[number_of_players].first = player_score;
    if (number_of_players < 10) {
        number_of_players++;
    }
    file << number_of_players << endl;
    for (int i = 0; i < game.size(); i++) {
        for (int j = i + 1; j < game.size(); j++) {
            if (game[i].first < game[j].first) {
                pair<int, string> temp;
                temp = game[j];
                game[j] = game[i];
                game[i] = temp;
            }
        }
    }
    for (int i = 0; i < game.size() && i < 10; i++) {
        file << game[i].second << " " << game[i].first << endl;
    }
    file.close();
}




void leaderboard::get_text_and_rect(SDL_Renderer* renderer, int x, int y, char* text,
    TTF_Font* font, SDL_Texture** texture, SDL_Rect* rect) {
    int text_width;
    int text_height;
    SDL_Surface* surface;
    SDL_Color textColor = { 255, 255, 255, 0 };

    surface = TTF_RenderText_Solid(font, text, textColor);
    *texture = SDL_CreateTextureFromSurface(renderer, surface);
    text_width = surface->w;
    text_height = surface->h;
    SDL_FreeSurface(surface);
    rect->x = x;
    rect->y = y;
    rect->w = text_width;
    rect->h = text_height;
}


void leaderboard::display_score() {

    SDL_Event event;
    SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO);
 
    if (IMG_Init(IMG_INIT_PNG) == 0) {
        cout << "error sdl2_img";
    }
    SDL_Surface* back_surface = IMG_Load("images/main.png");
    SDL_Surface* face_surface = IMG_Load("images/face.png");
    SDL_Surface* name_surface = IMG_Load("images/name.png");


    SDL_Surface* top[3];
    top[0] = IMG_Load("images/first.png");
    top[1] = IMG_Load("images/second.png");
    top[2] = IMG_Load("images/third.png");

    back_tex = SDL_CreateTextureFromSurface(renderer, back_surface);
    for (int i = 0; i < 10; i++) {
        tex_face[i] = SDL_CreateTextureFromSurface(renderer, face_surface);
        tex_name_background[i] = SDL_CreateTextureFromSurface(renderer, name_surface);
        rect_name_back[i].x = 320;
        rect_name_back[i].y = 196 + i * 35;
        rect_name_back[i].w = 600;
        rect_name_back[i].h = 30;
        rect_face[i].x = 280;
        rect_face[i].y = 195 + i * 35;
        rect_face[i].w = rect_face[i].h = 30;
        if (i < 3) {
            tex_top[i] = SDL_CreateTextureFromSurface(renderer, top[i]);
            SDL_FreeSurface(top[i]);
            rect_top[i].y = 190 + i * 35;
            rect_top[i].w = rect_top[i].h = 35;
            rect_top[i].x = 230;
        }
    }
   
    SDL_FreeSurface(back_surface);
    SDL_FreeSurface(face_surface);
    SDL_FreeSurface(name_surface);

    char* player_names[10];
    char* scores[10];
   
    fstream file;
    int number_of_players;
    file.open("data/Data.txt");
    file >> number_of_players;
    vector<pair<string, string>> players(number_of_players);
    for (int i = 0; i < number_of_players; i++) {
        file >> players[i].first >> players[i].second;
        player_names[i] = const_cast<char*>(players[i].first.c_str());
        scores[i] = const_cast<char*>(players[i].second.c_str());
    }
    file.close();


    int quit;

   
    TTF_Init();
    TTF_Font* font = TTF_OpenFont("font/cha.ttf", 24);
    if (font == NULL) {
        fprintf(stderr, "error: font not found\n");
        exit(EXIT_FAILURE);
    }
    
    SDL_Texture* tex;
    SDL_Rect rectangle;
    char* espace_statement = (char*)"PRESS ESC TO GO TO MAIN MENU";
    SDL_Texture* tex_for_escape;
    SDL_Rect rect_for_escape;
    get_text_and_rect(renderer, 0, 0, espace_statement, font, &tex_for_escape, &rect_for_escape);
    get_text_and_rect(renderer, 340, 200, player_names[0], font, &texture[0], &rect[0]);
    get_text_and_rect(renderer, 800, 200, scores[0], font, &tex_score[0], &rect_score[0]);

    for (int i = 1; i < number_of_players; i++) {
        get_text_and_rect(renderer, 340, rect[i - 1].y + rect[i - 1].h + 12, player_names[i], font, &texture[i], &rect[i]);
        get_text_and_rect(renderer, 800, rect_score[i - 1].y + rect_score[i - 1].h + 12, scores[i], font, &tex_score[i], &rect_score[i]);
    }


    
  
}
void leaderboard::destroy() {
    SDL_DestroyTexture(back_tex);
    for (int i = 0; i < number_of_players; i++) {
        SDL_DestroyTexture(tex_face[i]);
        SDL_DestroyTexture(texture[i]);
        SDL_DestroyTexture(tex_score[i]);
        SDL_DestroyTexture(tex_name_background[i]);
        if (i < 3) {
            SDL_DestroyTexture(tex_top[i]);
        }
    }
}
