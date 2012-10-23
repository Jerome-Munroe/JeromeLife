#ifndef TILEFLOOR_H_INCLUDED
#define TILEFLOOR_H_INCLUDED

#include <SDL\SDL.h>

struct gameBoardDimensions
{
    int squaresWide;
    int squaresTall;
    int xPadding;
    int yPadding;
    SDL_Rect origin;
};

class TileFloor
{
    protected:
    SDL_Surface* screen;
    Uint32 lifeColor;
    Uint32 blackColor;
    Uint32 RandomColor;
    gameBoardDimensions sizes;

    static const int SCREEN_WIDTH = 800;
    static const int SCREEN_HEIGHT = 600;
    static const int SCREEN_BPP = 32;
    static const int TILE_DIMENSION = 23;

    void init_grid();
    void set_game_dimensions();
    void fill_screen();
    void populate_screen(bool**);
    void put_square(SDL_Rect tmp,SDL_Surface* destination, Uint32 color);
    void put_square(int col, int row, bool fill);
    void put_square(SDL_Rect tmp);
    void draw_square(int pixX, int pixY);
    void set_random_color();
    bool** gimme_life();

    public:
    TileFloor();
    ~TileFloor();

    int start();
};


#endif // TILEFLOOR_H_INCLUDED
