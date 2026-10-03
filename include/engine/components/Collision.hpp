#pragma once
#include "engine/core/Object.hpp"
#include "engine/core/Event.hpp"

// Collision Component Class
struct CollisionData
{
    void* objectHit;
    void* thisObject;
    Vector2 overlap;
    Vector2 normal;
    CollisionData(void* oH, void* tO, Vector2 o, Vector2 dir) : objectHit(oH), thisObject(tO), overlap(o), normal(dir) {}
};

class Collision : public Component
{
    private:
        
    public:
        bool Anchored = false;
        Vector2 min, max;
        Collision() = default;
        void FixedUpdate() {
            min = owner->Position - (owner->Size * owner->AnchorPoint);
            max = min + owner->Size;
        }
        Event<const CollisionData&> OnCollide;
        Vector2 Center() {
            return (min + max)/2;
        }
        Vector2 CalculateOverlap(Collision& other) {
            return Vector2(
                std::min(max.x, other.max.x) - std::max(min.x, other.min.x),
                std::min(max.y, other.max.y) - std::max(min.y, other.min.y)
            );
        }
        Vector2 CalculateNormal(Collision& other) {
            Vector2 direction(
                other.Center().x - Center().x,
                other.Center().y - Center().y
            );
            Vector2 overlap = CalculateOverlap(other);
            
            if (overlap.x < overlap.y)
            {
                return Vector2(direction.x >= 0.0f ? 1.0f : -1.0f, 0.0f);
            }
            
            return Vector2(0.0f, direction.y >= 0.0f ? 1.0f : -1.0f);
        }
        bool Overlaping(Collision& other) {
            return (
                min.x < other.max.x &&
                max.x > other.min.x &&
                min.y < other.max.y &&
                max.y > other.min.y
            );
        }
        
        bool BroadCollisionCheck(Collision &other) {
            Vector2 diff(
                other.Center().x - Center().x,
                other.Center().y - Center().y
            );

            float distanceSquared = (diff.x*diff.x) + (diff.y*diff.y);

            float radiusSum = (owner->Size.length()) + (other.owner->Size.length());

            return distanceSquared <= radiusSum*radiusSum;
        }
        void PullPosition(Collision &other) {
            if (Anchored) {
                return;
            }
            Vector2 overlap = CalculateOverlap(other);
            Vector2 direction(
                other.Center().x - Center().x,
                other.Center().y - Center().y
            );
            if (overlap.x < overlap.y)
            { 
                owner->Position.x += direction.x >= 0.0f ? -overlap.x : overlap.x;
            } else { 
                owner->Position.y += direction.y >= 0.0f ? -overlap.y : overlap.y;
            }
            OnCollide.Fire(CollisionData(this, &other, overlap, CalculateNormal(other)));
        }
};