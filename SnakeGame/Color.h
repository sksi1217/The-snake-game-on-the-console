#pragma once
#include <windows.h>

class Color {
public:
    static const WORD BLACK;
    static const WORD BLUE;
    static const WORD DARK_GREEN;
    static const WORD CYAN;
    static const WORD RED;
    static const WORD MAGENTA;
    static const WORD BROWN;
    static const WORD LIGHT_GRAY;
    static const WORD DARK_GRAY;
    static const WORD LIGHT_BLUE;
    static const WORD LIGHT_GREEN;
    static const WORD LIGHT_CYAN;
    static const WORD LIGHT_RED;
    static const WORD LIGHT_MAGENTA;
    static const WORD YELLOW;
    static const WORD WHITE;
    static const WORD ORANGE;
    static const WORD LIGHT_ORANGE;

    static void SetTextColor(WORD color);
    static void ResetColors();
};