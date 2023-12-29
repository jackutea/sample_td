#ifndef D_CELL_H__
#define D_CELL_H__
#include "Context.h"
#include "Factory.h"

// D: Domain
void D_Cell_Spawn(Context *ctx, int typeID, Vector2 pos) {
    // 1. Factory
    E_Cell *cell = Factory_Create_Cell(ctx, typeID, pos);

    // 2. Repository
    RP_Cell_Add(ctx->rp_cell, cell);
}

void D_Cell_Unspawn(Context *ctx, E_Cell *cell) {
    // 1. Repository
    RP_Cell_Remove(ctx->rp_cell, cell);

    // 2. Free
    free(cell);
}

#endif