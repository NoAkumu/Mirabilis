#include "engine/components/Camera.hpp"

void Camera::Update() {
    CameraView.setCenter(owner->Position);
    CameraView.setSize(Vector2(static_cast<float>(Config.WIDTH)/Config.HEIGHT,1) * viewHeight);
    Main_Window.setView(CameraView);
}
