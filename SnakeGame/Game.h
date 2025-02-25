#pragma once
#include "Snake.h"
#include "Item.h"
#include "Setting.h"
#include "Color.h"
#include <conio.h>

class Game {
public:
    Snake snake;
    Item item;

    bool IsGame = true;

    void Start();
    void Update();
    void HandleInput();
    void CheckCollision();

private:
   void GenerateItem();
    void ResetGame();

    void MapBorder();
    void Info();
};