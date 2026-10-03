#include "engine/Engine.hpp" 
#include "game/movement.hpp"

Physics* phys;
Collision* coll;
bool jumped = false;

void Movement::Start() {
    phys = Movement::owner->GetComponent<Physics>();
    coll = Movement::owner->GetComponent<Collision>();
}
void Movement::Update() {
    owner->Position += Vector2(MainInput.InputDirection.x * 250 * Time::deltaTime, 0);

    if (phys == nullptr || coll == nullptr) { return; }
    bool jump = MainInput.InputDirection.y < 0;
    if (jump && !jumped && std::abs(phys->GetVelocity().y) <= 0.0f)
    {
        if (CheckLineCast(Ray(Vector2(owner->Position.x, owner->Position.y + owner->Size.y + 1.0f),Vector2(0.0f, 1.0f)), 1.0f) || CheckLineCast(Ray(Vector2(owner->Position.x + owner->Size.x, owner->Position.y + owner->Size.y + 1.0f),Vector2(0.0f, 1.0f)), 1.0f))
        {
            phys->AddVelocity(Vector2(0, -500.0f));
        }
        
    }
    jumped = jump;
}
