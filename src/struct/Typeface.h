#ifndef TYPEFACE_H
#define TYPEFACE_H

#include <vector>

struct Typeface {
    unsigned char charWidth;
    unsigned char charHeight;

    std::vector<unsigned int> data;

    unsigned char count()
    {
        return data.size();
    }

    unsigned char kerning()
    {
        return charWidth * 0.5;
    }

    bool pixelSet( char ascii, int x, int y )
    {
        int pixel = ( y * charWidth ) + x;
        return data[ getIndex( ascii ) ] & ( 1 << pixel );
    }

    unsigned char getIndex( char i )
    {
        if ( 'a' <= i && i <= 'z' )
        {
            return i - 'a';
        } else if ( 'A' <= i && i <= 'Z' )
        {
            return i - 'A';
        } else if ( '0' <= i && i <= '9' )
        {
            return 25 + i - '0';
        }
        return 36;
    }
};

#endif //TYPEFACE_H
