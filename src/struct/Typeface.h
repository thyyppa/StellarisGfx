#ifndef TYPEFACE_H
#define TYPEFACE_H

#include <vector>

struct Typeface {
    unsigned char glyphWidth;
    unsigned char glyphHeight;

    std::vector<unsigned char> data;

    unsigned char kerning()
    {
        return glyphWidth * 0.1;
    }

    bool pixelIsSet( char ascii, int x, int y )
    {
        int offset = getIndex( ascii ) * glyphHeight;
        return data[ offset + y ] & ( 1 << x + ( 8 - glyphWidth ));
    }

    unsigned char getIndex( char i )
    {
        if ( 'A' <= i && i <= 'Z' )
        {
            return i - 65 + 26;
        }
        if ( 'a' <= i && i <= 'z' )
        {
            return i - 97;
        }
        if ( '1' <= i && i <= '9' )
        {
            return i - 48 + 77;
        }
        if ( '!' <= i && i <= '+' )
        {
            return i - 33 + 53;
        }
        if ( i == '0' )
        {
            return i - 48 + 87;
        }
        if ( i == ':' )
        {
            return 72;
        }
        return 103;
    }
};

#endif //TYPEFACE_H
