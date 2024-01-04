#ifndef TEMPLATE_H__
#define TEMPLATE_H__
#include "TM_Cave.h"
#include "TM_Cell.h"
#include "TM_Level.h"
#include "TM_Monster.h"
#include <stdlib.h>

typedef struct Template {

    TM_Level *levels;
    int levelLen;

    TM_Cave *caves;
    int caveLen;

    TM_Cell *cells;
    int cellLen;

    TM_Monster *monsters;
    int monsterLen;

} Template;

void Template_InitLevels(Template *tpl);
void Template_InitCaves(Template *tpl);
void Template_InitCells(Template *tpl);
void Template_InitMonsters(Template *tpl);

void Template_Init(Template *tpl) {
    Template_InitLevels(tpl);
    Template_InitCaves(tpl);
    Template_InitCells(tpl);
    Template_InitMonsters(tpl);
}

void Template_Free(Template *tpl) {
    for (int i = 0; i < tpl->levelLen; i += 1) {
        TM_Level_Free(&tpl->levels[i]);
    }
    free(tpl->cells);
    free(tpl->monsters);
    free(tpl);
}

// - Cave
void Template_InitCaves(Template *tpl) {
    tpl->caveLen = 0;
    tpl->caves = (TM_Cave *)malloc(sizeof(TM_Cave) * 50);

    TM_Cave *caves = tpl->caves;

    // Create: typeID, cd, spawnMaintain, spawnInterval, monsterTypeID;
    TM_Cave cave1 = TM_Cave_Create(1, 2.0f, 1.0f, 0.1f, 1);
    caves[tpl->caveLen++] = cave1;
}

TM_Cave *Template_GetCave(Template *tpl, int typeID) {
    for (int i = 0; i < tpl->caveLen; i += 1) {
        if (tpl->caves[i].typeID == typeID) {
            return &tpl->caves[i];
        }
    }
    return NULL;
}

// - Level
void Template_InitLevels(Template *tpl) {

    tpl->levelLen = 0;
    tpl->levels = (TM_Level *)malloc(sizeof(TM_Level) * 50);

    TM_Level *levels = tpl->levels;
    TM_Level l1;
    l1.typeID = 1;
    l1.size = Vector2New(40, 23);

    l1.caveGeneratorCount = 1;
    l1.caveGenerators = (TM_CaveGenerator *)malloc(sizeof(TM_CaveGenerator) * l1.caveGeneratorCount);
    l1.caveGenerators[0] = TM_CaveGenerator_Create(1, Vector2New(0, 0));

#define cr TM_CellGenerator_Create
    l1.cellCount = 11 * 2;
    l1.cellGenerators = (TM_CellGenerator *)malloc(sizeof(TM_CellGenerator) * l1.cellCount);
    l1.cellGenerators[0] = cr(1, Vector2New(-4, -10));
    l1.cellGenerators[1] = cr(1, Vector2New(-4, -8));
    l1.cellGenerators[2] = cr(1, Vector2New(-4, -6));
    l1.cellGenerators[3] = cr(1, Vector2New(-4, -4));
    l1.cellGenerators[4] = cr(1, Vector2New(-4, -2));
    l1.cellGenerators[5] = cr(1, Vector2New(-4, 0));
    l1.cellGenerators[6] = cr(1, Vector2New(-4, 2));
    l1.cellGenerators[7] = cr(1, Vector2New(-4, 4));
    l1.cellGenerators[8] = cr(1, Vector2New(-4, 6));
    l1.cellGenerators[9] = cr(1, Vector2New(-4, 8));
    l1.cellGenerators[10] = cr(1, Vector2New(-4, 10));

    l1.cellGenerators[11] = cr(2, Vector2New(4, -10));
    l1.cellGenerators[12] = cr(2, Vector2New(4, -8));
    l1.cellGenerators[13] = cr(2, Vector2New(4, -6));
    l1.cellGenerators[14] = cr(2, Vector2New(4, -4));
    l1.cellGenerators[15] = cr(2, Vector2New(4, -2));
    l1.cellGenerators[16] = cr(2, Vector2New(4, 0));
    l1.cellGenerators[17] = cr(2, Vector2New(4, 2));
    l1.cellGenerators[18] = cr(2, Vector2New(4, 4));
    l1.cellGenerators[19] = cr(2, Vector2New(4, 6));
    l1.cellGenerators[20] = cr(2, Vector2New(4, 8));
    l1.cellGenerators[21] = cr(2, Vector2New(4, 10));
#undef cr

    levels[tpl->levelLen++] = l1;
}

TM_Level *Template_GetLevel(Template *tpl, int typeID) {
    for (int i = 0; i < tpl->levelLen; i += 1) {
        if (tpl->levels[i].typeID == typeID) {
            return &tpl->levels[i];
        }
    }
    return NULL;
}

// - Cell
void Template_InitCells(Template *tpl) {
    tpl->cellLen = 0;
    tpl->cells = (TM_Cell *)malloc(sizeof(TM_Cell) * 50);

    TM_Cell *cells = tpl->cells;

    // Create: typeID, shapeType, color, size
    TM_Cell c1 = TM_Cell_Create(1, SHAPE_TYPE_RECT, BLUE, Vector2NewScale(1, 1, BASE_GRID_SIZE));
    cells[tpl->cellLen++] = c1;

    TM_Cell c2 = TM_Cell_Create(2, SHAPE_TYPE_CIRCLE, GREEN, Vector2NewScale(1, 1, BASE_GRID_SIZE));
    cells[tpl->cellLen++] = c2;

}

TM_Cell *Template_GetCell(Template *tpl, int typeID) {
    for (int i = 0; i < tpl->cellLen; i += 1) {
        if (tpl->cells[i].typeID == typeID) {
            return &tpl->cells[i];
        }
    }
    return NULL;
}

// - Monster
void Template_InitMonsters(Template *tpl) {
    tpl->monsterLen = 0;
    tpl->monsters = (TM_Monster *)malloc(sizeof(TM_Monster) * 50);

    TM_Monster *monsters = tpl->monsters;

    // Create: typeID, moveSpeed, hp, dropMoney, color, drawShapeType, drawSize
    TM_Monster m1 = TM_Monster_Create(1, 1, 100, 10, RED, SHAPE_TYPE_RECT, Vector2NewScale(1, 1, BASE_GRID_SIZE));
    monsters[tpl->monsterLen++] = m1;
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