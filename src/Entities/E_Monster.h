#ifndef E_MONSTER_H__
#define E_MONSTER_H__
#include "../Common.h"

typedef struct E_Monster {
    
    int id;
    int typeID;

    Vector2 pos;
    Vector2 moveDir;
    float moveSpeed;

    int hp;
    int hpMax;

    Color color;
    ShapeType drawShape;
    Vector2 drawSize;

} E_Monster;

#endif