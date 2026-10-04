#include "engine/core/Object.hpp"

bool Component::IsEnabled() const {
    return Component::enabled;
}
void Component::SetEnabled(bool value) {
    Component::enabled = value;
}


