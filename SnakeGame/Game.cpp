#include "Game.h"
#include "Art.h"
#include <iostream>

void Game::Start() {
	system("mode con: cols=51 lines=23");

	snake._lengthSnake = 0;
	snake._tail.clear();
	snake._lastKeyPressed = 'w';

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

		HandleInput();
		snake.Update();

		CheckCollision();

		snake.Draw();
		item.Draw();

		Sleep(100);
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
	}

	if (snake._headPosition.X == item._itemPosition.X && snake._headPosition.Y == item._itemPosition.Y)
	{
		GenerateItem();
		snake.Grow();
	}
}

void Game::GenerateItem() {
	COORD Item;
	bool isPositionValid = false;

	if (snake._lengthSnake < 431)
	{
		while (!isPositionValid) {
			Item.X = Setting::generatePosistion(2, 24) * 2;
			Item.Y = Setting::generatePosistion(1, 18);

			isPositionValid = true;

			for (const auto& segment : snake._tail) {
				if (segment.X == Item.X && segment.Y == Item.Y) {
					isPositionValid = false;
					break;
				}
			}

			if (snake._headPosition.X == Item.X && snake._headPosition.Y == Item.Y) {
				isPositionValid = false;
			}
		}

		item.SetPosition(Item.X, Item.Y);
	}
	else
	{
		IsGame = false;
	}
}

void Game::ResetGame() {
	std::vector<std::string> text;
	bool restart = false;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0, 0 });
	for (size_t i = 0; i < Setting::getConsoleHeight(); ++i) {
		std::cout << std::string(Setting::getConsoleWidth(), ' ') << "\n";
	}

	if (snake._lengthSnake == 432)
	{
		text = Art::GetWinText();
	}
	else if (snake._lengthSnake > 432)
	{
		text = Art::GetCheatingText();
	}
	else
	{
		text = Art::GetGameOverText();
	}
	
	Color::SetTextColor(Color::RED);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0, 0 });
	Art::PrintText(text);
	Color::ResetColors();

	Color::SetTextColor(Color::LIGHT_MAGENTA);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0, 5 });
	std::cout << "Your score: ";
	Color::ResetColors();

	Color::SetTextColor(Color::MAGENTA);
	std::cout << snake._lengthSnake << std::endl;
	Color::ResetColors();

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0, 7 });

	char selection;
	while (true) {
		Color::SetTextColor(Color::LIGHT_GREEN);
		std::cout << "You lost!" << std::endl
			<< "Play again?" << std::endl;
		Color::ResetColors();

		Color::SetTextColor(Color::LIGHT_CYAN);
		std::cout << "Y(Yes)/N(No): ";
		Color::ResetColors();

		Color::SetTextColor(Color::DARK_GREEN);
		std::cin >> selection;
		Color::ResetColors();

		if (selection == 'Y' || selection == 'y') {
			restart = true;
			break;
		}
		else if (selection == 'N' || selection == 'n') {
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
	Color::SetTextColor(Color::DARK_GRAY);
	// Up border
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0, 0 });
	std::cout << std::string(Setting::getConsoleWidth(), '~');

	// Down border
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0, 19 });
	std::cout << std::string(Setting::getConsoleWidth(), '~');
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0, 22 });
	std::cout << std::string(Setting::getConsoleWidth(), '~');

	// Left and Right border
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
	Color::SetTextColor(Color::LIGHT_MAGENTA);
	std::cout << "Score: ";
	Color::ResetColors();

	Color::SetTextColor(Color::MAGENTA);
	std::cout << snake._lengthSnake << std::string(30, ' ');
	Color::ResetColors();

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 2, 21 });
	Color::SetTextColor(Color::CYAN);
	std::cout << "Position Item: ";
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
