#pragma once
#include <windows.h>

class Color {
public:
    // Определение базовых цветов
    static const WORD BLACK;            // Черный
    static const WORD BLUE;             // Синий
    static const WORD GREEN;            // Зеленый
    static const WORD DARK_GREEN;       // Зеленый (темно-зеленый)
    static const WORD CYAN;             // Голубой
    static const WORD RED;              // Красный
    static const WORD MAGENTA;          // Фиолетовый
    static const WORD BROWN;            // Коричневый
    static const WORD LIGHT_GRAY;       // Светло-серый
    static const WORD DARK_GRAY;        // Темно-серый
    static const WORD LIGHT_BLUE;       // Светло-синий
    static const WORD LIGHT_GREEN;      // Светло-зеленый
    static const WORD LIGHT_CYAN;       // Светло-голубой
    static const WORD LIGHT_RED;        // Светло-красный
    static const WORD LIGHT_MAGENTA;    // Светло-фиолетовый
    static const WORD YELLOW;           // Желтый
    static const WORD WHITE;            // Белый
    static const WORD ORANGE;           // Оранжевый
    static const WORD LIGHT_ORANGE;     // Оранжевый

    // Установка цвета текста и фона
    static void SetTextColor(WORD color);
    static void ResetColors(); // Возвращение к стандартным цветам
};