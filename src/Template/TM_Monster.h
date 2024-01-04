#ifndef TM_MONSTER_H__
#define TM_MONSTER_H__

#include "import.h"

typedef struct TM_Monster {

    int typeID;

    float moveSpeed;

    int hp;

    int dropMoney;

    Color color;
    ShapeType drawShapeType;
    Vector2 drawSize;

} TM_Monster;

#endif