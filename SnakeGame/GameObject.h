#pragma once

class GameObject {
public:
    virtual void Update() { }; // Абстрактный метод обновления
    virtual void Draw() { };   // Абстрактный метод отрисовки
    virtual ~GameObject() { };
};