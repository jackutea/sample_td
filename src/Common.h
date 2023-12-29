#ifndef COMMON_H__
#define COMMON_H__

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

#endif