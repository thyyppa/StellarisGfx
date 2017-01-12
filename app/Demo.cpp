#include <config_pc.h>
#include <cstdlib>
#include "Demo.h"

int Demo::run()
{
    draw->setBgColor( 0x00, 0x00, 0x44 );
    while ( running )
    {
        draw->setFgColor( rand() % 0xff, rand() % 0xff, rand() % 0xff );
        draw->line( rand() % WIDTH, rand() % HEIGHT, rand() % WIDTH, rand() % HEIGHT );
        draw->render();
        draw->clear();
    }
    return 55;
}

void Demo::setDrawer( Drawer *drawer )
{
    this->draw = drawer;
}
