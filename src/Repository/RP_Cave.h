#ifndef RP_CAVE_H__
#define RP_CAVE_H__

#include "import.h"

typedef struct RP_Cave {
    E_Cave **all;
    int count;
    int capacity;
    E_Cave **temp_all;
} RP_Cave;

void RP_Cave_Init(RP_Cave *rp) {
    rp->capacity = 100;
    rp->count = 0;
    rp->all = (E_Cave **)malloc(sizeof(E_Cave *) * rp->capacity);
    rp->temp_all = (E_Cave **)malloc(sizeof(E_Cave *) * rp->capacity);
}

void RP_Cave_Free(RP_Cave *rp) {
    for (int i = 0; i < rp->count; i++) {
        E_Cave_Free(rp->all[i]);
    }
    free(rp->all);
    free(rp->temp_all);
    free(rp);
}

void RP_Cave_Add(RP_Cave *rp, E_Cave *cave) {
    if (rp->count == rp->capacity) {
        rp->capacity *= 2;
        rp->all = (E_Cave **)realloc(rp->all, sizeof(E_Cave *) * rp->capacity);
        rp->temp_all = (E_Cave **)realloc(rp->temp_all, sizeof(E_Cave *) * rp->capacity);
    }
    rp->all[rp->count++] = cave;
}

void RP_Cave_Remove(RP_Cave *rp, E_Cave *cave) {
    int index = -1;
    for (int i = 0; i < rp->count; i++) {
        if (rp->all[i] == cave) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        return;
    }
    rp->all[index] = rp->all[rp->count - 1];
    rp->count--;
}

int RP_Cave_TakeAll(RP_Cave *rp, E_Cave ***out_all) {
    for (int i = 0; i < rp->count; i++) {
        rp->temp_all[i] = rp->all[i];
    }
    *out_all = rp->temp_all;
    return rp->count;
}

#endif