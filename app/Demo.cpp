#include "Demo.h"
#include "text/tinyfont.font"

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

        snprintf( strbuff, sizeof( strbuff ), "random number: %i", rand() % 10000 );
        draw->string( strbuff, 10, 10, &tinyfont );

        snprintf( strbuff, sizeof( strbuff ), "random letter: %c", rand() % 26 + 65 );
        draw->string( strbuff, 10, 20, &tinyfont );

        draw->string( "cancel", 10, 30, &tinyfont );
        draw->string( "help", 10, 40, &tinyfont );
        draw->string( "quit", 10, 50, &tinyfont );

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
