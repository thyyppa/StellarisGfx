#ifndef CONFIG_PC_H
#define CONFIG_PC_H

#define APP PC

#define WIDTH 131
#define HEIGHT 131
#define SCALE 4

#define RWIDTH rand() % WIDTH
#define RHEIGHT rand() % HEIGHT
#define RCOLOR rand() % 0xff, rand() % 0xff, rand() % 0xff

#endif //CONFIG_PC_H
