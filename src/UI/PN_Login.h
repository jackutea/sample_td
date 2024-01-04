#ifndef PN_LOGIN_H__
#define PN_LOGIN_H__
#include "../Common.h"

typedef struct PN_Login {
    Rectangle start_rect;
    string start_text;
    bool is_start_click;
} PN_Login;

void PN_Login_Ctor(PN_Login *panel) {
    panel->start_rect = RectangleNewV(Vector2New(480, 270), Vector2New(160, 30));
    panel->start_text = "Start";
}

void PN_Login_Draw(PN_Login *panel) {
    panel->is_start_click = (bool)GuiButton(panel->start_rect, panel->start_text);
}

bool PN_Loign_IsStartClick(PN_Login *panel) {
    return panel->is_start_click;
}

#endif