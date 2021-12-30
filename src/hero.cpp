#include "../include/hero.hpp"

LTexture::LTexture(Window* win)

{
	//Initializ
	window=win->get_window();
	gRenderer=win->get_renderer();
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
	
}
LTexture::~LTexture()
{
	//Deallocate
	destroy();
}

void LTexture :: display(int i,int angle){
	cuangle+=angle;
	if(cuangle%360==0){
		right=true;
	}
	else{
		right=false;
	}
	SDL_Surface* backsurface = IMG_Load("../images/Background.jpg");
	background = SDL_CreateTextureFromSurface( gRenderer,backsurface);
	SDL_Surface* image1 =IMG_Load("../images/hulk.png");
	t =SDL_CreateTextureFromSurface(gRenderer,image1);
	SDL_FreeSurface(backsurface);
	SDL_FreeSurface(image1);
	SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
    SDL_RenderClear(gRenderer);
	SDL_RenderCopy(gRenderer, background, NULL, NULL);
	SDL_Rect src ={580,500,200,200};
	if(i<4){
		if(angle==180)
			SDL_RenderCopyEx(gRenderer,t,&clips[i],&src,angle,NULL,SDL_FLIP_VERTICAL);
		else	
			SDL_RenderCopyEx(gRenderer,t,&clips[i],&src,angle,NULL,SDL_FLIP_NONE);
	}
	else if(i<9){
		if(angle==180)
			SDL_RenderCopyEx(gRenderer,t,&clips2[i-5],&src,angle,NULL,SDL_FLIP_VERTICAL);
		else	
			SDL_RenderCopyEx(gRenderer,t,&clips2[i-5],&src,angle,NULL,SDL_FLIP_NONE);
	}
	else if(i<19){
		if(angle==180)
			SDL_RenderCopyEx(gRenderer,t,&clips3[i-15],&src,angle,NULL,SDL_FLIP_VERTICAL);
		else	
			SDL_RenderCopyEx(gRenderer,t,&clips3[i-15],&src,angle,NULL,SDL_FLIP_NONE);
	}
	SDL_RenderPresent(gRenderer);


}
void LTexture:: render(SDL_Texture* tex, SDL_Rect s, SDL_Rect d){
	SDL_RenderCopy(gRenderer,tex,&s,&d);
}
void LTexture:: destroy(){
	SDL_DestroyTexture(background);
	SDL_DestroyTexture(mTexture);
	SDL_DestroyTexture(t);
}




void LTexture:: loadmedia()
{
		clips[ 0 ].x =   0;
		clips[ 0 ].y =   0;
		clips[ 0 ].w =  302;
		clips[ 0 ].h =  286;

		clips[ 1 ].x = 752;
		clips[ 1 ].y =   75;
		clips[ 1 ].w =  248;
		clips[ 1 ].h =  286;
		
		clips[ 2 ].x = 1450;
		clips[ 2 ].y =   60;
		clips[ 2 ].w = 290;
		clips[ 2 ].h = 284;

		clips[ 3 ].x = 1720;
		clips[ 3 ].y = 11;
		clips[ 3 ].w = 243;
		clips[ 3 ].h = 332;

		////////////////////////////////
		clips2[ 0 ].x =   1956;
		clips2[ 0 ].y =   365;
		clips2[ 0 ].w =  248;
		clips2[ 0 ].h =  275;

		clips2[ 1 ].x =   1956;
		clips2[ 1 ].y =   365;
		clips2[ 1 ].w =  248;
		clips2[ 1 ].h =  275;

		clips2[ 2 ].x =   969;
		clips2[ 2 ].y =   363;
		clips2[ 2 ].w =  297;
		clips2[ 2 ].h =  292;

		clips2[ 3 ].x =   1535;
		clips2[ 3 ].y =   398;
		clips2[ 3 ].w =  343;
		clips2[ 3 ].h =  244;
		////////////////////////////////
		clips3[ 0 ].x =   459;
		clips3[ 0 ].y =   1139;
		clips3[ 0 ].w =  266;
		clips3[ 0 ].h =  218;

		clips3[ 1 ].x =   212;
		clips3[ 1 ].y =   1093;
		clips3[ 1 ].w =  257;
		clips3[ 1 ].h =  264;

		clips3[ 2 ].x =   1225;
		clips3[ 2 ].y = 1000;
		clips3[ 2 ].w =  271;
		clips3[ 2 ].h =  357;

		clips3[ 3 ].x =   1504;
		clips3[ 3 ].y =   1135;
		clips3[ 3 ].w =  334;
		clips3[ 3 ].h =  221;


}