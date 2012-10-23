#include <SDL\SDL.h>
#include <SDL\SDL_ttf.h>
#include <cstdlib>
#include "GameOfLife.h"

void GameOfLife::take_care_input()
{
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_KEYDOWN)
        {
            switch(event.key.keysym.sym)
            {
                case SDLK_UP: message = upMessage; break;
                case SDLK_DOWN: message = downMessage; break;
                case SDLK_LEFT: message = leftMessage; break;
                case SDLK_RIGHT: message = rightMessage; break;
            }
        }
        if (event.type == SDL_QUIT)
        {
            quit = true;
        }
    }
}

void GameOfLife::keyboard_control()
{

}

void GameOfLife::mouse_input()
{

}

void GameOfLife::display_message()
{
    SDL_Rect location;
    location.x = SCREEN_WIDTH/2;
    location.y = SCREEN_HEIGHT/2;
    SDL_BlitSurface(message, NULL, screen, &location);
}

void GameOfLife::start()
{
    bool** lifeStateA, lifeStateB;
    lifeStateA = gimme_life();
    lifeStateB = gimme_life();

    while (quit != true)
    {
        fill_screen();
        take_care_input();
        display_message();
        SDL_Flip(screen);
        SDL_Delay(50);
    }
}

GameOfLife::GameOfLife()
{
    TTF_Init();
    TTF_Font* font = TTF_OpenFont("lazy.ttf", 50);
    quit = false;
    message = NULL;
    SDL_Color color = {255,255,255};

    upMessage = TTF_RenderText_Solid(font, "UP", color);
    downMessage = TTF_RenderText_Solid(font, "DOWN", color);
    leftMessage = TTF_RenderText_Solid(font, "LEFT", color);
    rightMessage = TTF_RenderText_Solid(font, "RIGHT", color);
}

GameOfLife::~GameOfLife()
{
    TTF_Quit();
    SDL_FreeSurface(upMessage);
    SDL_FreeSurface(downMessage);
    SDL_FreeSurface(leftMessage);
    SDL_FreeSurface(rightMessage);
}









