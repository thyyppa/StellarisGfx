#include <text/lgfont.font>
#include <config_pc.h>
#include "Demo.h"

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
        draw->setFont( &lg_font );

        draw->transform( 10, 10 );
        snprintf( strbuff, sizeof( strbuff ), "number:%i", rand() % 100000 );
        draw->string( strbuff, 0, 0 );

        snprintf( strbuff, sizeof( strbuff ), "letter:%c", rand() % 26 + 65 );
        draw->string( strbuff, 0, 10 );

        draw->string( "help", 0, 20 );
        draw->string( "cancel", 0, 30 );
        draw->string( "1234567890", 0, 40 );
        draw->untransform();

        draw->setFgColor( 0xAA, 0xAA, 0xff );
        draw->button( "light", 10, 65 );

        draw->setFgColor( 0x22, 0x00, 0x00 );
        draw->button( "dark", 10, 87 );

        draw->transform( 0, 111 );
        draw->setFgColor( 0x66, 0x66, 0x66 );
        draw->fill( 0, 0, WIDTH, 20 );
        draw->setFgColor( 0x88, 0x88, 0x88 );
        draw->fill( 90, 0, WIDTH - 90, 20 );
        draw->setFgColor( 0xff, 0xff, 0xff );
        draw->string( "menu", 97, 5 );
        draw->setFgColor( 0x33, 0x33, 0x33 );
        draw->box( -1, 0, WIDTH + 2, 20 );
        draw->untransform();

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
