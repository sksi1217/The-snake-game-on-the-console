#pragma once
#include <vector>
#include <string>
#include <iostream>

class Art
{
public:
    // Метод для получения текста победы
    static const std::vector<std::string>& GetWinText();

    // Метод для получения текста Game Over
    static const std::vector<std::string>& GetGameOverText();

    // Метод для получения текста читерства
    static const std::vector<std::string>& GetCheatingText();

    // Метод для вывода текста на экран
    static void PrintText(const std::vector<std::string>& text);

private:
    // Статические переменные для хранения текстов
    static std::vector<std::string> text_win;
    static std::vector<std::string> text_gameOver;
    static std::vector<std::string> text_cheating;
};