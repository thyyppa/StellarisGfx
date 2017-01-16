#include "Demo.h"
#include <config_pc.h>
#include <ball/ball.h>
#include <SDL2/SDL_events.h>
#include "ball/ball.sprite"
#include "text/font.font"

int Demo::run()
{
    draw->setBgColor( 0xff, 0xff, 0xff );
    draw->clear();
    draw->setFramerate( 60 );
    SDL_Event e;

    std::vector<Ball> balls;

    for ( int i = 0; i < 3; i++ )
    {
        Ball b;
        b.x      = RWIDTH;
        b.y      = RHEIGHT;
        b.x1     = RWIDTH;
        b.y1     = RHEIGHT;
        b.bounds = { 0, 0, WIDTH - 10, HEIGHT - 10 };
        balls.push_back( b );
    }

    while ( running )
    {
        draw->clear();

        for ( Ball &b : balls )
        {
            b.run();
            draw->sprite( b.x, b.y, &img_ball );
            draw->line( b.x, b.y, b.x1, b.y1 );
        }

        draw->setFgColor( 0x00, 0x00, 0x00 );
        draw->glyph( 10, 10, 1, &small_font );
        draw->glyph( 20, 10, 2, &small_font );
        draw->glyph( 30, 10, 3, &small_font );
        draw->glyph( 10, 24, 10, &small_font );
        draw->glyph( 20, 24, 20, &small_font );
        draw->glyph( 30, 24, 30, &small_font );

        draw->render();


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

    return 0;
}

void Demo::setDrawer( Drawer *drawer )
{
    this->draw = drawer;
}
