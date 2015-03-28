#ifndef _MODEL_H
#define _MODEL_H
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

enum State { RUN, SEEK };
enum Direction { UP, DOWN, LEFT, RIGHT, STILL };


typedef struct {
    SDL_Rect object;
	int x;
	int y;
	
   
} Rect;

// The model manages the state of the game
class Model {
public:
    // Constructor (instantiates object)
    Model();
    // Destructor deletes all dynamically allocated stuff
    ~Model();
	void go(Direction d);
	void move();
    // Is the game over?
    bool gameOver();
	//Make the object move
	// Move (if the next spot is a wall d = STILL)
	Direction direction;
	void move_pac(SDL_Rect &pacman);
	// Move the ghosts (if the next spot is a wall, switch direction)
	void move_ghost(Rect pac, Rect &ghost, Direction &d);
	//Next spot detection
	void next_spot(Rect c, Direction last_d);
	
    // instantiate objects
	Rect pacman;
	// ghosts 
	Rect ghost1;
	Rect ghost2;
	
	
	
	Direction last_d;
	// big food pill
	
private:
	int score;
};

#endif