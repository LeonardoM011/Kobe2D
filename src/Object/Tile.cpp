#include "Tile.h"
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

Tile::Tile(float x, float y, const std::string &texPath, Shader &shader, Renderer &renderer, Camera &camera) :
    _object(nullptr)
{
    std::vector<float> buffer = {
        -0.1f, -0.1f,  0.0f, 0.0f,
		-0.1f,  0.1f,  0.0f, 1.0f,
	     0.1f,  0.1f,  1.0f, 1.0f,
		 0.1f, -0.1f,  1.0f, 0.0f
    };
    std::vector<unsigned int> indices = {
		0, 1, 2,
		2, 3, 0
	};

    _object = new Object(buffer, indices, texPath, shader, renderer, camera);
    SetPos(x, y);
}

Tile::~Tile() {
    delete _object;
}

void Tile::Move(float x, float y) {
    _object->Move(x, y);
}

void Tile::SetPos(float x, float y) {
    _object->SetPos(x, y);
}

void Tile::RotateR(float radians, float pitch, float yaw, float roll) {
    _object->RotateR(radians, pitch, yaw, roll);
}

void Tile::RotateD(float degrees, float pitch, float yaw, float roll) {
    _object->RotateD(degrees, pitch, yaw, roll);
}

void Tile::SetRotR(float radians, float pitch, float yaw, float roll) {
    _object->SetRotR(radians, pitch, yaw, roll);
}

void Tile::SetRotD(float degrees, float pitch, float yaw, float roll) {
    _object->SetRotD(degrees, pitch, yaw, roll);
}

void Tile::Draw() {
    _object->Draw();
}
