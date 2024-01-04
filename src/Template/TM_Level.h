#ifndef TM_LEVEL_H__
#define TM_LEVEL_H__

#include "import.h"

// Cell 生成器
typedef struct TM_CellGenerator {
    int typeID;
    Vector2 pos;
} TM_CellGenerator;

TM_CellGenerator TM_CellGenerator_Create(int typeID, Vector2 pos) {
    TM_CellGenerator cellGenerator;
    cellGenerator.typeID = typeID;
    cellGenerator.pos = pos;
    return cellGenerator;
}

// Cave 生成器
typedef struct TM_CaveGenerator {
    int typeID;
    Vector2 pos;
} TM_CaveGenerator;

TM_CaveGenerator TM_CaveGenerator_Create(int typeID, Vector2 pos) {
    TM_CaveGenerator caveGenerator;
    caveGenerator.typeID = typeID;
    caveGenerator.pos = pos;
    return caveGenerator;
}

// ==== 游戏关卡 ====
typedef struct TM_Level {

    int typeID;
    Vector2 size;

    TM_CellGenerator *cellGenerators;
    int cellCount;

    TM_CaveGenerator *caveGenerators;
    int caveGeneratorCount;

} TM_Level;

void TM_Level_Free(TM_Level *level) {
    free(level->cellGenerators);
    free(level->caveGenerators);
    free(level);
}

#endif