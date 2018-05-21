#pragma once
#include <glm/glm.hpp>
#include "Object.h"

class Tile {
public:
    Tile(float x, float y, Shader &shader, Renderer &renderer, Camera &camera, const std::string &texPath);
    ~Tile();
    void Move(float x, float y);
    void SetPos(float x, float y);
    void RotateR(float radians, float pitch, float yaw, float roll);
    void RotateD(float degrees, float pitch, float yaw, float roll);
    void SetRotR(float radians, float pitch, float yaw, float roll);
    void SetRotD(float degrees, float pitch, float yaw, float roll);
    void Draw();
private:
    Object *_object;
};
