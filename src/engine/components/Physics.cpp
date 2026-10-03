#include "engine/components/Physics.hpp"
#include "engine/core/Time.hpp"

void Physics::Awake() {
    collision = owner->GetComponent<Collision>();

    assert(collision != nullptr);
    
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

void Physics::AddVelocity(Vector2 v) {
    velocity += v;
};

Vector2 Physics::GetVelocity() const& {
    return velocity;
};