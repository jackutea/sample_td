#ifndef RP_MONSTER_H__
#define RP_MONSTER_H__
#include "import.h"

typedef struct RP_Monster {
    E_Monster **all;
    int count;
    int capacity;

    E_Monster **temp_all;
} RP_Monster;

void RP_Monster_Init(RP_Monster *rp) {
    int capacity = 1000;
    rp->capacity = capacity;
    rp->all = (E_Monster **)calloc(capacity, sizeof(E_Monster *));
    rp->count = 0;

    rp->temp_all = (E_Monster **)calloc(capacity, sizeof(E_Monster *));
}

void RP_Monster_Add(RP_Monster *rp, E_Monster *monster) {
    rp->all[rp->count] = monster;
    rp->count++;
    // 扩容
    if (rp->count >= rp->capacity) {
        rp->capacity *= 2;
        // 保留原来的数据, 重新分配更大的内存
        rp->all = (E_Monster **)realloc(rp->all, rp->capacity * sizeof(E_Monster *));
    }
}

void RP_Monster_Remove(RP_Monster *rp, E_Monster *monster) {
    // 1. 找到要删除的元素
    int index = -1;
    for (int i = 0; i < rp->count; i++) {
        if (rp->all[i] == monster) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        return;
    }

    // 2. 交换式删除元素
    rp->all[index] = rp->all[rp->count - 1];
    rp->count--;
}

E_Monster *RP_Monster_Get(RP_Monster *rp, int id) {
    for (int i = 0; i < rp->count; i++) {
        if (rp->all[i]->id == id) {
            return rp->all[i];
        }
    }
    return NULL;
}

#endif