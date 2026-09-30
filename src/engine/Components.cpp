#include "engine/core/Components.hpp"
#include "engine/core/Utils.hpp"
#include "engine/core/Window.hpp"
#include "engine/core/ComponentParts.hpp"
#include "engine/core/Settings.hpp"
#include "engine/input/Input.hpp"
#include "engine/core/Time.hpp"
#include <SFML/Graphics.hpp>

#pragma region Universal

bool Component::IsEnabled() {
    return Component::enabled;
}
void Component::SetEnabled(bool value) {
    Component::enabled = value;
}

#pragma endregion

#pragma region Sprite

void Sprite::Render() {
    sprite.setPosition(owner->Position - (owner->Size * owner->AnchorPoint));
    sprite.setScale({
        owner->Size.x / static_cast<float>(texture.getSize().x),
        owner->Size.y / static_cast<float>(texture.getSize().y)
    });
    Main_Window.draw(sprite);
}

#pragma endregion

#pragma region Physics

bool pressed = false;
void Physics::Awake() {
    collision = owner->GetComponent<Collision>();
    mass = ((owner->Size.x/100) * (owner->Size.y/100));
    collision->OnCollide.Subscribe([&](const CollisionData& a) {
        if(a.normal.x != 0 && velocity.x * a.normal.x > 0.0f) {
            velocity.x = 0;
        }
        if(a.normal.y != 0 && velocity.y * a.normal.y > 0.0f) {
            velocity.y = 0;
        }
    });
}

void Physics::FixedUpdate() {
    Vector2 actualaccel = acceleration;
    
    if (EnableGravity) {
        actualaccel.y += gravity;
    }
    velocity += actualaccel * Time::fixedDt;
    owner->Position += velocity * Time::fixedDt;
}
float Physics::ApplyGravity() {
    return gravity;
}
void Physics::AddForce(Vector2 f) {
    velocity += f;
};

Vector2 Physics::GetVelocity() {
    return velocity;
};

#pragma endregion

#pragma region Camera

void Camera::Update() {
    CameraView.setCenter(owner->Position);
    CameraView.setSize(Vector2(static_cast<float>(Config.WIDTH)/Config.HEIGHT,1) * viewHeight);
    Main_Window.setView(CameraView);
}

#pragma endregion

