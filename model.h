#ifndef _MODEL_H
#define _MODEL_H

enum State { RUN, SEEK };
enum Direction { UP, DOWN, LEFT, RIGHT, STILL };

typedef struct{
	int x;
	int y;
} Coordinate;

// The model manages the state of the game
class Model {
public:
    // Constructor (instantiates object)
    Model();
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
	Coordinate pacman;
	// ghosts 
	Coordinate ghost1;
	Coordinate ghost2;
	
	
	
	Direction last_d;
	// big food pill
	
private:
	int score;
};

#endif