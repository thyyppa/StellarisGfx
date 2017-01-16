#include <struct/Sprite.h>
#include <struct/Typeface.h>
#include <SDL2/SDL_timer.h>
#include "SdlDraw.h"


SdlDraw::SdlDraw( SDL_Renderer *renderer )
{
    this->renderer = renderer;
}

void SdlDraw::point( int x, int y )
{
    SDL_RenderDrawPoint( renderer, x + transformx, y + transformy );
}

void SdlDraw::line( int x0, int y0, int x1, int y1 )
{
    SDL_RenderDrawLine( renderer, x0 + transformx, y0 + transformy, x1 + transformx, y1 + transformy );
}

void SdlDraw::box( int x, int y, int w, int h )
{
    SDL_Rect box{ x + transformx, y + transformy, w, h };
    SDL_RenderDrawRect( renderer, &box );
}

void SdlDraw::fill( int x, int y, int w, int h )
{
    SDL_Rect box{ x + transformx, y + transformy, w, h };
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

void SdlDraw::setFramerate( int fps )
{
    this->framedelay = 1000 / fps;
}

void SdlDraw::string( char *string, int x, int y )
{
    int offset = 0;

    for ( int i = 0; i < strlen( string ); i++ )
    {
        offset = i * ( font->glyphWidth + font->kerning());
        glyph( &string[ i ], x + offset, y );
    }
}

void SdlDraw::glyph( char *glyph, int x, int y )
{
    for ( int row = 0; row < font->glyphHeight; row++ )
    {
        for ( int col = 0; col < font->glyphWidth; col++ )
        {
            if ( font->pixelIsSet( glyph[ 0 ], col, row ))
            {
                this->point( font->glyphWidth - col + x, row + y );
            }
        }
    }
}

void SdlDraw::transform( int x, int y )
{
    this->transformx = x;
    this->transformy = y;
}

void SdlDraw::untransform()
{
    this->transformx = 0;
    this->transformy = 0;
}

void SdlDraw::button( char *label, int x, int y )
{
    Color saveFg = fg;
    Color border = { fg.r * 0.15, fg.g * 0.15, fg.b * 0.15 };

    transform( x, y );
    fill( 0, 0, ( strlen( label ) * font->glyphWidth ) + 10, font->glyphHeight + 8 );

    setFgColor( border.r, border.g, border.b );
    if (( saveFg.r + saveFg.g + saveFg.b ) / 3 < 40 )
    {
        setFgColor( 0xff, 0xff, 0xff );
    }
    string( label, 4, 4 );

    setFgColor( border.r, border.g, border.b );
    box( 0, 0, ( strlen( label ) * font->glyphWidth ) + 10, font->glyphHeight + 8 );
    untransform();

    setFgColor( saveFg.r, saveFg.g, saveFg.b );
}

void SdlDraw::setFont( Typeface *font )
{
    this->font = font;
}
