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

    // ==== Template ====
    Template *tpl;

    // ==== Service ====
    S_ID *s_id;

} Ctx;

#endif