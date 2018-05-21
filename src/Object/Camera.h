#pragma once
#include <glm/glm.hpp>

class Camera {
public:
    Camera(float x, float y);
    ~Camera();
    void SetPos(float x, float y);
    void Move(float x, float y);
    glm::mat4 GetViewMat() const { return _viewMat; }
private:
    glm::mat4 _viewMat;
    glm::vec3 _translate;
};