#pragma once
#include <SFML/Graphics.hpp>
#include "engine/math/Vector2.hpp"
#include "engine/core/Window.hpp"
#include "engine/core/Utils.hpp"
#include <vector>
#include <memory>
#include <utility>

class Object;

// Base Components Class (You shouldn't be using this)
class Component
{
    friend class Object;
    private:
        void SetOwner(Object* obj) {
            owner = obj;
        };
    protected:
        bool enabled = true;
        Object* owner;
    public:
        // Declaration
        Component() {};
        // Destructor
        ~Component() = default;
        // Virtual Functions
        virtual void Awake() {};
        virtual void Start() {};
        virtual void FixedUpdate() {};
        virtual void Update() {};
        virtual void LateUpdate() {};
        // Functions
        bool IsEnabled();
        void SetEnabled(bool value);
        Object* Owner() {
            return owner;
        };
};

/*Object Class*/
class Object {
    protected:
        sf::RectangleShape shape;
        std::vector<std::unique_ptr<Component>> components;
    public:
        // Declaration
        Object(Vector2 position, Vector2 size, Vector2 AnchorPoint) : Position(position), Size(size), AnchorPoint(AnchorPoint) {
            shape.setPosition(position);
            shape.setSize(size);
        }
        Object(Vector2 position, Vector2 size) : Position(position), Size(size), AnchorPoint(Vector2(0,0)) {
            shape.setPosition(position);
            shape.setSize(size);
        }
        // Destructor
        virtual ~Object() = default;
        // Object info

        char* Name = "Default";
        Vector2 Position;
        Vector2 AnchorPoint;
        Vector2 Size;
        sf::Color Color = sf::Color::Black;
        // Functions
        virtual void Awake();
        virtual void Start();
        virtual void FixedUpdate();
        virtual void Update();
        virtual void LateUpdate();
        virtual void Render();
        // Component-related functions
        template <typename T, typename... Args>
        T& AddComponent(Args&&... args) {
            static_assert(std::is_base_of_v<Component, T>,"Class is not a Valid Component");

            auto obj = std::make_unique<T>(std::forward<Args>(args)...);

            T& reference = *obj;
            
            reference.SetOwner(this);
            
            components.push_back(std::move(obj));

            reference.Start();

            return reference;
        };
        template <typename T>
        T* GetComponent() const {
            for(auto& comp : components) {
                if (T* result = dynamic_cast<T*>(comp.get()))
                {
                    return result;
                }
            }
            return nullptr;
        };
};