#include "model.h"
#include <cstdlib>
#include <ctime>

using namespace std;

// Constructor initializes the object
Model::Model() {

}
// Destructor deletes dynamically allocated memory
Model::~Model() {
}

bool Model::gameOver() {
    return false;
}
void Model::go(Direction d) {
    direction = d;
}

void Model::move(){
switch(direction) {
    case UP: Pacman.y--; break;
    case DOWN: Pacman.y++; break;
    case LEFT: Pacman.x--; break;
    case RIGHT: Pacman.x++; break;
    }
}