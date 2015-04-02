
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include "model.h"
#include <map>
#include <string>

#ifndef _VIEW_H
#define _VIEW_H



// Show (output) the state of the model
class View {
public:
    View(std::string title, int width, int height);
    ~View();
    // Print out the visible stuff in the grid
    void show(Model * model, SDL_Rect &pacdest, SDL_Event e);
private:
	bool Collision(SDL_Rect a, SDL_Rect b);
	SDL_Surface* background;
	SDL_Rect SPloc[5];
	SDL_Rect Rect[31];
	SDL_Surface* Pills[143];
	SDL_Surface* SPills[5];
	SDL_Rect checkblock, offset, middle, middle2, pacinit, ghost_init;
    SDL_Window* window;
    SDL_Surface* screen;
    bool fail;
    SDL_Surface* load(char * path);
    SDL_Surface* Pacmanright;
	SDL_Surface* Pacmanleft;
	SDL_Surface* Pacmanup;
	SDL_Surface* Pacmandown;
	SDL_Surface* Ghost;
	
//    Mix_Music * music;
//    Mix_Chunk * food;
    TTF_Font * font;
};
#endif