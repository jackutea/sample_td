#ifndef D_MONSTER_H__
#define D_MONSTER_H__
#include "import.h"

E_Monster *D_Monster_Spawn(Ctx *ctx, int typeID, Vector2 pos) {
    E_Monster *monster = Factory_Create_Monster(ctx, typeID, pos);
    RP_Monster_Add(ctx->rp_monster, monster);
    return monster;
}

void D_Monster_Unspawn(Ctx *ctx, E_Monster *monster) {
    RP_Monster_Remove(ctx->rp_monster, monster);
    E_Monster_Free(monster);
}

void D_Monster_Move(Ctx *ctx, E_Monster *monster, float dt) {
    E_Monster_Move(monster, dt);
}

#endif