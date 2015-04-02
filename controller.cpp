#include "controller.h"
#include "model.h"
#include <map>

using namespace std;

Controller::Controller() {
    model = new Model(640, 480);
    view = new View("Game", 640, 480);
}

Controller::~Controller() {
    delete model;
    delete view;
}
/**
References:
https://wiki.libsdl.org/SDL_PollEvent
https://wiki.libsdl.org/SDL_Event
*/
void Controller::loop() {
	SDL_Rect pacdest;
	pacdest.x=288;
	pacdest.y=416;
    SDL_Event e;
	e.type=NULL;
	
	
	
	
	
	
	
    unsigned int lastTime = 0, currentTime;
    std::map<SDL_Keycode, Direction> direction;
    direction[SDLK_UP] = UP;
    direction[SDLK_DOWN] = DOWN;
    direction[SDLK_LEFT] = LEFT;
    direction[SDLK_RIGHT] = RIGHT;
	
    while(!model->gameOver()) {
        currentTime = SDL_GetTicks();
		   if (currentTime > lastTime + 10) {
            model->move_pac(pacdest);
			model->move_ghost();
            lastTime = currentTime;
        }
        // Do stuff here to animate as necessary
        view->show(model, pacdest, e);
        if (SDL_PollEvent(&e) != 0) {
            switch (e.type) {
            case SDL_QUIT:
                return;
            case SDL_KEYDOWN:
                switch(e.key.keysym.sym) {
                case SDLK_DOWN:
                case SDLK_UP:
                case SDLK_LEFT:
                case SDLK_RIGHT:
                    model->go(direction[e.key.keysym.sym]);
                break;
                default:
                break;
                }
            case SDL_MOUSEBUTTONDOWN:
                break;
            }
        }
    }
	
    // TODO: show something nice?
    view->show(model, pacdest, e);
    SDL_Delay(3000);
}
