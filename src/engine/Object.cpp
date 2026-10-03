#include "engine/core/Object.hpp"
#include "engine/core/ComponentParts.hpp"

void Object::Awake(){
    for(auto& comp : components) {
        comp->Awake();
    }
}
void Object::Start(){}
void Object::FixedUpdate() {
    // Physics stuff goes here i guess
    for(auto& comp : components) {
        comp->FixedUpdate();
    }
    
}

void Object::Update() {
    for(auto& comp : components) {
        comp->Update();
    }
}

void Object::LateUpdate() {
    for(auto& comp : components) {
        comp->LateUpdate();
    }
}

void Object::Render() {
    for (auto& comp : components)
    {
        if (auto* rend = dynamic_cast<Renderable*>(comp.get()))
        {
            rend->Render();
        }
    }
}