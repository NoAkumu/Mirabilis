#pragma once
#include "engine/core/Object.hpp"
#include "engine/components/Collision.hpp"

// Physics Component Class
class Physics : public Component
{
    protected:
        Collision* collision = nullptr;
        Vector2 velocity;
        Vector2 acceleration;
        float gravity = 981.0f;
        float ApplyGravity();
        float mass = 1.0f;
    public:
        bool EnableGravity = true;
        Physics() = default;
        virtual void Awake();
        virtual void FixedUpdate();
        void AddVelocity(Vector2 v);
        Vector2 GetVelocity() const&;
};
