#pragma once
#include <deque>

class Snake
{
public:
	COORD _headPosition = { 0, 0 };
	std::deque<COORD> _body;

	int _lengthSnake = 0;

	char _lastKeyPressed = 'w';
	char _BodySnakeSprite = '*';
	char _headSnakeSprite = 'O';
};
