#ifndef CONTEXT_H__
#define CONTEXT_H__

#include "../include/raylib.h"
#include "Common.h"
#include "E_Cell.h"
#include "Template.h"
#include "S_ID.h"
#include "RP_Cell.h"
#include "App_UI.h"

typedef struct Context {
    // 40 * 22.5 格一屏
    int baseGameWidth;    // 960
    int baseGameHeight;   // 540

    Camera2D *cam;

    ContextUI *ctx_ui;

    // ==== Repository ====
    RP_Cell *rp_cell;

    // ==== Template ====
    Template *tpl;

    // ==== Service ====
    S_ID *s_id;

} Context;

#endif