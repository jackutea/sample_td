#ifndef CONTEXT_H__
#define CONTEXT_H__

#include "../include/raylib.h"

typedef struct Context {

    int windowWidth;
    int windowHeight;

    Camera2D *cam;

} Context;

#endif