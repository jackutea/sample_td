#ifndef CONTEXT_H__
#define CONTEXT_H__

#include "Common.h"
#include "Entities/export.h"
#include "Repository/export.h"
#include "Template/export.h"
#include "Service/export.h"
#include "UI/export.h"

typedef struct Ctx {
    // 40 * 22.5 格一屏
    int baseGameWidth;    // 960
    int baseGameHeight;   // 540

    Camera2D *cam;

    Ctx_UI *ctx_ui;

    // ==== Repository ====
    RP_Cell *rp_cell;
    RP_Monster *rp_monster;
    RP_Cave *rp_cave;

    // ==== Template ====
    Template *tpl;

    // ==== Service ====
    S_ID *s_id;

} Ctx;

void Ctx_Init(Ctx *ctx) {
    ctx->baseGameWidth = 960;
    ctx->baseGameHeight = 540;

    // Camera
    Camera2D *cam = (Camera2D *)calloc(1, sizeof(Camera2D));
    cam->offset = (Vector2){ctx->baseGameWidth / 2, ctx->baseGameHeight / 2};
    cam->target = (Vector2){0, 0};
    cam->rotation = 0;
    cam->zoom = 1;
    ctx->cam = cam;

    // Repository
    RP_Cell *rp_cell = (RP_Cell *)calloc(1, sizeof(RP_Cell));
    RP_Cell_Init(rp_cell);
    ctx->rp_cell = rp_cell;

    RP_Monster *rp_monster = (RP_Monster *)calloc(1, sizeof(RP_Monster));
    RP_Monster_Init(rp_monster);
    ctx->rp_monster = rp_monster;

    RP_Cave *rp_cave = (RP_Cave *)calloc(1, sizeof(RP_Cave));
    RP_Cave_Init(rp_cave);
    ctx->rp_cave = rp_cave;

    // UI
    Ctx_UI *ctx_ui = (Ctx_UI *)calloc(1, sizeof(Ctx_UI));
    ctx->ctx_ui = ctx_ui;

    // Template
    Template *tpl = (Template *)calloc(1, sizeof(Template));
    Template_Init(tpl);
    ctx->tpl = tpl;
    ctx->ctx_ui->tpl = tpl;

    // Service
    S_ID *s_id = (S_ID *)calloc(1, sizeof(S_ID));
    ctx->s_id = s_id;
}

void Ctx_Free(Ctx *ctx) {
    Template_Free(ctx->tpl);
    RP_Cell_Free(ctx->rp_cell);
    RP_Monster_Free(ctx->rp_monster);
    RP_Cave_Free(ctx->rp_cave);
    App_UI_Free(ctx->ctx_ui);
    free(ctx->s_id);
    free(ctx);
}

#endif