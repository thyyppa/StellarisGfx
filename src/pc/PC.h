#ifndef PC_H
#define PC_H

#include <interface/Bootstrap.h>
#include "config_pc.h"

class PC : public Bootstrap {
public:
    int boot();
};


#endif //PC_H
