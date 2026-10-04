#pragma once

#include "engine/math/Vector2.hpp"

namespace Math {
    bool IsBetween(float x, float min, float max);
    bool IsBetweenExclusive(float x, float min, float max);
};