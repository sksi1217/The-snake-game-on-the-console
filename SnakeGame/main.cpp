#include "Game.h"
#include <iostream>

int main() {
    Game game;

    while (true) {
        game.Start(); // Начало новой игры
        game.Update(); // Игровой цикл

        if (!game.IsGame) {
            char selection;
            Color::SetTextColor(Color::RED);
            std::cout << ">:( ";
            Color::ResetColors();

            Color::SetTextColor(Color::LIGHT_GREEN);
            std::cout << "Do you want to exit the game? " << std::endl;
            Color::ResetColors();

            Color::SetTextColor(Color::LIGHT_CYAN);
            std::cout << "Y(Yes)/N(No): ";
            Color::ResetColors();

            Color::SetTextColor(Color::DARK_GREEN);
            std::cin >> selection;
            Color::ResetColors();

            if (selection == 'Y' || selection == 'y') {
                break;
            }
        }
    }

    return 0;
}