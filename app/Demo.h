#ifndef DEMO_H
#define DEMO_H

#include <interface/App.h>
#include <SDL2/SDL_events.h>

class Demo : public App {
public:
    int run() override;
    void setDrawer( Drawer *drawer ) override;
protected:
    Drawer *draw;
    bool   running = true;
    void handleEvents( SDL_Event &e );
};


#endif //DEMO_H
