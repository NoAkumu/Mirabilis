#pragma once
#include "engine/core/Object.hpp"

// ScriptBehavior Component Class
class ScriptBehavior : public Component
{
    public:
        ScriptBehavior() = default;
        virtual void Awake() {};
        virtual void Start() {};
        virtual void FixedUpdate() {};
        virtual void Update() {};
        virtual void LateUpdate() {};
        void SetCameraView();
};