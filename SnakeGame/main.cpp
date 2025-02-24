#include "Game.h"
#include <iostream>

int main() {
    Game game;

    while (true) {
        game.Start(); // Начало новой игры
        game.Update(); // Игровой цикл

        if (!game.IsGame) {
            char selection;
            std::cout << "Do you want to exit the game? (Y/N): ";
            std::cin >> selection;

            if (selection == 'Y' || selection == 'y' || selection == 'н') {
                std::cout << "Thank you for playing!" << std::endl;
                break;
            }
        }
    }

    return 0;
}