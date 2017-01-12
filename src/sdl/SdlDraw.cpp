#include <SDL2/SDL_system.h>
#include <SDL2/SDL_timer.h>
#include "SdlDraw.h"

SdlDraw::SdlDraw( SDL_Renderer *renderer )
{
    this->renderer = renderer;
}

void SdlDraw::point( int x, int y )
{
    SDL_RenderDrawPoint( renderer, x, y );
}

void SdlDraw::line( int x0, int y0, int x1, int y1 )
{
    SDL_RenderDrawLine( renderer, x0, y0, x1, y1 );
}

void SdlDraw::box( int x0, int y0, int x1, int y1 )
{
    SDL_Rect box{ x0, y0, x1, y1 };
    SDL_RenderDrawRect( renderer, &box );
}

void SdlDraw::fill( int x0, int y0, int x1, int y1 )
{
    SDL_Rect box{ x0, y0, x1, y1 };
    SDL_RenderFillRect( renderer, &box );
}

void SdlDraw::setFgColor( int r, int g, int b )
{
    this->fg = Color{ r, g, b };
    SDL_SetRenderDrawColor( renderer, fg.r, fg.g, fg.b, 0xff );
}

void SdlDraw::setBgColor( int r, int g, int b )
{
    this->bg = Color{ r, g, b };
}

void SdlDraw::clear()
{
    SDL_SetRenderDrawColor( renderer, bg.r, bg.g, bg.b, 0xff );
    this->fill( 0, 0, WIDTH, HEIGHT );
    SDL_RenderClear( renderer );
    SDL_SetRenderDrawColor( renderer, fg.r, fg.g, fg.b, 0xff );
}

void SdlDraw::render()
{
    SDL_RenderPresent( renderer );
    SDL_Delay( 16 );
}
