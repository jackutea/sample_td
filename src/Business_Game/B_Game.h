#ifndef B_GAME_H__
#define B_GAME_H__
#include "D_Cave.h"
#include "D_Cell.h"
#include "D_Monster.h"
#include "import.h"

void B_Game_Enter(Ctx *ctx) {

    // Spawn: Cells
    TM_Level *level = Template_GetLevel(ctx->tpl, 1);
    for (int i = 0; i < level->cellCount; i++) {
        TM_CellGenerator *gen = &level->cellGenerators[i];
        Vector2 pos = gen->pos;
        pos = Vector2Scale(pos, BASE_GRID_SIZE);
        D_Cell_Spawn(ctx, gen->typeID, pos);
    }

    // Spawn: Caves
    for (int i = 0; i < level->caveGeneratorCount; i++) {
        TM_CaveGenerator *gen = &level->caveGenerators[i];
        Vector2 pos = gen->pos;
        D_Cave_Spawn(ctx, gen->typeID, pos);
    }

    // 生成玩家状态: 可建造列表, 金钱, 生命值
}

void B_Game_Tick(Ctx *ctx, float dt) {

    // - Cave
    RP_Cave *rp_cave = ctx->rp_cave;
    E_Cave **caves = NULL;
    int caveLen = RP_Cave_TakeAll(rp_cave, &caves);
    if (caveLen > 0) {
        assert(caves != NULL);
    }
    for (int i = 0; i < caveLen; i++) {
        E_Cave *cave = caves[i];
        D_Cave_TrySpawnMonster(ctx, cave, dt);
    }

    // - Monster
    RP_Monster *rp_monster = ctx->rp_monster;
    E_Monster **monsters = NULL;
    int monsterLen = RP_Monster_TakeAll(rp_monster, &monsters);
    for (int i = 0; i < monsterLen; i++) {
        E_Monster *monster = monsters[i];
        D_Monster_Move(ctx, monster, dt);
    }
}

void B_Game_Draw(Ctx *ctx) {
    // - Cell
    RP_Cell *rp_cell = ctx->rp_cell;
    int cellLen = rp_cell->count;
    for (int i = 0; i < cellLen; i++) {
        E_Cell *cell = rp_cell->all[i];
        E_Cell_Draw(cell);
    }

    // - Monster
    RP_Monster *rp_monster = ctx->rp_monster;
    int monsterLen = rp_monster->count;
    for (int i = 0; i < monsterLen; i++) {
        E_Monster *monster = rp_monster->all[i];
        E_Monster_Draw(monster);
    }
}

void B_Game_DrawUI(Ctx *ctx) {
}

#endif