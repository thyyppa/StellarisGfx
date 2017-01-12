#ifndef APP_H
#define APP_H

#include "Drawer.h"

class App {
public:
    virtual void setDrawer( Drawer *drawer ) = 0;
    virtual int run() = 0;
};

#endif //APP_H
