#pragma once 
#include "engine/components/ScriptBehavior.hpp"

class Movement : public ScriptBehavior {
    public:
        Movement() = default;
        virtual ~Movement() = default;
        virtual void Awake() {};
        virtual void Start();
        virtual void FixedUpdate() {};
        virtual void Update();
        virtual void LateUpdate() {};
};