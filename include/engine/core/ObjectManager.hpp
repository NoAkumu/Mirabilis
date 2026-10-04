#pragma once
#include "engine/core/Object.hpp"
#include "engine/core/Utils.hpp"
#include "engine/components/Components.hpp"
#include <memory>
#include <utility>
#include <vector>

class  ObjectManager {
    public:
        template <typename... Args> Object& create(Args&&... args) {
            auto obj = std::make_unique<Object>(std::forward<Args>(args)...);
            
            Object& reference = *obj;

            objects.push_back(std::move(obj));

            reference.Start();

            return reference;
        };
        void AwakeAll() {
            for(auto& obj : objects) {
                obj->Awake();
            }
        };
        void FixedUpdateAll() {
            for(auto& obj : objects) {
                obj->FixedUpdate();
            }
            //This collision check is probably ass, but i can't think of a better alternative at 5 AM
            for (std::size_t i = 0; i < objects.size(); i++)
            {
                Collision* a = objects[i].get()->GetComponent<Collision>();
                if (a == nullptr || !a->IsEnabled()){
                    continue;
                }
                for (std::size_t j = 0; j < objects.size(); j++)
                {
                    if (objects[i] == objects[j]) {
                        continue;
                    }
                    Collision* b = objects[j].get()->GetComponent<Collision>();
                    if (b == nullptr || !b->IsEnabled()){
                        continue;
                    }
                    if (!a->BroadCollisionCheck(*b))
                    {
                        continue;
                    }
                    if (!a->Overlaping(*b))
                    {
                        continue;
                    }
                    a->PullPosition(*b);
                }
            }
        };
        void UpdateAll() {
            for(auto& obj : objects) {
                obj->Update();
            }
        };
        void LateUpdateAll() {
            for(auto& obj : objects) {
                obj->LateUpdate();
            }
        };
        void RenderAll() {
            for(auto& obj : objects) {
                obj->Render();
            }
        };
        const std::vector<std::unique_ptr<Object>>& GetObjects() const {
            return objects;
        };
    private:
        std::vector<std::unique_ptr<Object>> objects;
};

inline ObjectManager gameObjects;