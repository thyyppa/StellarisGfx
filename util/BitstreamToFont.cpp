#include <cstdio>
#include "BitstreamToFont.h"

int main( int argc, char *argv[] )
{
//    std::string filename = getFilename( argv[ 1 ] );
    std::string filename = "op";
    FILE        *output;
    output = fopen(( filename + ".h" ).c_str(), "w" );

    fprintf( output, "#include <struct/Typeface.h>\n"
            "\n"
            "Typeface %s_font{\n"
            "        %i,\n"
            "        %i,\n"
            "        {\n", filename.c_str(), font.cwidth, font.cheight );

    for ( int f = 0; f < 104; f++ )
    {
        Char c = font.getChar( f );
        for ( int y = 0; y < c.height; y++ )
        {
            fprintf( output, "        0b" );
            for ( int x = 0; x < 8; x++ )
            {
                if ( c.data[ y ][ x ] )
                {
                    fprintf( output, "1" );
                } else
                {
                    fprintf( output, "0" );
                }
            }
            fprintf( output, ",\n" );
        }
    }


    fprintf( output, "}\n};\n\n" );
    fprintf( output, "#endif\n" );
    fclose( output );
    return 0;
}