#ifndef B_GAME_H__
#define B_GAME_H__
#include "Context.h"
#include "D_Cell.h"

// B: Business
// LifeCycle, 生命周期函数
void B_Game_Tick(Context *ctx, float dt) {}

void B_Game_Draw(Context *ctx) {
    int cellLen = ctx->rp_cell->count;
    for (int i = 0; i < cellLen; i++) {
        E_Cell *cell = ctx->rp_cell->all[i];
        E_Cell_Draw(cell);
    }
}

void B_Game_DrawUI(Context *ctx) {}

// 业务函数
void B_Game_Enter(Context *ctx) {

    // 生成格子
    for (int x = -20; x <= 20; x++) {
        for (int y = -11; y <= 11; y++) {
            Vector2 pos = Vector2New(x, y);
            pos = Vector2Scale(pos, BASE_GRID_SIZE);
            D_Cell_Spawn(ctx, 1, pos);
        }
    }

    // 生成生成器

    // 生成玩家状态: 可建造列表, 金钱, 生命值
}

#endif