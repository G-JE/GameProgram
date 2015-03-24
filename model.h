#ifndef _MODEL_H
#define _MODEL_H

enum Direction { UP, DOWN, LEFT, RIGHT };

typedef struct {
    unsigned int x;
    unsigned int y;
} Coordinate;

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
    // TODO: Put your stuff here
	Coordinate Pacman;
	Direction direction;
};

#endif