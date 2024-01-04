#ifndef COMMON_H__
#define COMMON_H__
#include <stdbool.h>
#include "../include/raylib.h"
#include "../include/raymath.h"
#include "../include/raygui.h"

typedef const char * string;

const int BASE_GRID_SIZE = 24;

typedef enum ShapeType {
    SHAPE_TYPE_RECT = 1,
    SHAPE_TYPE_CIRCLE = 2,
} ShapeType;

typedef struct Vector2Int {
    int x;
    int y;
} Vector2Int;

Vector2 Vector2New(float x, float y){
    Vector2 v;
    v.x = x;
    v.y = y;
    return v;
}

Vector2 Vector2NewScale(float x, float y, float scale){
    Vector2 v;
    v.x = x * scale;
    v.y = y * scale;
    return v;
}

Rectangle RectangleNew(float x, float y, float w, float h){
    Rectangle r;
    r.x = x;
    r.y = y;
    r.width = w;
    r.height = h;
    return r;
}

Rectangle RectangleNewV(Vector2 pos, Vector2 size){
    Rectangle r;
    r.x = pos.x;
    r.y = pos.y;
    r.width = size.x;
    r.height = size.y;
    return r;
}

#endif