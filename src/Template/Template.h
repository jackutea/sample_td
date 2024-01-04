#ifndef TEMPLATE_H__
#define TEMPLATE_H__
#include <stdlib.h>
#include "TM_Cell.h"

typedef struct Template {
    TM_Cell *cells;
    int cellLen;
} Template;

void Template_Init(Template *tpl) {

    tpl->cellLen = 0;
    tpl->cells = (TM_Cell *)malloc(sizeof(TM_Cell) * 50);

    TM_Cell *cell = tpl->cells;
    TM_Cell c1;
    c1.typeID = 1;
    c1.shapeType = SHAPE_TYPE_RECT;
    c1.color = BLUE;
    c1.size = Vector2NewScale(1, 1, BASE_GRID_SIZE);

    cell[tpl->cellLen++] = c1;
}

void Template_Free(Template *tpl) {
    free(tpl->cells);
    free(tpl);
}

TM_Cell *Template_GetCell(Template *tpl, int typeID) {
    for (int i = 0; i < tpl->cellLen; i += 1) {
        if (tpl->cells[i].typeID == typeID) {
            return &tpl->cells[i];
        }
    }
    return NULL;
}

#endif