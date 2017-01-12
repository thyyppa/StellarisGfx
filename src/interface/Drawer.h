#ifndef DRAWER_H
#define DRAWER_H

#include <SDL2/SDL_system.h>
#include "structs/Sprite.h"

class Drawer {
public:
    virtual void setFgColor( int r, int g, int b ) = 0;
    virtual void setBgColor( int r, int g, int b ) = 0;
    virtual void point( int x, int y ) = 0;
    virtual void line( int x0, int y0, int x1, int y1 ) = 0;
    virtual void box( int x0, int y0, int x1, int y1 ) = 0;
    virtual void fill( int x0, int y0, int x1, int y1 ) = 0;
    virtual void sprite( int x, int y, const Sprite *s ) = 0;
    virtual void render() = 0;
    virtual void clear() = 0;
    virtual void setFramerate( int fps ) = 0;

protected:
    SDL_Renderer *renderer  = nullptr;
    int          framedelay = 16;
    Color        fg{ 0xff, 0xff, 0xff };
    Color        bg{ 0x00, 0x00, 0x00 };
};

#endif //DRAWER_H
