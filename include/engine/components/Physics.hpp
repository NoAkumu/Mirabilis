#pragma once
#include "engine/core/Object.hpp"
#include "engine/components/Collision.hpp"

// Physics Component Class
class Physics : public Component
{
    protected:
        Collision* collision = nullptr;
        size_t connectionId;
        Vector2 velocity;
        Vector2 acceleration;
        float gravity = 981.0f;
        float ApplyGravity();
        float mass = 1.0f;
    public:
        bool EnableGravity = true;
        Physics() = default;
        virtual void Start();
        virtual void FixedUpdate();
        virtual void OnDestroy();
        void AddVelocity(Vector2 v);
        Vector2 GetVelocity() const;
};
