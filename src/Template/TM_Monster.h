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

TM_Monster TM_Monster_Create(int typeID, float moveSpeed, int hp, int dropMoney, Color color, ShapeType drawShapeType, Vector2 drawSize) {
    TM_Monster monster;
    monster.typeID = typeID;
    monster.moveSpeed = moveSpeed;
    monster.hp = hp;
    monster.dropMoney = dropMoney;
    monster.color = color;
    monster.drawShapeType = drawShapeType;
    monster.drawSize = drawSize;
    return monster;
}

#endif