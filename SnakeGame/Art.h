#pragma once
#include <vector>
#include <string>
#include <iostream>

class Art
{
public:
    static const std::vector<std::string>& GetWinText();

    static const std::vector<std::string>& GetGameOverText();

    static const std::vector<std::string>& GetCheatingText();

    static void PrintText(const std::vector<std::string>& text);

private:
    // —татические переменные дл€ хранени€ текстов
    static std::vector<std::string> text_win;
    static std::vector<std::string> text_gameOver;
    static std::vector<std::string> text_cheating;
};