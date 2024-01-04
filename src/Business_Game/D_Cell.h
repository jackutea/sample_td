#ifndef D_CELL_H__
#define D_CELL_H__
#include "import.h"

void D_Cell_Spawn(Ctx *ctx, int typeID, Vector2 pos) {
    E_Cell *cell = Factory_Create_Cell(ctx, typeID, pos);
    RP_Cell_Add(ctx->rp_cell, cell);
}

void D_Cell_Unspawn(Ctx *ctx, E_Cell *cell) {
    RP_Cell_Remove(ctx->rp_cell, cell);
    E_Cell_Free(cell);
}
#endif