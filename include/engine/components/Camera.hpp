#pragma once
#include "engine/core/Object.hpp"

// Camera Component Class
class Camera : public Component
{
    private:
        sf::View CameraView;
    public:
        float aspectRatio = 16.0f/9.0f;
        float viewHeight = 600.0f;
        Camera() {};
        Camera(float viewHeight) : viewHeight(viewHeight) {};
        Camera(float viewHeight, float aspectRatio) : viewHeight(viewHeight), aspectRatio(aspectRatio)  {};
        virtual void Update();
};