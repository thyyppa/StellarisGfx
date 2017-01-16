#include "init.h"

SDL_Renderer *createRenderer( SDL_Window *window )
{
    SDL_Renderer *renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
    if ( renderer == NULL )
    {
        printf( STR_NO_CREATE_RENDERER, SDL_GetError());
        return nullptr;
    }
    return renderer;
}

SDL_Window *createWindow( int width, int height )
{
    SDL_Window *window = SDL_CreateWindow(
            "StellarisGfx",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            width,
            height,
            SDL_WINDOW_SHOWN
    );

    if ( !window )
    {
        printf( STR_NO_CREATE_WINDOW, SDL_GetError());
        return nullptr;
    }

    return window;
}

bool init_sdl()
{
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( STR_SDL_NO_INIT, SDL_GetError());
        return true;
    }

    if ( !( IMG_Init( IMG_INIT_PNG ) & IMG_INIT_PNG ))
    {
        printf( STR_NO_INIT_SDL_IMAGE, IMG_GetError());
        return true;
    }

    return false;
}

