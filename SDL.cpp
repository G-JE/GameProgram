#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

using namespace std;
bool init(SDL_Window*& window, SDL_Surface*& screen, int width, int height){

if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0){
	return false;
}
window = SDL_CreateWindow("PACMAN", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
	width, height, SDL_WINDOW_SHOWN);
if (window == NULL){
		return false;
	}
screen = SDL_GetWindowSurface(window);
	//jpg and png loading initializer
if(!(IMG_Init( IMG_INIT_JPG|IMG_INIT_PNG) & (IMG_INIT_JPG|IMG_INIT_PNG))){
	return false;
}
return true;
}



void close(SDL_Window* window){

	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
}

SDL_Surface* load(SDL_Surface*& screen, string path){
	SDL_Surface* optimizedSurface = NULL;
	SDL_Surface* LoadedSurface = IMG_Load(path.c_str());
	if (LoadedSurface == NULL){
		return NULL;
	}
	optimizedSurface = SDL_ConvertSurface(LoadedSurface, screen->format, 0);
	SDL_FreeSurface(LoadedSurface);
	return optimizedSurface;
}

bool Collision(SDL_Rect a, SDL_Rect b){
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


int main(int argc, char* argv[]){
	SDL_Window* window = NULL;
	SDL_Surface* screen = NULL;
	SDL_Surface* background = NULL;

	SDL_Rect SPloc[5];
	SDL_Rect Rect[31];

	// Initialize surface for each Super pill
	SDL_Surface* SPills[5];
	for (int k = 0; k < 5; k++)
		SPills[k] = NULL;

	// Initialize a surface for each pill
	SDL_Surface* Pills[143];
	for (int i = 0; i < 143; i++)
		Pills[i] = NULL;

//Super pill locations
	SPloc[0].x = 32;	SPloc[0].y = 416;
	SPloc[1].x = 96;	SPloc[1].y = 128;
	SPloc[2].x = 416;	SPloc[2].y = 128;
	SPloc[3].x = 576;	SPloc[3].y = 32;
	SPloc[4].x = 576;	SPloc[4].y = 320;

// Border (in 640 x 480 pixel window)
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


	if(!init(window, screen, 640, 480)){
		cout << "Could not initialize Window" << endl;
		return 1;
	}

	// Setting collision blocks
	SDL_Rect checkblock, offset, middle, middle2, pacinit;

	middle.x = 224;		middle.y = 192;		middle.h = 96;		middle.w = 192;
	middle2.x = 320;	middle2.y = 160;	middle2.w = 32;		middle2.h = 32;
	checkblock.h = 32;	checkblock.w = 32;	checkblock.x = 0;	checkblock.y = 0;
	pacinit.x = 288;	pacinit.y = 416; 	pacinit.w = 32; 	pacinit.h = 32;
	offset.x = 0;		offset.y = 0;


	int p = 0;

	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0x22,0x02,0x49));
	
	//for (int i = 0; i < 31; i++){
	//	SDL_FillRect(screen, &Rect[i], SDL_MapRGB(screen->format, 0x00,0x00,0x00));
	//}
	background = load(screen, "background.jpg");
	SDL_BlitSurface(background, NULL, screen, NULL);

	// Pill drawing loop
	for (int x = 0; x < 20; x++){
		checkblock.y = 0;
		offset.y = 0;
		for (int y = 0; y < 15; y++){
			for (int b = 0; b < 31; b++){
			if (Collision(checkblock, Rect[b]) || Collision(checkblock, middle)
				|| Collision(checkblock, middle2) || Collision(pacinit, checkblock)){
				break;
				}
			if (b == 30 && !Collision(checkblock, Rect[b]) && !Collision(checkblock, middle)
				&& !Collision(checkblock, middle2) && !Collision(pacinit, checkblock)){
				Pills[p] = load(screen, "new.png"); // loads image to surface
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

	for (int m = 0; m < 5; m++){
		SPills[m] = load(screen, "Superpills.png");
		SDL_SetColorKey(SPills[m], SDL_TRUE, SDL_MapRGB(screen->format,0x00,0x00,0x00));
		SDL_BlitSurface(SPills[m], NULL, screen, &SPloc[m]);
	}
	//Pill = load(screen, "pills.jpg");
	//SDL_BlitSurface(Pill, NULL, screen, &offset);

	SDL_UpdateWindowSurface(window);

	SDL_Delay(20000);

	close(window);
	return 0;
}