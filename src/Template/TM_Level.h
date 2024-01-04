#ifndef TM_LEVEL_H__
#define TM_LEVEL_H__

#include "import.h"

// 游戏关卡
typedef struct TM_Level {
    int typeID;
    Vector2 size;
    Vector2 *cellPoses;
    int cellCount;
} TM_Level;

void TM_Level_Free(TM_Level *level) {
    free(level->cellPoses);
    free(level);
}

#endif