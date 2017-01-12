#ifndef SPRITE_H
#define SPRITE_H

#include "Color.h"

struct Sprite {
public:
    int   width;
    int   height;
    Color data[];
};

#endif //SPRITE_H
