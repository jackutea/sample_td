#define RAYGUI_IMPLEMENTATION
#include "Business_Game/export.h"
#include <stdio.h>
#include <stdlib.h>

void Init(Ctx *_ctx);
void Tick(Ctx *_ctx, float dt);
void DrawWorld(Ctx *_ctx);
void DrawUI(Ctx *_ctx);
void Free(Ctx *_ctx);

static Ctx *ctx;

int main() {

    ctx = (Ctx *)calloc(1, sizeof(Ctx));
    Init(ctx);

    InitWindow(ctx->baseGameWidth, ctx->baseGameHeight, "cyh");
    SetTargetFPS(60);

    // ==== Enter ====
    App_UI_Login_Open(ctx->ctx_ui);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        float dt = GetFrameTime();

        // ==== Input ====
        if (App_UI_Login_IsStartClick(ctx->ctx_ui)) {
            App_UI_Login_Close(ctx->ctx_ui);
            B_Game_Enter(ctx);
        }

        // ==== Logic Tick ====
        Tick(ctx, dt);

        // ==== Draw World ====
        BeginMode2D(*ctx->cam);
        DrawWorld(ctx);
        EndMode2D();

        // ==== Draw UI ====
        DrawUI(ctx);

        EndDrawing();
    }
    CloseWindow();
    Free(ctx);
    return 0;
}

void Init(Ctx *_ctx) {

    _ctx->baseGameWidth = 960;
    _ctx->baseGameHeight = 540;

    // Camera
    Camera2D *cam = (Camera2D *)calloc(1, sizeof(Camera2D));
    cam->offset = (Vector2){_ctx->baseGameWidth / 2, _ctx->baseGameHeight / 2};
    cam->target = (Vector2){0, 0};
    cam->rotation = 0;
    cam->zoom = 1;
    _ctx->cam = cam;

    // Repository
    RP_Cell *rp_cell = (RP_Cell *)calloc(1, sizeof(RP_Cell));
    RP_Cell_Init(rp_cell);
    _ctx->rp_cell = rp_cell;

    // UI
    Ctx_UI *ctx_ui = (Ctx_UI *)calloc(1, sizeof(Ctx_UI));
    _ctx->ctx_ui = ctx_ui;

    // Template
    Template *tpl = (Template *)calloc(1, sizeof(Template));
    Template_Init(tpl);
    _ctx->tpl = tpl;
    _ctx->ctx_ui->tpl = tpl;

    // Service
    S_ID *s_id = (S_ID *)calloc(1, sizeof(S_ID));
    _ctx->s_id = s_id;
}

void Tick(Ctx *_ctx, float dt) {
    B_Game_Tick(ctx, dt);
}

void DrawWorld(Ctx *_ctx) {
    B_Game_Draw(ctx);
}

void DrawUI(Ctx *_ctx) {
    App_UI_Draw(ctx->ctx_ui);
}

void Free(Ctx *_ctx) {
    Template_Free(_ctx->tpl);
    RP_Cell_Free(_ctx->rp_cell);
    App_UI_Free(_ctx->ctx_ui);
    free(_ctx->s_id);
    free(_ctx);
}