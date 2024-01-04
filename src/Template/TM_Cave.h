#ifndef TM_CAVE_H__
#define TM_CAVE_H__

#include "import.h"

typedef struct TM_Cave {

    int typeID;

    float cd;

    float spawnMaintain;
    float spawnInterval;
    int spawnMonsterTypeID;

} TM_Cave;

TM_Cave TM_Cave_Create(int typeID, float cd, float spawnMaintain, float spawnInterval, int spawnMonsterTypeID) {

    TM_Cave cave;

    cave.typeID = typeID;

    cave.cd = cd;

    cave.spawnMaintain = spawnMaintain;
    cave.spawnInterval = spawnInterval;
    cave.spawnMonsterTypeID = spawnMonsterTypeID;

    return cave;

}

#endif