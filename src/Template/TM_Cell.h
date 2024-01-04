#ifndef TM_CELL_H__
#define TM_CELL_H__

#include "import.h"

typedef struct TM_Cell {
    int typeID;
    ShapeType shapeType;
    Color color;
    Vector2 size;
} TM_Cell;

TM_Cell TM_Cell_Create(int typeID, ShapeType shapeType, Color color, Vector2 size) {
    TM_Cell cell;
    cell.typeID = typeID;
    cell.shapeType = shapeType;
    cell.color = color;
    cell.size = size;
    return cell;
}

#endif