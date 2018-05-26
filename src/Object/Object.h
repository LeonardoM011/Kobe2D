#pragma once
#include <vector>
#include <glm/glm.hpp>
#include "../Buffer/VertexArray.h"
#include "../Buffer/VertexBuffer.h"
#include "../Buffer/VertexBufferLayout.h"
#include "../Buffer/IndexBuffer.h"
#include "../Shader/Shader.h"
#include "../Texture/Texture.h"
#include "Camera.h"

class Object {
public:
    Object(const std::vector<float> &buffer, const std::vector<unsigned int> &indices, const std::string &texPath, Shader &shader, Renderer &renderer, Camera &camera);
    ~Object();
    void Move(float x, float y);
    void SetPos(float x, float y);
    void RotateR(float radians, float pitch, float yaw, float roll);
    void RotateD(float degrees, float pitch, float yaw, float roll);
    void SetRotR(float radians, float pitch, float yaw, float roll);
    void SetRotD(float degrees, float pitch, float yaw, float roll);
    void Draw();
private:
    std::vector<float> _buffer;
    std::vector<unsigned int> _indices;
    VertexArray _va;
    VertexBuffer _vb;
    VertexBufferLayout _layout;
    IndexBuffer *_ib;
    Texture _texture;
    Renderer &_renderer;
    Camera &_camera;
    Shader &_shader;
    glm::mat4 _modelMat;
    glm::vec3 _translate;
    glm::vec3 _rotation;
};
