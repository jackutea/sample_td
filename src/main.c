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
    Ctx_Init(_ctx);
}

void Tick(Ctx *_ctx, float dt) {
    B_Game_Tick(_ctx, dt);
}

void DrawWorld(Ctx *_ctx) {
    B_Game_Draw(_ctx);
}

void DrawUI(Ctx *_ctx) {
    App_UI_Draw(_ctx->ctx_ui);
}

void Free(Ctx *_ctx) {
    Ctx_Free(_ctx);
}