#ifndef PN_LOGIN_H__
#define PN_LOGIN_H__
#include "../include/GUI_Button.h"
#include "Common.h"

typedef struct PN_Login {
    GUI_Button btn_start;
} PN_Login;

void PN_Login_Ctor(PN_Login *panel) {
    panel->btn_start = GUI_Button_New(Vector2New(480, 270), Vector2New(160, 30), BLACK, GRAY, WHITE, "Login");
}

void PN_Login_Draw(PN_Login *panel) {
    GUI_Button_Draw(&panel->btn_start);
}

bool PN_Loign_IsStartClick(PN_Login *panel) {
    return GUI_Button_IsClick(&panel->btn_start);
}

#endif