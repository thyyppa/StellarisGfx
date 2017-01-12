#include "Demo.h"
#include <config_pc.h>

#include "IMG_TEST.h"

int Demo::run()
{
    draw->setBgColor( 0xff, 0xff, 0xff );
    draw->clear();
    draw->setFramerate( 60 );

    while ( running )
    {
        draw->sprite( RWIDTH, RHEIGHT, IMG_TEST );
        draw->render();
        draw->clear();
    }

    return 0;
}

void Demo::setDrawer( Drawer *drawer )
{
    this->draw = drawer;
}
