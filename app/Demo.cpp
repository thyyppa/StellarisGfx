#include <config_pc.h>
#include <cstdlib>
#include "Demo.h"

int Demo::run()
{
    draw->setBgColor( 0x00, 0x00, 0x44 );
    while ( running )
    {
        draw->setFgColor( RCOLOR );
        draw->line( RWIDTH, RHEIGHT, RWIDTH, RHEIGHT );
        draw->render();
        draw->clear();
    }
    return 55;
}

void Demo::setDrawer( Drawer *drawer )
{
    this->draw = drawer;
}
