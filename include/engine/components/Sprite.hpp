#pragma once
#include "engine/core/Object.hpp"
#include "engine/core/ComponentParts.hpp"

// Sprite Component Class
class Sprite : public Component, public Renderable
{
    protected:
        sf::Texture texture;
        sf::Sprite sprite;
        std::string texturePath = "Debug.png";
    public:
        Sprite(std::string texturePath) : texturePath(texturePath), texture(LoadTexture(texturePath)), sprite(texture) {};
        void Render() override;
};