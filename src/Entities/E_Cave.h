#ifndef E_LEVEL_H__
#define E_LEVEL_H__

#include "import.h"

typedef struct E_Cave {

    int id;
    int typeID;

    Vector2 spawnPos;
    float cd;
    float cdMax;
    float spawnMaintain;
    float spawnMaintainTimer;
    float spawnInterval;
    float spawnIntervalTimer;
    int spawnMonsterTypeID;

} E_Level;

#endif