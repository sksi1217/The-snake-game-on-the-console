#pragma once
#include "GameObject.h"
#include "Color.h"
#include <windows.h>

class Item : public GameObject {
public:
    char _itemSprite = '$';
    COORD _itemPosition;

    Item();

    void SetPosition(int x, int y);

    void Draw() override;
};