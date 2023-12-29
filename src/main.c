#include "..\include\raylib.h"
#include "..\include\raymath.h"
#include "Context.h"
#include <stdio.h>
#include <stdlib.h>

void Init(Context *ctx);
void Free(Context *ctx);

int main() {

    Context *ctx = (Context *)malloc(sizeof(Context));
    Init(ctx);
    InitWindow(ctx->windowWidth, ctx->windowHeight, "cyh");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // ==== Input ====

        // ==== Logic Tick ====

        // ==== Draw World ====
        BeginMode2D(*ctx->cam);
        DrawCircleV(Vector2Zero(), 10, RED);
        EndMode2D();
        // ==== Draw UI ====

        float dt = GetFrameTime();

        EndDrawing();
    }
    CloseWindow();
    Free(ctx);
    return 0;
}

void Init(Context *ctx) {

    ctx->windowWidth = 800;
    ctx->windowHeight = 600;

    Camera2D *cam = (Camera2D *)malloc(sizeof(Camera2D));
    cam->offset = (Vector2){ctx->windowWidth / 2, ctx->windowHeight / 2};
    cam->target = (Vector2){0, 0};
    cam->rotation = 0;
    cam->zoom = 1;
    ctx->cam = cam;
}

void Free(Context *ctx) { free(ctx); }