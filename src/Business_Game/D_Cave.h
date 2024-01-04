#ifndef D_CAVE_H__
#define D_CAVE_H__
#include "import.h"
#include "D_Monster.h"

void D_Cave_Spawn(Ctx *ctx, int typeID, Vector2 pos) {
    E_Cave *cave = Factory_Create_Cave(ctx, typeID, pos);
    RP_Cave_Add(ctx->rp_cave, cave);
}

void D_Cave_Unspawn(Ctx *ctx, E_Cave *cave) {
    RP_Cave_Remove(ctx->rp_cave, cave);
    E_Cave_Free(cave);
}

void D_Cave_TrySpawnMonster(Ctx *ctx, E_Cave *cave, float dt) {

    if (cave->cd > 0) {
        cave->cd -= dt;
        return;
    }

    cave->spawnIntervalTimer -= dt;
    if (cave->spawnIntervalTimer <= 0) {
        cave->spawnIntervalTimer += cave->spawnInterval;
        // 生成怪物
        E_Monster *mst = D_Monster_Spawn(ctx, cave->spawnMonsterTypeID, cave->spawnPos);
        mst->moveDir = Vector2New(0, -1);
    }

    cave->spawnMaintainTimer -= dt;
    if (cave->spawnMaintainTimer <= 0) {
        // 重置计时器
        cave->spawnMaintainTimer += cave->spawnMaintain;
        cave->cd += cave->cdMax;
        return;
    }

}

#endif