#include <SDL2/SDL_system.h>
#include <SDL2/SDL_timer.h>
#include <struct/Sprite.h>
#include <struct/Typeface.h>
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
    SDL_Delay( this->framedelay );
}

void SdlDraw::sprite( int x, int y, Sprite *s )
{
    unsigned char pixel[3];
    char          *buffer = s->data;
    for ( int     row     = 0; row < s->width; row++ )
    {
        for ( int col = 0; col < s->height; col++ )
        {
            pixel[ 0 ] = ((( s->data[ 0 ] - 33 ) << 2 ) | (( s->data[ 1 ] - 33 ) >> 4 ));
            pixel[ 1 ] = (((( s->data[ 1 ] - 33 ) & 0xF ) << 4 ) | (( s->data[ 2 ] - 33 ) >> 2 ));
            pixel[ 2 ] = (((( s->data[ 2 ] - 33 ) & 0x3 ) << 6 ) | (( s->data[ 3 ] - 33 )));
            s->data += 4;

            if ( pixel[ 0 ] != 0xff || pixel[ 1 ] != 0x00 || pixel[ 2 ] != 0xff )
            {
                this->setFgColor( pixel[ 0 ], pixel[ 1 ], pixel[ 1 ] );
                this->point( col + x, row + y );
            }
        }
    }
    s->data = buffer;
}

//void SdlDraw::sprite( int x, int y, const Sprite *s )
//{
//    int       c   = 0;
//    for ( int row = 0; row < s->height; row++ )
//    {
//        for ( int col = 0; col < s->width; col++ )
//        {
//            if ( s->data[ c ].r != 0xff || s->data[ c ].g != 0x00 || s->data[ c ].b != 0xff )
//            {
//                this->setFgColor( s->data[ c ].r, s->data[ c ].g, s->data[ c ].b );
//                this->point( col + x, row + y );
//            }
//            c++;
//        }
//    }
//}

void SdlDraw::setFramerate( int fps )
{
    this->framedelay = 1000 / fps;
}

void SdlDraw::glyph( int x, int y, int offset, Typeface *font )
{
    font->getGlyph( offset );

    for ( int row = 0; row < font->charWidth; row++ )
        for ( int col = 0; col < font->charHeight; col++ )
        {
            {
                if ( font->glyph[ row ][ col ] )
                {
                    this->point( col, row );
                }
            }
        }

}
