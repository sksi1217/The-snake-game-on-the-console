#pragma once

class GameObject {
public:
    virtual void Update() { };
    virtual void Draw() { };
    virtual ~GameObject() { };
};