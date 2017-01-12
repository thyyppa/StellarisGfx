using namespace cimg_library;

struct Color {
    int r, g, b;
};

struct Sprite {
public:
    int   width;
    int   height;
    Color *data[];
};

std::string getFilename( std::string filename );

int main( int argc, char *argv[] )
{
    std::string filename = getFilename( argv[ 1 ] );
    CImg<float> img( argv[ 1 ] );
    FILE        *output;
    output = fopen(( filename + ".h" ).c_str(), "w" );

    int r     = 0;
    int g     = 0;
    int b     = 0;
    int c     = 0;
    int total = img.height() * img.width();

    fprintf( output, "#ifndef %s_H\n", filename.c_str());
    fprintf( output, "#define %s_H\n\n", filename.c_str());
    fprintf( output, "const Sprite %s [3] = { %d, %d,\n{", filename.c_str(), img.width(), img.height());

    for ( int y = 0; y < img.height(); y++ )
    {
        for ( int x = 0; x < img.width(); x++ )
        {
            r = img( x, y, 0, 0 );
            g = img( x, y, 0, 1 );
            b = img( x, y, 0, 2 );
            fprintf( output, "{%#02x,%#02x,%#02x}", r, g, b );
            if ( total > ++c )
            {
                fprintf( output, "," );
            }
        }
        fprintf( output, "\n" );
    }

    fprintf( output, "}};\n\n" );
    fprintf( output, "#endif\n" );
    fclose( output );
    return 0;
}

std::string getFilename( std::string filename )
{
    int dot   = filename.find_last_of( "." );
    int slash = filename.find_last_of( "/" ) + 1;
    filename = filename.substr( slash, dot - slash );
    for ( auto &c: filename ) c = toupper( c );
    return "IMG_" + filename;
}