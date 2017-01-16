#ifndef DRAWER_H
#define DRAWER_H

#include <SDL2/SDL_system.h>
#include <struct/Color.h>
#include <struct/Typeface.h>
#include "struct/Sprite.h"

class Drawer {
public:
    virtual void setFgColor( int r, int g, int b ) = 0;
    virtual void setBgColor( int r, int g, int b ) = 0;
    virtual void point( int x, int y ) = 0;
    virtual void line( int x0, int y0, int x1, int y1 ) = 0;
    virtual void box( int x0, int y0, int x1, int y1 ) = 0;
    virtual void fill( int x0, int y0, int x1, int y1 ) = 0;
    virtual void sprite( int x, int y, Sprite *s ) = 0;
    virtual void string( char *string, int x, int y ) = 0;
    virtual void glyph( char *glyph, int x, int y ) = 0;
    virtual void render() = 0;
    virtual void clear() = 0;
    virtual void button( char *label, int x, int y ) = 0;
    virtual void transform( int x, int y ) = 0;
    virtual void untransform() = 0;
    virtual void setFramerate( int fps ) = 0;
    virtual void setFont( Typeface *font ) = 0;

protected:
    SDL_Renderer *renderer  = nullptr;
    int          framedelay = 16;
    Color        fg{ 0xff, 0xff, 0xff };
    Color        bg{ 0x00, 0x00, 0x00 };
    Typeface     *font;
    int          transformx = 0;
    int          transformy = 0;
};

#endif //DRAWER_H
