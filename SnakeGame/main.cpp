#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <random>
#include "PositionInfoGame.h";
#include "Snake.h";
#include "Apple.h";

int getConsoleWidth();
int getConsoleHeight();
int generatePosistion(int min, int max);

bool Collision(COORD& coordSnake, COORD& coordApple);
bool CollisionBody(Snake& snake);

void InputManager(COORD& coordApple, char& lastKeyPressed);
void MoveSnake(Snake& snake);
void CleanSnake(Snake& snake);
void DrawSnake(Snake& snake);
void GenerationApple(Apple& apple);
void HideCursor();
void sizeWindow();

void StartGame(Snake& snake, Apple& apple)
{
	system("mode con: cols=50 lines=22");

	HideCursor();
	sizeWindow();

	int consoleWidth = getConsoleWidth();
	int consoleHeight = getConsoleHeight();

	int centerX = consoleWidth / 2;
	int centerY = consoleHeight / 2;

	// snake Position
	snake._headPosition.X = centerX - 1;
	snake._headPosition.Y = centerY - 1;

	// apple Position
	apple._applePosition.X = generatePosistion(0, 24) * 2;
	apple._applePosition.Y = generatePosistion(0, 18);
}

void Updata(Snake& snake, Apple& apple, PositionInfoGame& positionInfoGame)
{
	while (true)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), positionInfoGame.PositionInfo);
		std::cout << " Score: " << snake._lengthSnake << "                                     ";

		CleanSnake(snake);

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), apple._applePosition);
		std::cout << apple._appleSprite;

		InputManager(apple._applePosition, snake._lastKeyPressed);

		MoveSnake(snake);

		DrawSnake(snake);

		if (Collision(snake._headPosition, apple._applePosition))
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), apple._applePosition);
			std::cout << " ";
			GenerationApple(apple);
			snake._lengthSnake++;
		}

		if (CollisionBody(snake))
		{
			CleanSnake(snake);
			snake._body.clear();
			snake._lengthSnake = 0;
		}

		Sleep(100);
	}
}

int main() {
	Snake snake;
	Apple apple;
	PositionInfoGame positionInfoGame;

	StartGame(snake, apple);

	Updata(snake, apple, positionInfoGame);

	return 0;
}

int getConsoleWidth() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

int getConsoleHeight() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

int generatePosistion(int min, int max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(min, max);

	int randomNumber = distrib(gen);

	return randomNumber;
}

void InputManager(COORD& coordApple, char& lastKeyPressed)
{
	if (_kbhit()) {
		char input = _getch();

		if (input == 100 && lastKeyPressed != 'a') lastKeyPressed = 'd';
		else if (input == 97 && lastKeyPressed != 'd') lastKeyPressed = 'a';
		else if (input == 119 && lastKeyPressed != 's') lastKeyPressed = 'w';
		else if (input == 115 && lastKeyPressed != 'w') lastKeyPressed = 's';
	}
}

void MoveSnake(Snake& snake)
{
	snake._body.push_front(snake._headPosition);

	if (snake._lastKeyPressed == 'd') snake._headPosition.X += 2;
	else if (snake._lastKeyPressed == 'a') snake._headPosition.X -= 2;
	else if (snake._lastKeyPressed == 'w') snake._headPosition.Y -= 1;
	else if (snake._lastKeyPressed == 's') snake._headPosition.Y += 1;

	// Wall Collision 
	if (snake._headPosition.X > 48) snake._headPosition.X = 0;
	else if (snake._headPosition.X < 0) snake._headPosition.X = 48;
	if (snake._headPosition.Y < 0) snake._headPosition.Y = 18;
	else if (snake._headPosition.Y > 18) snake._headPosition.Y = 0;

	// We limit the length of the body
	if (snake._body.size() > snake._lengthSnake) snake._body.pop_back(); // we delete the last element if the body length is longer than desired
}

bool Collision(COORD& coordSnake, COORD& coordApple)
{
	if (coordSnake.X == coordApple.X && coordSnake.Y == coordApple.Y) return true;
	return false;
}

bool CollisionBody(Snake& snake)
{
	for (int i = 0; i < snake._body.size(); i++) {
		if (snake._body[i].X == snake._headPosition.X && snake._body[i].Y == snake._headPosition.Y)
		{
			return true;
		}
	}
	return false;
}

void CleanSnake(Snake& snake)
{
	// Clearing previous position body
	for (int i = 0; i < snake._body.size(); i++) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake._body[i]);
		std::cout << " ";
	}
	// Clearing previous position head
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake._headPosition);
	std::cout << " ";
}

void DrawSnake(Snake& snake)
{
	// Drawing head snake
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake._headPosition);
	std::cout << snake._headSnakeSprite;

	// Drawing body snake
	for (int i = 0; i < snake._body.size(); i++) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake._body[i]);
		std::cout << snake._BodySnakeSprite;
	}
}

void GenerationApple(Apple& apple)
{
	// Apple Position
	apple._applePosition.X = generatePosistion(0, 24) * 2;
	apple._applePosition.Y = generatePosistion(0, 18);
}

void HideCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(consoleHandle, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void sizeWindow()
{
	SetConsoleOutputCP(CP_UTF8);

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	GetCurrentConsoleFontEx(hOut, FALSE, &cfi);

	cfi.dwFontSize.Y = 35;

	SetCurrentConsoleFontEx(hOut, FALSE, &cfi);
}
