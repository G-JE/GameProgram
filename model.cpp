#include "model.h"
#include <cstdlib>
#include <ctime>
#include <cmath>


using namespace std;

// Constructor initializes the object
Model::Model(int w, int h) {
	SDL_Rect pacman;
	width = w;
	height = h;
	
	Rect pacman;
	Direction pac_d;
	Direction ghost_d;
	
	//Initialize ghost as sdl_rect
	Rect ghost1;
	
	ghost1.x = 64;
	ghost1.y = 64;
	ghost.w = 32;
	ghost.h = 32;
	
	pac_d = STILL;
	ghost_d = DOWN;
	
	
}



//TODO: make everything go in a direction
void Model::go(Direction d){
	direction = d;
};

//TODO: make pacman move.
//*if next Rect is a barrier, direction is STILL
void Model::move_pac(SDL_Rect &pacman){

	switch(direction) {
    case UP: pacman.y += -2; break;
    case DOWN: pacman.y += 2; break;
    case LEFT: pacman.x += -2; break;
    case RIGHT: pacman.x += 2; break;
    }

	
};


//TODO: detect next tile
void Model::next_spot(SDL_Rect c, Direction last_d){
void Model::next_spot(Rect c, Direction last_d){
	switch(last_d) {
		case UP:
			c.y--; 
			break;
		case DOWN: 
			c.y++; 
			break;
		case LEFT: 
			c.x--; 
			break;
		case RIGHT: 
			c.x++; 			
			break;
	}
}


//TODO: make the ghosts move relative to pacman
//*if next Rect is barrier, the ghost chooses another direction
void Model::move_ghost(SDL_Rect pac, SDL_Rect &ghost, Direction &d){
	
	int path1, path2, path3, path4;
	SDL_Rect c1,c2,c3,c4;
	
	/*
	//TODO: find shortest path
	c1 = ghost; c1.y - 32; //up
	c2 = ghost; c2.y + 32; //down
	c3 = ghost; c3.x - 32; //left
	c4 = ghost; c4.x + 32; //right
	
	if(!Collision(c1)){
		path1 = abs (c1.x - pac.x) + abs (c1.y - pac.y);
	}else{
		path1 == 10000006;
	}
	if(!Collision(c2)){
		path = abs (c2.x - pac.x) + abs (c2.y - pac.y);
	}else{
		path2 == 10000003;
	}
	if(!Collision(c3)){
		path3 = abs (c3.x - pac.x) + abs (c3.y - pac.y);
	}else{
		path3 == 1000000002;
	}
	if(!Collision(c4)){
		path4 = abs (c4.x - pac.x) + abs (c4.y - pac.y);
	}else{
		path4 == 100000001;
	}
	
	
	
	if (next_spot(ghost, d)!= wall){
			//Switch statements to update the ghost Rect
		switch(d) {
			case UP:
			ghost.y - 32; 
			break;
		case DOWN: 
			ghost.y + 32; 
			break;
		case LEFT: 
			ghost.x - 32; 
			break;
		case RIGHT: 
			ghost.x + 32; 			
			break;
		
		}
	}
	else{
		if (path1 < path2 && path1 < path3 && path1 < path4){
			d = UP;
		}
		if (path2 < path1 && path2 < path3 && path2 < path4){
			d = DOWN;
		}
		if (path3 < path2 && path3 < path1 && path3 < path4){
			d = LEFT;
		}
		else{
			d = RIGHT;
		}
	
	}
	*/
};


// Destructor deletes dynamically allocated memory
Model::~Model() {
}

bool Model::gameOver() {
    return false;
}

