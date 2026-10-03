#include "engine/components/Sprite.hpp"

void Sprite::Render() {
    sprite.setPosition(owner->Position - (owner->Size * owner->AnchorPoint));
    sprite.setScale({
        owner->Size.x / static_cast<float>(texture.getSize().x),
        owner->Size.y / static_cast<float>(texture.getSize().y)
    });
    Main_Window.draw(sprite);
}