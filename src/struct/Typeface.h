#ifndef TYPEFACE_H
#define TYPEFACE_H

#include <vector>
#include "Color.h"

struct Typeface {
    int  rows;
    int  cols;
    int  charWidth;
    int  charHeight;
    char *data;
    bool filled = false;

    std::vector<std::vector<bool>> pixels;
    std::vector<std::vector<bool>> glyph;

    int width()
    {
        return cols * charWidth;
    }

    int height()
    {
        return rows * charHeight;
    }

    int size()
    {
        return this->height() * this->width();
    }

    int charSize()
    {
        return this->charWidth * this->charHeight;
    }

    void fillBuffer()
    {
        if ( filled )
        {
            return;
        }

        unsigned char pixel[3];

        this->pixels.reserve( this->width(), std::vector<bool>);
        this->glyph.reserve( this->charWidth, std::vector<bool>);

        int y = 0;
        int x = 0;

        for ( int i = 0; i < this->size(); i++ )
        {

            pixel[ 0 ] = ((( this->data[ 0 ] - 33 ) << 2 ) | (( this->data[ 1 ] - 33 ) >> 4 ));
            pixel[ 1 ] = (((( this->data[ 1 ] - 33 ) & 0xF ) << 4 ) | (( this->data[ 2 ] - 33 ) >> 2 ));
            pixel[ 2 ] = (((( this->data[ 2 ] - 33 ) & 0x3 ) << 6 ) | (( this->data[ 3 ] - 33 )));
            this->data += 4;

            x++;

            if ( x >= this->width())
            {
                x = 0;
                y++;
            }

            this->pixels[ y ][ x ] = ( pixel[ 0 ] || pixel[ 1 ] || pixel[ 2 ] );
        }
        this->filled = true;
    }

    void getGlyph( int offset )
    {
        this->fillBuffer();
        int row  = 0;
        int col  = 0;
        int xOff = 0;
        int yOff = 0;

        for ( int y = 0; y < this->charHeight; y++ )
        {
            for ( int x = 0; x < this->charWidth; x++ )
            {
                this->glyph[ x ][ y ] = this->pixels[ x ][ y ];
            }
        }

//        for ( int y = yOff; y < yOff + charHeight; y++ )
//        {
//            for ( int x = xOff; x < xOff + charWidth; x++ )
//            {
//                out.push_back( this->pixels[ this->coordToOffset( x, y ) ] );
//            }
//        }
    }

    int coordToOffset( int x, int y )
    {
        return ( y * width()) + x;
    }
};

#endif //TYPEFACE_H
