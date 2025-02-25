#pragma once
#include <windows.h>
#include <random>

class Setting {
public:
    static HANDLE hConsole;
    static WORD originalColor;

    static int getConsoleWidth();

    static int getConsoleHeight();

    static int generatePosistion(int min, int max);

    static void HideCursor();

    static void sizeWindow();
};