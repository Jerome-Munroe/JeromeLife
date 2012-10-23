#ifndef GAMEOFLIFE_H_INCLUDED
#define GAMEOFLIFE_H_INCLUDED

#include <SDL/SDL.h>
#include "TileFloor.h"

class GameOfLife : public TileFloor
{
    protected:
    SDL_Surface *upMessage, *downMessage, *leftMessage, *rightMessage, *message;
    SDL_Event event;
    bool quit;

    void take_care_input();
    void keyboard_control();
    void mouse_input();
    void display_message();

    public:
    void start();
    GameOfLife();
    ~GameOfLife();
};

#endif // GAMEOFLIFE_H_INCLUDED
