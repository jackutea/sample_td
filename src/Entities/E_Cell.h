#ifndef E_CELL_H__
#define E_CELL_H__
#include <stdio.h>
#include "../Common.h"

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

void E_Cell_Free(E_Cell *cell) {
    free(cell);
}

void E_Cell_Draw(E_Cell *cell) {
    DrawByShapeType(cell->shapeType, cell->pos, cell->size, cell->color);
}

#endif