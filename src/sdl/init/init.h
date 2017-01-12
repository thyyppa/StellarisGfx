#ifndef SDL_INIT_H
#define SDL_INIT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "sdl/init/en.h"

bool init_sdl();
SDL_Renderer *createRenderer( SDL_Window *window );
SDL_Window *createWindow( int width, int height );

#endif //SDL_INIT_H
