#include "model.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>


using namespace std;

// Constructor initializes the object
Model::Model() {
	SDL_Rect pacman;
	pacman.x = 288; pacman.y = 416; pacman.h = 32; pacman.w = 32;
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
}

bool Model::collision(SDL_Rect pac){
	int lefta, leftb, righta, rightb, topa, topb, bottoma, bottomb;
	
	lefta = pac.x;
	righta = pac.x + pac.w;
	topa = pac.y;
	bottoma = pac.y + pac.h;
	
	switch(direction){
		case UP:
		topa += -2;
		for (int i = 0; i < 31; i++){
	leftb = Rect[i].x;
	rightb = Rect[i].x + Rect[i].w;
	topb = Rect[i].y;
	bottomb = Rect[i].y + Rect[i].h;
	if (bottoma > topb && topa < bottomb && righta > leftb && lefta < rightb){
		cout << i << endl;
		return true;
	break;}
}
	return false;
	break;
		case DOWN:
		bottoma += 2;
		for (int i = 0; i < 31; i++){
	leftb = Rect[i].x;
	rightb = Rect[i].x + Rect[i].w;
	topb = Rect[i].y;
	bottomb = Rect[i].y + Rect[i].h;
	if (bottoma > topb && topa < bottomb && righta > leftb && lefta < rightb){
		cout << i << endl;
		return true;
	break;}
		
}
	return false;
	break;
		case RIGHT:
		righta += 2;
		for (int i = 0; i < 31; i++){
	leftb = Rect[i].x;
	rightb = Rect[i].x + Rect[i].w;
	topb = Rect[i].y;
	bottomb = Rect[i].y + Rect[i].h;
	if (bottoma > topb && topa < bottomb && righta > leftb && lefta < rightb){
		cout << i << endl;
		return true;
	break;}
}
	return false;
	break;
		case LEFT:
		lefta += -2;
		for (int i = 0; i < 31; i++){
	leftb = Rect[i].x;
	rightb = Rect[i].x + Rect[i].w;
	topb = Rect[i].y;
	bottomb = Rect[i].y + Rect[i].h;
	if (bottoma > topb && topa < bottomb && righta > leftb && lefta < rightb){
		return true;
		cout << i << endl;
	break;}
}
	return false;
		break;
	}

}

//TODO: make everything go in a direction
void Model::go(Direction d){
	direction = d;
};

//TODO: make pacman move.
//*if next Rect is a barrier, direction is STILL
void Model::move_pac(SDL_Rect &pacman){


	switch(direction) {
    case UP: if (!collision(pacman)){pacman.y += -2;} break;
    case DOWN: if (!collision(pacman)){pacman.y += 2;} break;
    case LEFT: if (!collision(pacman)){pacman.x += -2;} break;
    case RIGHT: if (!collision(pacman)){pacman.x += 2;} break;
    }

	
};


//TODO: detect next tile
void Model::next_spot(SDL_Rect c, Direction last_d){
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
	c1 = ghost; c1.y--; //up
	c2 = ghost; c2.y++; //down
	c3 = ghost; c3.x--; //left
	c4 = ghost; c4.x++; //right
	
	if(c1!=wall){
		path1 = abs (c1.x - pac.x) + abs (c1.y - pac.y);
	}else{
		path1 == 1000;
	}
	if(c2!=wall){
		path = abs (c2.x - pac.x) + abs (c2.y - pac.y);
	}else{
		path2 == 1001;
	}
	if(c3!=wall){
		path3 = abs (c3.x - pac.x) + abs (c3.y - pac.y);
	}else{
		path3 == 1003;
	}
	if(c4!=wall){
		path4 = abs (c4.x - pac.x) + abs (c4.y - pac.y);
	}else{
		path4 == 1004;
	}
	
	
	
	if (next_spot(ghost, d)!= wall){
			//Switch statements to update the ghost Rect
		switch(d) {
			case UP:
			ghost.y--; 
			break;
		case DOWN: 
			ghost.y++; 
			break;
		case LEFT: 
			ghost.x--; 
			break;
		case RIGHT: 
			ghost.x++; 			
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

