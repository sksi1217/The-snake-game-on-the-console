#include "Color.h"

// ������������� ����������� ����������
const WORD Color::BLACK = 0;
const WORD Color::BLUE = FOREGROUND_BLUE;
const WORD Color::DARK_GREEN = FOREGROUND_GREEN;
const WORD Color::CYAN = FOREGROUND_BLUE | FOREGROUND_GREEN;
const WORD Color::RED = FOREGROUND_RED;
const WORD Color::MAGENTA = FOREGROUND_RED | FOREGROUND_BLUE;
const WORD Color::BROWN = FOREGROUND_RED | FOREGROUND_GREEN;
const WORD Color::LIGHT_GRAY = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
const WORD Color::DARK_GRAY = FOREGROUND_INTENSITY;
const WORD Color::LIGHT_BLUE = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
const WORD Color::LIGHT_GREEN = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
const WORD Color::LIGHT_CYAN = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
const WORD Color::LIGHT_RED = FOREGROUND_RED | FOREGROUND_INTENSITY;
const WORD Color::LIGHT_MAGENTA = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
const WORD Color::YELLOW = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
const WORD Color::WHITE = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
const WORD Color::ORANGE = FOREGROUND_RED | FOREGROUND_GREEN;
const WORD Color::LIGHT_ORANGE = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;

// ��������� ����� ������
void Color::SetTextColor(WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(hConsole, &info);

    // ��������� ������� ��� � ������������� ����� ���� ������
    SetConsoleTextAttribute(hConsole, (info.wAttributes & 0xF0) | (color & 0x0F));
}

// ����������� � ����������� ������
void Color::ResetColors() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}