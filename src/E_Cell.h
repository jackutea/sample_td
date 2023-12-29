#ifndef E_CELL_H__
#define E_CELL_H__
#include "../include/raylib.h"
#include "../include/raymath.h"
#include "Common.h"
#include <stdio.h>

typedef struct TM_Cell {
    int typeID;
    ShapeType shapeType;
    Color color;
    Vector2 size;
} TM_Cell;

typedef struct E_Cell {
    int id;
    int typeID;
    Vector2 pos;
    // 逻辑
    // 表现
    ShapeType shapeType;
    Color color;
    Vector2 size;
} E_Cell;

void E_Cell_Draw(E_Cell *cell) {
    Vector2 center = cell->pos;
    center = Vector2Subtract(center, Vector2Scale(cell->size, 0.5f));

    if (cell->shapeType == SHAPE_TYPE_CIRCLE) {
        DrawCircleV(center, cell->size.x / 2, cell->color);
    } else if (cell->shapeType == SHAPE_TYPE_RECT) {
        DrawRectangleV(center, cell->size, cell->color);
    } else {
        printf("err E_Cell_Draw: shapeType error\n");
    }
}

#endif