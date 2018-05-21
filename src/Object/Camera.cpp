#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(float x, float y) :
    _translate(glm::vec3(0.0f, 0.0f, 0.0f)),
    _viewMat(1.0f)
{
    SetPos(x, y);
}

Camera::~Camera() {
    
}

void Camera::SetPos(float x, float y) {
    _translate = glm::vec3(-x, -y, _translate.z);
    _viewMat = glm::translate(glm::mat4(1.0f), _translate);
}

void Camera::Move(float x, float y) {
    _translate = glm::vec3(_translate.x - x, _translate.y - y, _translate.z);
    _viewMat = glm::translate(glm::mat4(1.0f), _translate);
}
