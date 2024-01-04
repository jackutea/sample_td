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

void E_Monster_Free(E_Monster *mst) {
    free(mst);
}

void E_Monster_Move(E_Monster *mst, float dt) {
    Vector2 moveDiff = Vector2Scale(mst->moveDir, mst->moveSpeed * dt);
    mst->pos = Vector2Add(mst->pos, moveDiff);
}

void E_Monster_Draw(E_Monster *mst) {
    DrawByShapeType(mst->drawShape, mst->pos, mst->drawSize, mst->color);
}

#endif