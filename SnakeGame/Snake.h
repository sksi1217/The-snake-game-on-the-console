#pragma once
#include "GameObject.h"
#include "Color.h"
#include <deque>
#include <windows.h>

class Snake : public GameObject {
public:
    COORD _headPosition;
    std::deque<COORD> _tail; // тело
    int _lengthSnake = 0;
    char _lastKeyPressed = 'w';
    char _BodySnakeSprite = '*';
    char _headSnakeSprite = 'O';

    Snake();

    void Update() override;

    void Draw() override;

    void Grow();

    bool CheckCollision(COORD position) const;

private:
    void Move();
    void CleanTail();
    void DrawHead();
    void DrawTail();
};