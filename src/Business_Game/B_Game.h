#ifndef B_GAME_H__
#define B_GAME_H__
#include "D_Cell.h"
#include "import.h"

void B_Game_Enter(Ctx *ctx) {

    // 生成格子
    TM_Level *level = Template_GetLevel(ctx->tpl, 1);
    for (int i = 0; i < level->cellCount; i++) {
        Vector2 pos = level->cellPoses[i];
        pos = Vector2Scale(pos, BASE_GRID_SIZE);
        D_Cell_Spawn(ctx, 1, pos);
    }

    // 生成生成器

    // 生成玩家状态: 可建造列表, 金钱, 生命值
}

void B_Game_Tick(Ctx *ctx, float dt) {
}

void B_Game_Draw(Ctx *ctx) {
    int cellLen = ctx->rp_cell->count;
    for (int i = 0; i < cellLen; i++) {
        E_Cell *cell = ctx->rp_cell->all[i];
        E_Cell_Draw(cell);
    }
}

void B_Game_DrawUI(Ctx *ctx) {
}

#endif