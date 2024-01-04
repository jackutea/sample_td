#ifndef RP_CELL_H__
#define RP_CELL_H__
#include <stdlib.h>
#include "import.h"

typedef struct RP_Cell {
    E_Cell **all;
    int count;
    E_Cell **tempArray;
} RP_Cell;

void RP_Cell_Init(RP_Cell *rp) {
    rp->all = (E_Cell **)calloc(40 * 23 * 10, sizeof(E_Cell *));
    rp->tempArray = (E_Cell **)calloc(40 * 23 * 10, sizeof(E_Cell *));
    printf("%d", sizeof(E_Cell *));
    rp->count = 0;
}

void RP_Cell_Free(RP_Cell *rp) {
    for (int i = 0; i < rp->count; i++) {
        free(rp->all[i]);
    }
    free(rp->all);
    free(rp);
}

void RP_Cell_Add(RP_Cell *rp, E_Cell *cell) {
    rp->all[rp->count++] = cell;
}

void RP_Cell_Remove(RP_Cell *rp, E_Cell *cell) {
    for (int i = 0; i < rp->count; i++) {
        if (rp->all[i]->id == cell->id) {
            rp->all[i] = rp->all[rp->count];
            rp->count--;
            return;
        }
    }
}

E_Cell *RP_Cell_Get(RP_Cell *rp, int id) {
    for (int i = 0; i < rp->count; i++) {
        if (rp->all[i]->id == id) {
            return rp->all[i];
        }
    }
    return NULL;
}

int RP_Cell_GetAll(RP_Cell *rp, E_Cell **result) {
    for (int i = 0; i < rp->count; i++) {
        rp->tempArray[i] = rp->all[i];
    }
    result = rp->tempArray;
    return rp->count;
}

#endif