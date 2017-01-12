#ifndef DRAWER_H
#define DRAWER_H

class Drawer {
public:
    virtual void setFgColor( int r, int g, int b ) = 0;
    virtual void setBgColor( int r, int g, int b ) = 0;
    virtual void point( int x, int y ) = 0;
    virtual void line( int x0, int y0, int x1, int y1 ) = 0;
    virtual void box( int x0, int y0, int x1, int y1 ) = 0;
    virtual void fill( int x0, int y0, int x1, int y1 ) = 0;
    virtual void render() = 0;
    virtual void clear() = 0;
};

#endif //DRAWER_H
