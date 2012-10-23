#include <SDL\SDL.h>
#include <cstdlib>
#include <ctime>
#include "TileFloor.h"

//fills the screen full of good sized boxes with random colors
void TileFloor::fill_screen()
{
    SDL_Rect whereToPutBlock;
    //set where to put the first block
    whereToPutBlock.x = sizes.xPadding / 2;
    for (int x = 1; x <= sizes.squaresWide; x++)
    {
        whereToPutBlock.y = sizes.yPadding / 2;
        for (int y = 1; y <= sizes.squaresTall; y++)
        {
            set_random_color();
            draw_square(whereToPutBlock.x, whereToPutBlock.y);
            whereToPutBlock.y += TILE_DIMENSION;
        }
        whereToPutBlock.x += TILE_DIMENSION;
    }
}

void TileFloor::populate_screen(bool** population)
{
    SDL_Rect whereToPutBlock;


}

void TileFloor::put_square(int col, int row, bool fill)
{
    int x = sizes.origin.x + (col * TILE_DIMENSION);
    int y = sizes.origin.y + (row * TILE_DIMENSION);

    draw_square(x,y);
}

void TileFloor::put_square(SDL_Rect tmp,SDL_Surface* destination = NULL, Uint32 color = NULL )
{


}

void TileFloor::draw_square(int pixX, int pixY)
{
    SDL_Rect tmp;
    tmp.x = pixX;
    tmp.y = pixY;
    tmp.w = TILE_DIMENSION;
    tmp.h = TILE_DIMENSION;

    SDL_FillRect(screen, &tmp, RandomColor);
}

void TileFloor::set_game_dimensions()
{
    sizes.xPadding = SCREEN_WIDTH % TILE_DIMENSION;
    sizes.squaresWide = (SCREEN_WIDTH - sizes.xPadding)/TILE_DIMENSION;
    sizes.yPadding = SCREEN_HEIGHT % TILE_DIMENSION;
    sizes.squaresTall = (SCREEN_HEIGHT - sizes.yPadding)/TILE_DIMENSION;
    sizes.origin.x = sizes.xPadding / 2;
    sizes.origin.y = sizes.yPadding / 2;
}

void TileFloor::set_random_color()
{
    Uint8 colors[3];
    for(int i=0; i<3; i++)
    {
        colors[i]=rand()%255;
    }
    RandomColor = SDL_MapRGB(screen->format, colors[0], colors[1], colors[2]);
}

bool** TileFloor::gimme_life()
{
    bool** life;

    life = new bool*[sizes.squaresWide]; //array is now the size of the right width

    for(int i=0; i<sizes.squaresWide; i++)
    {
        life[i] = new bool[sizes.squaresTall];
    }//the momory is now allocated.

    //now initialize the memory
    for(int i=0; i<sizes.squaresWide; i++)
        for(int j=0; j<sizes.squaresTall; j++)
        {
            life[i][j] = false;
        }

    return life;
    // This is what I tried to do -> populated = new bool[gameBoardDimensions.w][gameBoardDimensions.y];
}

//PUBLICS
TileFloor::TileFloor()
{
    SDL_Init(SDL_INIT_EVERYTHING);

    screen = NULL;
    screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP, SDL_SWSURFACE);

    set_game_dimensions();
    std::srand(std::time(0));
    lifeColor = SDL_MapRGB(screen->format, 0x00, 0xFF , 0x00);
}

TileFloor::~TileFloor()
{
    SDL_Quit();
}

int TileFloor::start()
{
    fill_screen();
    if (SDL_Flip(screen) == -1)
    {
        return 1;
    }
    for (int i = 0; i<=1000; i++)
    {
        SDL_Delay(10);
    }
}
