#pragma once
#include "engine/math/Vector2.hpp"
#include "engine/renderer/Window.hpp"

class Input {
    public:
        Vector2 InputDirection;
        Vector2 MousePosition = Vector2(0,0);
        void Update();
        Vector2 GetMouse();
        Vector2 GetMouse(Window& w);
        Input() : InputDirection(Vector2(0,0)) {};
};

inline Input MainInput;