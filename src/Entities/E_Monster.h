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

void E_Monster_Draw(E_Monster *mst) {
    Vector2 center = mst->pos;
    center = Vector2Subtract(center, Vector2Scale(mst->drawSize, 0.5f));
    if (mst->drawShape == SHAPE_TYPE_CIRCLE) {
        DrawCircleV(center, mst->drawSize.x / 2, mst->color);
    } else if (mst->drawShape == SHAPE_TYPE_RECT) {
        DrawRectangleV(center, mst->drawSize, mst->color);
    } else {
        printf("err E_Monster_Draw: shapeType error\n");
    }
}

#endif