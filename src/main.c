#include "..\include\raylib.h"
#include "..\include\raymath.h"
#include "B_Game.h"
#include "Context.h"
#include "D_Cell.h"
#include <stdio.h>
#include <stdlib.h>

void Init(Context *ctx);
void Free(Context *ctx);

int main() {

    Context *ctx = (Context *)calloc(1, sizeof(Context));
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
        B_Game_Tick(ctx, dt);

        // ==== Draw World ====
        BeginMode2D(*ctx->cam);
        B_Game_Draw(ctx);
        EndMode2D();

        // ==== Draw UI ====
        App_UI_Draw(ctx->ctx_ui);
        // B_Game_DrawUI(ctx);

        EndDrawing();
    }
    CloseWindow();
    Free(ctx);
    return 0;
}

void Init(Context *ctx) {

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

    // UI
    ContextUI *ctx_ui = (ContextUI *)calloc(1, sizeof(ContextUI));
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

void Free(Context *ctx) {
    Template_Free(ctx->tpl);
    RP_Cell_Free(ctx->rp_cell);
    App_UI_Free(ctx->ctx_ui);
    free(ctx->s_id);
    free(ctx);
}