#pragma once

#include <unordered_map>

using SceneId = std::size_t;

class Scene
{
private:
    /* data */
public:
    Scene(/* args */) {};
    ~Scene() {};
};

inline std::unordered_map<SceneId, Scene> scenes;
