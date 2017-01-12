#ifndef SDLDRAW_H
#define SDLDRAW_H

#include <interface/Drawer.h>
#include <structs/Color.h>
#include <config_pc.h>

class SdlDraw : public Drawer {
public:
    SdlDraw( SDL_Renderer *renderer );
    void point( int x, int y ) override;
    void line( int x0, int y0, int x1, int y1 ) override;
    void setFgColor( int r, int g, int b ) override;
    void render() override;
    void setBgColor( int r, int g, int b ) override;
    void clear() override;
    void box( int x0, int y0, int x1, int y1 ) override;
    void fill( int x0, int y0, int x1, int y1 ) override;
protected:
    SDL_Renderer *renderer = nullptr;

    Color fg{ 0xff, 0xff, 0xff };
    Color bg{ 0x00, 0x00, 0x00 };
};

#endif //SDLDRAW_H
