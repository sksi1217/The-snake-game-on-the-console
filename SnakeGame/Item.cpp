#include "Item.h"
#include <iostream>

Item::Item() {
	_itemPosition = { 0, 0 };
};

void Item::SetPosition(int x, int y) {
	_itemPosition.X = x;
	_itemPosition.Y = y;
}

void Item::Draw() {
	Color::SetTextColor(Color::DARK_GREEN);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), _itemPosition);
	std::cout << _itemSprite;
	Color::ResetColors();
}