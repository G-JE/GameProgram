#ifndef _MODEL_H
#define _MODEL_H

enum State { RUN, SEEK };
enum Direction { UP, DOWN, LEFT, RIGHT, STILL, DEAD };

typedef SDL_Rect Rect;

// The model manages the state of the game
class Model {
public:
    // Constructor (instantiates object)
    Model(int w, int h);
    // Destructor deletes all dynamically allocated stuff
    ~Model();
    // Is the game over?
    bool gameOver();
	//Make the object move
	void go(Direction d);
	// Move (if the next spot is a wall d = STILL)
	void move_pac();
	// Move the ghosts (if the next spot is a wall, switch direction)
	void move_ghost(Coordinate pac, Coordinate &ghost, Direction &d);
	//Next spot detection
	void next_spot(Coordinate c, Direction last_d);
	
    // instantiate objects
	Rect pacman;
	// ghosts 
	Rect ghost1;
	Rect ghost2;
	
	Direction pac_d;
	Direction ghost_d;
	Direction last_d;
	// big food pill
	
private:
	int score;
};

#endif