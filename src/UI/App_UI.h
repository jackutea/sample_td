#ifndef APP_UI_H__
#define APP_UI_H__
#include "../Template/export.h"
#include "PN_Login.h"
#include <stdlib.h>

typedef struct Ctx_UI {

    PN_Login *pn_login;

    // ==== External ====
    Template *tpl;

} Ctx_UI;

void App_UI_Free(Ctx_UI *ctx) {
    if (ctx->pn_login != NULL) {
        PN_Login_Free(ctx->pn_login);
        ctx->pn_login = NULL;
    }
    free(ctx);
}

void App_UI_Draw(Ctx_UI *ctx) {
    if (ctx->pn_login != NULL) {
        PN_Login_Draw(ctx->pn_login);
    }
}

// Panel: Login
void App_UI_Login_Open(Ctx_UI *ctx) {
    PN_Login *panel = (PN_Login *)calloc(1, sizeof(PN_Login));
    PN_Login_Ctor(panel);
    ctx->pn_login = panel;
}

bool App_UI_Login_IsStartClick(Ctx_UI *ctx) {
    PN_Login *panel = ctx->pn_login;
    if (panel != NULL) {
        return PN_Loign_IsStartClick(panel);
    }
    return false;
}

void App_UI_Login_Close(Ctx_UI *ctx) {
    if (ctx->pn_login != NULL) {
        PN_Login_Free(ctx->pn_login);
        ctx->pn_login = NULL;
    }
}

// Panel: Manifest
// Open / Close
// AddElement(ContextUI *ctx, int typeID)
// int PN_Manifest_ClickElementTypeID(ContextUI *ctx)

#endif