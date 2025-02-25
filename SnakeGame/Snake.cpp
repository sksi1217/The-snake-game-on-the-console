#include "Snake.h"
#include <iostream>

Snake::Snake()
{
	_headPosition = { 28, 28 };
}

void Snake::Update() {
	CleanTail();
	Move();
	
}

void Snake::Draw() {
	DrawHead();
	DrawTail();
}

void Snake::Grow() {
	_lengthSnake++;
}

bool Snake::CheckCollision(COORD position) const {
	for (const auto& segment : _tail) {
		if (segment.X == position.X && segment.Y == position.Y) {
			return true;
		}
	}
	return false;
}

void Snake::Move() {
	_tail.push_front(_headPosition);

	switch (_lastKeyPressed) {
	case 'w': _headPosition.Y--; break;
	case 's': _headPosition.Y++; break;
	case 'a': _headPosition.X-=2; break;
	case 'd': _headPosition.X+=2; break;
	}

	if (_headPosition.X < 1) _headPosition.X = 48;
	if (_headPosition.X > 48) _headPosition.X = 2;
	if (_headPosition.Y < 1) _headPosition.Y = 18;
	if (_headPosition.Y > 18) _headPosition.Y = 1;

	if (_tail.size() > _lengthSnake) _tail.pop_back();
}

void Snake::CleanTail() {
	for (const auto& segment : _tail) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), segment);
		std::cout << " ";
	}
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), _headPosition);
	std::cout << " ";
}

void Snake::DrawHead() {
	Color::SetTextColor(Color::ORANGE);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), _headPosition);
	std::cout << _headSnakeSprite;
	Color::ResetColors();
}

void Snake::DrawTail() {
	Color::SetTextColor(Color::LIGHT_ORANGE);
	for (const auto& segment : _tail) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), segment);
		std::cout << _BodySnakeSprite;
	}
	Color::ResetColors();
}
