#ifndef SDLDRAW_H
#define SDLDRAW_H

#include <interface/Drawer.h>
#include <struct/Color.h>
#include <config_pc.h>
#include <struct/Sprite.h>
#include <struct/Typeface.h>

class SdlDraw : public Drawer {
public:
    SdlDraw( SDL_Renderer *renderer );
    void point( int x, int y ) override;
    void line( int x0, int y0, int x1, int y1 ) override;
    void setFgColor( int r, int g, int b ) override;
    void setFramerate( int fps ) override;
    void sprite( int x, int y, Sprite *s ) override;
    void render() override;
    void setBgColor( int r, int g, int b ) override;
    void clear() override;
    void box( int x0, int y0, int x1, int y1 ) override;
    void fill( int x0, int y0, int x1, int y1 ) override;
    void string( char *string, int x, int y, Typeface *font ) override;
    void glyph( char *glyph, int x, int y, Typeface *font ) override;
};

#endif //SDLDRAW_H
