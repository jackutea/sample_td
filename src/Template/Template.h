#ifndef TEMPLATE_H__
#define TEMPLATE_H__
#include "TM_Cell.h"
#include "TM_Level.h"
#include "TM_Monster.h"
#include <stdlib.h>

typedef struct Template {

    TM_Level *levels;
    int levelLen;

    TM_Cell *cells;
    int cellLen;

    TM_Monster *monsters;
    int monsterLen;

} Template;

void Template_Init(Template *tpl) {

    // ==== Level ====
    tpl->levelLen = 0;
    tpl->levels = (TM_Level *)malloc(sizeof(TM_Level) * 50);

    TM_Level *levels = tpl->levels;
    TM_Level l1;
    l1.typeID = 1;
    l1.size = Vector2New(40, 23);
    l1.cellCount = 11 * 2;
    l1.cellPoses = (Vector2 *)malloc(sizeof(Vector2) * l1.cellCount);
    l1.cellPoses[0] = Vector2New(-4, -10);
    l1.cellPoses[1] = Vector2New(-4, -8);
    l1.cellPoses[2] = Vector2New(-4, -6);
    l1.cellPoses[3] = Vector2New(-4, -4);
    l1.cellPoses[4] = Vector2New(-4, -2);
    l1.cellPoses[5] = Vector2New(-4, 0);
    l1.cellPoses[6] = Vector2New(-4, 2);
    l1.cellPoses[7] = Vector2New(-4, 4);
    l1.cellPoses[8] = Vector2New(-4, 6);
    l1.cellPoses[9] = Vector2New(-4, 8);
    l1.cellPoses[10] = Vector2New(-4, 10);
    l1.cellPoses[11] = Vector2New(4, -10);
    l1.cellPoses[12] = Vector2New(4, -8);
    l1.cellPoses[13] = Vector2New(4, -6);
    l1.cellPoses[14] = Vector2New(4, -4);
    l1.cellPoses[15] = Vector2New(4, -2);
    l1.cellPoses[16] = Vector2New(4, 0);
    l1.cellPoses[17] = Vector2New(4, 2);
    l1.cellPoses[18] = Vector2New(4, 4);
    l1.cellPoses[19] = Vector2New(4, 6);
    l1.cellPoses[20] = Vector2New(4, 8);
    l1.cellPoses[21] = Vector2New(4, 10);
    levels[tpl->levelLen++] = l1;

    // ==== Cell ====
    tpl->cellLen = 0;
    tpl->cells = (TM_Cell *)malloc(sizeof(TM_Cell) * 50);

    TM_Cell *cells = tpl->cells;
    TM_Cell c1;
    c1.typeID = 1;
    c1.shapeType = SHAPE_TYPE_RECT;
    c1.color = BLUE;
    c1.size = Vector2NewScale(1, 1, BASE_GRID_SIZE);
    cells[tpl->cellLen++] = c1;

    // ==== Monster ====
    tpl->monsterLen = 0;
    tpl->monsters = (TM_Monster *)malloc(sizeof(TM_Monster) * 50);

    TM_Monster *monsters = tpl->monsters;
    TM_Monster m1;
    m1.typeID = 1;
    m1.moveSpeed = 1;
    m1.hp = 100;
    m1.dropMoney = 10;
    m1.drawShapeType = SHAPE_TYPE_RECT;
    m1.color = RED;
    m1.drawSize = Vector2NewScale(1, 1, BASE_GRID_SIZE);
    monsters[tpl->monsterLen++] = m1;
}

void Template_Free(Template *tpl) {
    for (int i = 0; i < tpl->levelLen; i += 1) {
        TM_Level_Free(&tpl->levels[i]);
    }
    free(tpl->cells);
    free(tpl->monsters);
    free(tpl);
}

TM_Level *Template_GetLevel(Template *tpl, int typeID) {
    for (int i = 0; i < tpl->levelLen; i += 1) {
        if (tpl->levels[i].typeID == typeID) {
            return &tpl->levels[i];
        }
    }
    return NULL;
}

TM_Cell *Template_GetCell(Template *tpl, int typeID) {
    for (int i = 0; i < tpl->cellLen; i += 1) {
        if (tpl->cells[i].typeID == typeID) {
            return &tpl->cells[i];
        }
    }
    return NULL;
}

TM_Monster *Template_GetMonster(Template *tpl, int typeID) {
    for (int i = 0; i < tpl->monsterLen; i += 1) {
        if (tpl->monsters[i].typeID == typeID) {
            return &tpl->monsters[i];
        }
    }
    return NULL;
}

#endif