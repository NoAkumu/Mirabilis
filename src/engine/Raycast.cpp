#include "engine/physics/Raycast.hpp"

bool IntersectAxis(float origin, float dir, float min, float max, float& tEnter, float& tExit) {
    if (std::abs(dir) <= 1e-6f) {
        if (origin >= min && origin <= max) {
            return true;
        }
    }else{
        float t1 = (min - origin) / dir;
        float t2 = (max - origin) / dir;

        if (t1 > t2)
            std::swap(t1, t2);
        
        tEnter = std::max(tEnter, t1);
        tExit = std::min(tExit, t2);

        return tEnter <= tExit;
    }
    return false;
}

bool CheckLineCast(Ray ray, float maxDist = 1000.0f) {
    ray.direction = ray.direction.normalized();

    for (auto& obj : gameObjects.GetObjects())
    {
        Collision* a = obj.get()->GetComponent<Collision>();
        if (!a)
            continue;

        float tEnter = 0.0f;
        float tExit = maxDist;

        if (!IntersectAxis(ray.origin.x, ray.direction.x, a->min.x, a->max.x, tEnter, tExit))
            continue;
        if (!IntersectAxis(ray.origin.y, ray.direction.y, a->min.y, a->max.y, tEnter, tExit))
            continue;
        
        return true;
    }
    return false;
}
