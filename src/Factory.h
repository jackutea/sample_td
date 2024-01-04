#ifndef FACTORY_H__
#define FACTORY_H__
#include "Ctx.h"

E_Cell *Factory_Create_Cell(Ctx *ctx, int typeID, Vector2 pos) {

    TM_Cell *tm = Template_GetCell(ctx->tpl, typeID);
    if (tm == NULL) {
        printf("err : Template_GetCell() return NULL\n");
        return NULL;
    }

    E_Cell *cell = (E_Cell *)malloc(sizeof(E_Cell));
    cell->id = ctx->s_id->cellIDRecord++;
    cell->typeID = typeID;
    cell->pos = pos;
    cell->shapeType = tm->shapeType;
    cell->size = tm->size;
    cell->color = tm->color;

    return cell;
}

E_Cave *Factory_Create_Cave(Ctx *ctx, int typeID, Vector2 pos) {

    TM_Cave *tm = Template_GetCave(ctx->tpl, typeID);
    if (tm == NULL) {
        printf("err : Template_GetCave() return NULL\n");
        return NULL;
    }

    E_Cave *cave = (E_Cave *)malloc(sizeof(E_Cave));
    cave->id = ctx->s_id->caveIDRecord++;
    cave->typeID = typeID;
    cave->spawnPos = pos;
    cave->cd = tm->cd;
    cave->cdMax = tm->cd;
    cave->spawnMaintain = tm->spawnMaintain;
    cave->spawnMaintainTimer = tm->spawnMaintain;
    cave->spawnInterval = tm->spawnInterval;
    cave->spawnIntervalTimer = tm->spawnInterval;
    cave->spawnMonsterTypeID = tm->spawnMonsterTypeID;

    return cave;
}

E_Monster *Factory_Create_Monster(Ctx *ctx, int typeID, Vector2 pos) {

    TM_Monster *tm = Template_GetMonster(ctx->tpl, typeID);
    if (tm == NULL) {
        printf("err : Template_GetMonster() return NULL\n");
        return NULL;
    }

    E_Monster *mst = (E_Monster *)malloc(sizeof(E_Monster));
    mst->id = ctx->s_id->mstIDRecord++;
    mst->typeID = typeID;
    mst->pos = pos;
    mst->moveDir = Vector2Zero();
    mst->moveSpeed = tm->moveSpeed;
    mst->hp = tm->hp;
    mst->hpMax = tm->hp;
    mst->color = tm->color;
    mst->drawShape = tm->drawShapeType;
    mst->drawSize = tm->drawSize;

    return mst;
}

#endif