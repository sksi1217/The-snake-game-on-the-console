#include "Game.h"
#include <iostream>

void Game::Start() {
	system("mode con: cols=51 lines=23");

	Color::SetTextColor(Color::BROWN);

	Setting::HideCursor();
	Setting::sizeWindow();

	int consoleWidth = Setting::getConsoleWidth();
	int consoleHeight = Setting::getConsoleHeight();
	int centerX = consoleWidth / 2;
	int centerY = consoleHeight / 2;

	centerX -= 1;

	snake._headPosition.X = centerX;
	snake._headPosition.Y = centerY;

	GenerateItem();
}

void Game::Update() {
	while (IsGame) {
		Info();
		MapBorder();

		// Обработка ввода, обновление змеи, проверка столкновений
		HandleInput();
		snake.Update();

		CheckCollision();

		snake.Draw();
		item.Draw();

		Sleep(100); // Задержка между кадрами
	}
	ResetGame();
}

void Game::HandleInput() {
	if (_kbhit()) {
		char input = _getch();
		if (
			(input == 'd' && snake._lastKeyPressed != 'a') ||
			(input == 'a' && snake._lastKeyPressed != 'd') ||
			(input == 'w' && snake._lastKeyPressed != 's') ||
			(input == 's' && snake._lastKeyPressed != 'w'))
		{
			snake._lastKeyPressed = input;
		}
		else if ((input == 'r'))
		{
			IsGame = false;
		}
	}
}

void Game::CheckCollision() {
	if (snake.CheckCollision(snake._headPosition)) {
		IsGame = false;
		//ResetGame();
	}

	if (snake._headPosition.X == item._itemPosition.X && snake._headPosition.Y == item._itemPosition.Y)
	{
		GenerateItem();
		snake.Grow();
	}
}

void Game::GenerateItem() {
	item.SetPosition(Setting::generatePosistion(2, 24) * 2, Setting::generatePosistion(1, 18));
}

void Game::ResetGame() {
	bool restart = false;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0, 0 });

	for (size_t i = 0; i < Setting::getConsoleHeight(); ++i) {
		std::cout << std::string(Setting::getConsoleWidth(), ' ') << "\n";
	}

	std::vector<std::string> text = {
		" _____                     _____                ",
		"|   __| ___  _____  ___   |     | _ _  ___  ___ ",
		"|  |  || .'||     || -_|  |  |  || | || -_||  _|",
		"|_____||__,||_|_|_||___|  |_____| \\_/ |___||_|  "
	};

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0, 0 });
	for (const auto& line : text) {
		std::cout << line << "\n";
	}
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0, 5 });
	std::cout << "Your score: " << snake._lengthSnake << std::endl;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0, 7 });

	char selection;
	while (true) {
		std::cout << "You lost!" << std::endl
			<< "Play again?" << std::endl
			<< "Y(Yes)/N(No): ";
		std::cin >> selection;

		if (selection == 'Y' || selection == 'y' || selection == 'д') {
			restart = true; // Флаг для перезапуска
			break;
		}
		else if (selection == 'N' || selection == 'n' || selection == 'н') {
			break;
		}
		else {
			std::cout << std::endl << "Invalid input! Please enter Y(Yes) or N(No)." << std::endl;
		}
	}

	if (restart) {
		IsGame = true;
	}
	else {
		IsGame = false;
	}
}

void Game::MapBorder() {
	// Устанавливаем цвет
	Color::SetTextColor(Color::DARK_GRAY);
	// Верхняя граница
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0, 0 });
	std::cout << std::string(Setting::getConsoleWidth(), '~');

	// Нижние границы
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0, 19 });
	std::cout << std::string(Setting::getConsoleWidth(), '~');
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0, 22 });
	std::cout << std::string(Setting::getConsoleWidth(), '~');

	// Левая и правая границы
	for (size_t i = 0; i < Setting::getConsoleHeight(); ++i) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 1, (short)i });
		std::cout << "|";
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 49, (short)i });
		std::cout << "|";
	}
	Color::ResetColors();
}

void Game::Info() {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 2, 20 });
	// Устанавливаем цвет
	Color::SetTextColor(Color::LIGHT_MAGENTA);
	std::cout << "Score: ";
	Color::ResetColors();

	// Устанавливаем цвет
	Color::SetTextColor(Color::MAGENTA);
	std::cout << snake._lengthSnake << std::string(30, ' ');
	Color::ResetColors();

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 2, 21 });
	Color::SetTextColor(Color::CYAN);
	std::cout << "Position Apple: ";
	Color::ResetColors();

	Color::SetTextColor(Color::LIGHT_CYAN);
	std::cout << "X: ";
	Color::ResetColors();

	Color::SetTextColor(Color::BROWN);
	std::cout << item._itemPosition.X; // Pos Item
	Color::ResetColors();

	Color::SetTextColor(Color::LIGHT_CYAN);
	std::cout << " Y: ";
	Color::ResetColors();


	Color::SetTextColor(Color::BROWN);
	std::cout << item._itemPosition.Y << std::string(31, ' ');
	Color::ResetColors();
}