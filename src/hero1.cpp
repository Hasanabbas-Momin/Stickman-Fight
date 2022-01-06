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


void LTexture:: startdisplay(){
	SDL_Surface* backsurface = IMG_Load("images/Background.jpg");
	background = SDL_CreateTextureFromSurface( gRenderer,backsurface);
	SDL_Surface* image1 =IMG_Load("images/hulk.png");
	t =SDL_CreateTextureFromSurface(gRenderer,image1);
	SDL_FreeSurface(backsurface);
	SDL_FreeSurface(image1);
	SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
    SDL_RenderClear(gRenderer);
	SDL_RenderCopy(gRenderer, background, NULL, NULL);
	//SDL_RenderPresent(gRenderer);
}
void LTexture:: cdis (int i, int angle ,float secondselapsed ){
    dest=animate(secondselapsed,i);
    if(angle==180){
        SDL_RenderCopyEx(gRenderer,t,&dest,&src,angle,NULL,SDL_FLIP_VERTICAL);
        SDL_RenderPresent(gRenderer);
    }
        
    else{
        SDL_RenderCopyEx(gRenderer,t,&dest,&src,angle,NULL,SDL_FLIP_NONE);
        SDL_RenderPresent(gRenderer);
    }

}
void LTexture :: display(int i,int angle, float secondselapsed, bool stop){
    int c=cpaused();
    //cout<<"value from paused " <<c<<endl;
    if(c==1 || stop==true){
       if(angle==180){
            SDL_RenderCopyEx(gRenderer,t,&clips[0],&src,angle,NULL,SDL_FLIP_VERTICAL);
            SDL_RenderPresent(gRenderer);
        }
            
        else{
            SDL_RenderCopyEx(gRenderer,t,&clips[0],&src,angle,NULL,SDL_FLIP_NONE);
            SDL_RenderPresent(gRenderer);
        }
        if(stop==false) {
            count2+=secondselapsed;
        }
        gamepause=true;
            

    }
    else if(c ==0){
        if(i==0){
            dest=animate(secondselapsed,0);
            if(angle==180){
                SDL_RenderCopyEx(gRenderer,t,&dest,&src,angle,NULL,SDL_FLIP_VERTICAL);
                SDL_RenderPresent(gRenderer);
            }
                
            else{
                SDL_RenderCopyEx(gRenderer,t,&dest,&src,angle,NULL,SDL_FLIP_NONE);
                SDL_RenderPresent(gRenderer);
            }
        }
        if(i==1){
            dest=animate(secondselapsed,1);
            if(angle==180){
                SDL_RenderCopyEx(gRenderer,t,&dest,&src,angle,NULL,SDL_FLIP_VERTICAL);
                SDL_RenderPresent(gRenderer);
            }
                
            else{
                SDL_RenderCopyEx(gRenderer,t,&dest,&src,angle,NULL,SDL_FLIP_NONE);
                SDL_RenderPresent(gRenderer);
            }
        }
        if(i==2){
            dest=animate(secondselapsed,2);
            if(angle==180){
                SDL_RenderCopyEx(gRenderer,t,&dest,&src,angle,NULL,SDL_FLIP_VERTICAL);
                SDL_RenderPresent(gRenderer);
            }
                
            else{
                SDL_RenderCopyEx(gRenderer,t,&dest,&src,angle,NULL,SDL_FLIP_NONE);
                SDL_RenderPresent(gRenderer);
            }
        }
        if(i==3){
            dest=animate(secondselapsed,3);
            if(angle==180){
                SDL_RenderCopyEx(gRenderer,t,&dest,&src,angle,NULL,SDL_FLIP_VERTICAL);
                SDL_RenderPresent(gRenderer);
            }
                
            else{
                SDL_RenderCopyEx(gRenderer,t,&dest,&src,angle,NULL,SDL_FLIP_NONE);
                SDL_RenderPresent(gRenderer);
            }
        }
        gamepause=false;
   }
	


}
SDL_Rect LTexture:: getsourcerect(){
    return src;
}
void LTexture:: render(SDL_Texture* tex, SDL_Rect s, SDL_Rect d){
	SDL_RenderCopy(gRenderer,tex,&s,&d);
}
void LTexture:: destroy(){
	SDL_DestroyTexture(background);
	SDL_DestroyTexture(mTexture);
	SDL_DestroyTexture(t);
}

int LTexture:: getdestx(){
	return destx;
}
 
SDL_Rect LTexture:: animate( float secondselapsed ,int i){
    if(i==0){
        if(count < 1*animation_time){
            dest = (clips[0]);
        }

        else if((count >= 1*animation_time) && (count < 2*animation_time)){
            dest = (clips[1]);
        }

        else if((count >= 2*animation_time) && (count < 3*animation_time)){
            dest =(clips[2]);
        }

        else if((count >= 3*animation_time) && (count < 4*animation_time)){
            dest = (clips[3]);
        }
        else if(count > 4* animation_time){
            count=0;
        }
    }
    else if( i==1){
        if(count < 1*animation_time){
            dest = (clips2[0]);
        }

        else if((count >= 1*animation_time) && (count < 2*animation_time)){
            dest = (clips2[1]);
        }

        else if((count >= 2*animation_time) && (count < 3*animation_time)){
            dest =(clips2[2]);
        }

        else if((count >= 3*animation_time) && (count < 4*animation_time)){
            dest = (clips2[3]);
        }
        else if(count > 4* animation_time){
            count=0;
        }
    }
    else if(i==2){
        if(count < 1*animation_time){
            dest = (clips3[0]);
        }

        else if((count >= 1*animation_time) && (count < 2*animation_time)){
            dest = (clips3[1]);
        }

        else if((count >= 2*animation_time) && (count < 3*animation_time)){
            dest =(clips3[2]);
        }

        else if((count >= 3*animation_time) && (count < 4*animation_time)){
            dest = (clips3[3]);
        }
        else if(count > 4* animation_time){
            count=0;
        }
    }
    else if(i==3){
        if(count < 1*animation_time){
            dest = (clips4[0]);
        }

        else if((count >= 1*animation_time) && (count < 2*animation_time)){
            dest = (clips4[1]);
        }

        else if((count >= 2*animation_time) && (count < 3*animation_time)){
            dest =(clips4[2]);
        }

        else if((count >= 3*animation_time) && (count < 4*animation_time)){
            dest = (clips4[3]);
        }
        else if(count > 4* animation_time){
            count=0;
        }
    }
    count +=secondselapsed;
    //cout<<"count =" <<count<<endl;
    //countpaused =countpaused+ secondselapsed;
    count2 +=secondselapsed;
    //cout<<"countpaused == " <<count2<<endl;
    return dest;
    
}
int LTexture:: cpaused(){
    //cout <<count2 <<endl;
    if(count2 >15*animation_time && flag==1){
        flag=0;
        return 1;
    }
    else if(count2 > 25*animation_time && flag==0){
        count2=0;
        flag=1;
        return 0;
    }
    else if(count2<15*animation_time ){
        return 0;
    }
    else{
        return 1;
    }
    //return 0;
}

bool LTexture::ispause(){
    return gamepause;
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
        ////////////////////////////////
        clips4[ 0 ].x =305;
        clips4[ 0 ].y =12;
        clips4[ 0 ].w =399;
        clips4[ 0 ].h =375;

        clips4[ 1 ].x =305;
        clips4[ 1 ].y =12;
        clips4[ 1 ].w =399;
        clips4[ 1 ].h =375;

        clips4[ 2 ].x =305;
        clips4[ 2 ].y =12;
        clips4[ 2 ].w =399;
        clips4[ 2 ].h =375;

        clips4[ 3 ].x =305;
        clips4[ 3 ].y =12;
        clips4[ 3 ].w =399;
        clips4[ 3 ].h =375;
        


}
