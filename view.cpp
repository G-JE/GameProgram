#include "view.h"

using namespace std;
// Initialize Barriers


// Initialize SDL
View::View(string title, int width, int height) {
    fail = false;
    SDL_SetMainReady();
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0) {
        fail = true;
        return;
    }
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        fail = true;
        return;
    }
    // Get the screen
    screen = SDL_GetWindowSurface(window);
    //Initialize JPEG and PNG loading
    if( !( IMG_Init( IMG_INIT_JPG|IMG_INIT_PNG ) & (IMG_INIT_JPG|IMG_INIT_PNG) ) ) {
        fail = true;
        return;
    }
    //Initialize SDL_mixer
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
        fail = true;
        return;
    }

    // Initialize True type fonts
    if( TTF_Init() == -1 ) {
        return;
    }
	
	//initialize Pills
	for (int i = 0; i < 143; i++)
		Pills[i] = NULL;

	//SP initialize
	for (int k = 0; k < 5; k++)
		SPills[k] = NULL;
	
    // Load assets
    Pacmanright = load("assets/pacmanR.png");
	Pacmanleft = load("assets/Lpacman.png");
	Pacmanup = load("assets/Upacman.png");
	Pacmandown = load("assets/Dpacman.png");
	
	SDL_SetColorKey(Pacmanup, SDL_TRUE, SDL_MapRGB(screen->format, 0x00,0x00,0x00));
	SDL_SetColorKey(Pacmanright, SDL_TRUE, SDL_MapRGB(screen->format, 0x00,0x00,0x00));
	SDL_SetColorKey(Pacmanleft, SDL_TRUE, SDL_MapRGB(screen->format, 0x00,0x00,0x00));
	SDL_SetColorKey(Pacmandown, SDL_TRUE, SDL_MapRGB(screen->format, 0x00,0x00,0x00));
	
//    music = Mix_LoadMUS("assets/2Inventions_-_Johaness_Gilther_-_Don_t_leave_me.mp3");
//    if (music != NULL) {
//       Mix_PlayMusic( music, -1 );
//    }
//    food = Mix_LoadWAV("assets/yummy.wav");
    font = TTF_OpenFont( "assets/LiberationSans-Regular.ttf", 28 );
	
Rect[0].x = 0; 		Rect[0].y = 0; 		Rect[0].w = 32; 	Rect[0].h = 640;
Rect[1].x = 32; 	Rect[1].y = 0; 		Rect[1].w = 608; 	Rect[1].h = 32;
Rect[2].x = 0; 		Rect[2].y = 448; 	Rect[2].w = 640; 	Rect[2].h = 32;
Rect[3].x = 608;	Rect[3].y = 32; 	Rect[3].w = 32;		Rect[3].h = 416;
Rect[4].x = 64; 	Rect[4].y = 64; 	Rect[4].w = 32; 	Rect[4].h = 128;
Rect[5].x = 96;		Rect[5].y = 160;	Rect[5].w = 64;		Rect[5].h = 32;
Rect[6].x = 64;		Rect[6].y = 224;	Rect[6].w = 32;		Rect[6].h = 32;
Rect[7].x = 128;	Rect[7].y = 224;	Rect[7].w = 64; 	Rect[7].h = 32;
Rect[8].x = 64;		Rect[8].y = 288;	Rect[8].w = 32;		Rect[8].h = 128;
Rect[9].x = 96;		Rect[9].y = 288;	Rect[9].w = 64; 	Rect[9].h = 32;
Rect[10].x = 128;	Rect[10].y = 352;	Rect[10].w = 96; 	Rect[10].h = 64;
Rect[11].x = 128;	Rect[11].y = 64;	Rect[11].w = 96; 	Rect[11].h = 64;
Rect[12].x = 192;	Rect[12].y = 160;	Rect[12].w = 32; 	Rect[12].h = 160;
Rect[13].x = 224;	Rect[13].y = 160;	Rect[13].w = 64; 	Rect[13].h = 32;
Rect[14].x = 224;	Rect[14].y = 288;	Rect[14].w = 192; 	Rect[14].h = 32;
Rect[15].x = 256;	Rect[15].y = 352;	Rect[15].w = 32; 	Rect[15].h = 96;
Rect[16].x = 256; 	Rect[16].y = 64; 	Rect[16].w = 64; 	Rect[16].h = 64;
Rect[17].x = 288; 	Rect[17].y = 128; 	Rect[17].w = 32; 	Rect[17].h = 64;
Rect[18].x = 320; 	Rect[18].y = 320; 	Rect[18].w = 32; 	Rect[18].h = 32;
Rect[19].x = 320; 	Rect[19].y = 352; 	Rect[19].w = 64; 	Rect[19].h = 64;
Rect[20].x = 352; 	Rect[20].y = 32; 	Rect[20].w = 32; 	Rect[20].h = 96;
Rect[21].x = 352; 	Rect[21].y = 160; 	Rect[21].w = 96; 	Rect[21].h = 32;
Rect[22].x = 416; 	Rect[22].y = 192; 	Rect[22].w = 32; 	Rect[22].h = 128;
Rect[23].x = 416; 	Rect[23].y = 352; 	Rect[23].w = 96; 	Rect[23].h = 64;
Rect[24].x = 416; 	Rect[24].y = 64; 	Rect[24].w = 96; 	Rect[24].h = 64;
Rect[25].x = 480; 	Rect[25].y = 160; 	Rect[25].w = 64; 	Rect[25].h = 32;
Rect[26].x = 448; 	Rect[26].y = 224; 	Rect[26].w = 64; 	Rect[26].h = 32;
Rect[27].x = 480; 	Rect[27].y = 288; 	Rect[27].w = 96; 	Rect[27].h = 32;
Rect[28].x = 544; 	Rect[28].y = 320; 	Rect[28].w = 32; 	Rect[28].h = 96;
Rect[29].x = 544; 	Rect[29].y = 224; 	Rect[29].w = 32; 	Rect[29].h = 32;
Rect[30].x = 544; 	Rect[30].y = 64; 	Rect[30].w = 32; 	Rect[30].h = 128;

//SP locations
	SPloc[0].x = 32;	SPloc[0].y = 416;
	SPloc[1].x = 96;	SPloc[1].y = 128;
	SPloc[2].x = 416;	SPloc[2].y = 128;
	SPloc[3].x = 576;	SPloc[3].y = 32;
	SPloc[4].x = 576;	SPloc[4].y = 320;
	
	middle.x = 224;		middle.y = 192;		middle.h = 96;		middle.w = 192;
	middle2.x = 320;	middle2.y = 160;	middle2.w = 32;		middle2.h = 32;
	checkblock.h = 32;	checkblock.w = 32;	checkblock.x = 0;	checkblock.y = 0;
	pacinit.x = 288;	pacinit.y = 416; 	pacinit.w = 32; 	pacinit.h = 32;
	offset.x = 0;		offset.y = 0;
	
	n = 0;
}

bool View::Collision(SDL_Rect a, SDL_Rect b){
	int lefta, leftb, righta, rightb, topa, topb, bottoma, bottomb;

	lefta = a.x;
	righta = a.x + a.w;
	topa = a.y;
	bottoma = a.y + a.h;

	leftb = b.x;
	rightb = b.x + b.w;
	topb = b.y;
	bottomb = b.y + b.h;

	if (bottoma <= topb || topa >= bottomb || righta <= leftb || lefta >= rightb)
		return false;
	else 
		return true;
}

View::~View() {
    SDL_DestroyWindow(window);
	SDL_FreeSurface(Pacmanright);
	SDL_FreeSurface(Pacmanleft);
	SDL_FreeSurface(Pacmanup);
	SDL_FreeSurface(Pacmandown);
	
	for (int p = 0; p < 143; p++)
	SDL_FreeSurface(Pills[p]);

	SDL_FreeSurface(background);
	
	for(int sp = 0; sp < 5; sp++ )
	SDL_FreeSurface(SPills[sp]);
    IMG_Quit();
    SDL_Quit();
}

/**
 *  Load an image from a file to a SDL_Surface
 */
SDL_Surface* View::load(char * path) {
    // Load image
    SDL_Surface* optimizedSurface = NULL;
    SDL_Surface* loadedSurface = IMG_Load( path );
    if( loadedSurface == NULL ) {
        return NULL;
    }
    // Convert surface to screen format
    optimizedSurface = SDL_ConvertSurface( loadedSurface, screen->format, 0 );
    
    // Get rid of old loaded surface
    SDL_FreeSurface( loadedSurface );
    return optimizedSurface;
}

void View::show(Model * model, SDL_Rect &pacdest, SDL_Event e) {

	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format,
        0x00, 0x00, 0x00));
	SDL_FillRect(screen, &pacdest, SDL_MapRGB(screen->format,
        0x00, 0x00, 0x00));
		
	background = load("assets/background.jpg");
	SDL_BlitSurface(background, NULL, screen, NULL);
		int p = 0;
		offset.x = 0;		offset.y = 0;
		checkblock.x = 0;	checkblock.y = 0;
	
	for (int x = 0; x < 19; x++){
		checkblock.y = 0;
		offset.y = 0;
		for (int y = 0; y < 14; y++){
			for (int b = 0; b < 31; b++){
			if (Collision(checkblock, Rect[b]) || Collision(checkblock, middle)
				|| Collision(checkblock, middle2) || Collision(pacinit, checkblock)){
				break;
				}
			if (b == 30 && !Collision(checkblock, Rect[b]) && !Collision(checkblock, middle)
				&& !Collision(checkblock, middle2) && !Collision(pacinit, checkblock)){
				Pills[p] = load("assets/pill.png"); // loads image to surface
				SDL_SetColorKey(Pills[p], SDL_TRUE, SDL_MapRGB(screen->format,0x00,0x00,0x00)); // sets black to transparent
				SDL_BlitSurface(Pills[p], NULL, screen, &offset); // prints pill
				p++;
				}
			}
			checkblock.y += 32;
			offset.y += 32;
		}
		checkblock.x += 32;
		offset.x += 32;
	}
	
	if (n == 0){
		SDL_BlitSurface(Pacmanright, NULL, screen, &pacdest);
	}
	for (int m = 0; m < 5; m++){
		SPills[m] = load("assets/Superpill.png");
		SDL_SetColorKey(SPills[m], SDL_TRUE, SDL_MapRGB(screen->format,0x00,0x00,0x00));
		SDL_BlitSurface(SPills[m], NULL, screen, &SPloc[m]);
	}
    // Probably call SDL_FillRect or SDL_BlitSurface a bunch here :-)
    SDL_UpdateWindowSurface(window);

	switch(e.key.keysym.sym) {
    case SDLK_UP:
	//SDL_SetColorKey(Pacmanup, SDL_TRUE, SDL_MapRGB(screen->format, 0x00,0x00,0x00));
	SDL_BlitSurface(Pacmanup, NULL, screen, &pacdest);
    // Probably call SDL_FillRect or SDL_BlitSurface a bunch here :-)
    SDL_UpdateWindowSurface(window);
	break;
    case SDLK_DOWN: 
	//SDL_SetColorKey(Pacmandown, SDL_TRUE, SDL_MapRGB(screen->format, 0x00,0x00,0x00));
	SDL_BlitSurface(Pacmandown, NULL, screen, &pacdest);
    // Probably call SDL_FillRect or SDL_BlitSurface a bunch here :-)
    SDL_UpdateWindowSurface(window); 
	break;
    case SDLK_LEFT:
	//SDL_SetColorKey(Pacmanleft, SDL_TRUE, SDL_MapRGB(screen->format, 0x00,0x00,0x00));
	SDL_BlitSurface(Pacmanleft, NULL, screen, &pacdest);
    // Probably call SDL_FillRect or SDL_BlitSurface a bunch here :-)
    SDL_UpdateWindowSurface(window);
	break;
    case SDLK_RIGHT:
	//SDL_SetColorKey(Pacmanright, SDL_TRUE, SDL_MapRGB(screen->format, 0x00,0x00,0x00));
	SDL_BlitSurface(Pacmanright, NULL, screen, &pacdest);
    // Probably call SDL_FillRect or SDL_BlitSurface a bunch here :-)
    SDL_UpdateWindowSurface(window); 
	break;
	}
	n++;
  }

