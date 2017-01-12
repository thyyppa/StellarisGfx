#ifndef DEMO_H
#define DEMO_H

#include <interface/App.h>

class Demo : public App {
public:
    int run() override;
    void setDrawer( Drawer *drawer ) override;
protected:
    Drawer *draw;
    bool   running = true;
};


#endif //DEMO_H
