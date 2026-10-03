#include "engine/components/Physics.hpp"
#include "engine/core/Time.hpp"

bool pressed = false;
void Physics::Awake() {
    collision = owner->GetComponent<Collision>();

    assert(collision != nullptr);
    
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