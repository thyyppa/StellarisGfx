#include <text/lgfont.font>
#include "Demo.h"
#include "text/lgfont.font"

int Demo::run()
{
    draw->setBgColor( 0xff, 0xff, 0xff );
    draw->clear();
    draw->setFramerate( 10 );
    SDL_Event e;
    char      strbuff[100];

    while ( running )
    {
        draw->clear();
        draw->setFgColor( 0x00, 0x00, 0x00 );

        snprintf( strbuff, sizeof( strbuff ), "number:%i", rand() % 100000 );
        draw->string( strbuff, 5, 10, &lg_font );

        snprintf( strbuff, sizeof( strbuff ), "letter:%c", rand() % 26 + 65 );
        draw->string( strbuff, 5, 20, &lg_font );

        draw->string( "cancel", 5, 30, &lg_font );
        draw->string( "help", 5, 40, &lg_font );
        draw->string( "1234567890", 5, 50, &lg_font );

        draw->setFgColor( 0x88, 0x00, 0x00 );
        draw->string( "Quit", 5, 115, &lg_font );
        draw->setFgColor( 0x00, 0x00, 0x88 );
        draw->string( "Okay", 97, 115, &lg_font );

        draw->render();

        handleEvents( e );
    }

    return 0;
}

void Demo::handleEvents( SDL_Event &e )
{
    while ( SDL_PollEvent( &e ))
    {
        if ( e.type == SDL_QUIT )
        {
            running = false;
        }
        if ( e.type == SDL_KEYDOWN )
        {
            switch ( e.key.keysym.sym )
            {
                case SDLK_ESCAPE:
                case SDLK_q:
                    running = false;
                    break;
            }
        }
    }
}

void Demo::setDrawer( Drawer *drawer )
{
    this->draw = drawer;
}
