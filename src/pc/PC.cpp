#include <sdl/init/init.h>
#include <Demo.h>
#include <sdl/SdlDraw.h>
#include "PC.h"

int PC::boot()
{
    init_sdl();
    SDL_Window   *window   = nullptr;
    SDL_Renderer *renderer = nullptr;

    window   = createWindow( WIDTH, HEIGHT );
    renderer = createRenderer( window );

    Demo     app;
    SdlDraw  drawer( renderer );
    app.setDrawer( &drawer );

    return app.run();
}
