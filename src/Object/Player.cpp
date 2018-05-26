#include "Player.h"
#include <GLFW/glfw3.h>
#include "../Window/Input.h"

Player::Player(float x, float y, float width, float height, const std::string &texPath, Shader &shader, Renderer &renderer, Camera &camera) :
    _object(nullptr),
    MOVE_SPEED(0.1)
{
    float bottomX = 0.0f - ( width / 2.0f );
    float bottomY = 0.0f - ( height / 2.0f );
    float topX = 0.0f + ( width / 2.0f );
    float topY = 0.0f + ( height / 2.0f );
    std::vector<float> buffer = {
        bottomX, bottomY,  0.0f, 0.0f,
		bottomX, topY,     0.0f, 1.0f,
	    topX,    topY,     1.0f, 1.0f,
		topX,    bottomY,  1.0f, 0.0f
    };
    std::vector<unsigned int> indices = {
		0, 1, 2,
		2, 3, 0
	};
    _object = new Object(buffer, indices, texPath, shader, renderer, camera);
    
    _binds[Bind::MOVEUP]    = GLFW_KEY_W;
    _binds[Bind::MOVEDOWN]  = GLFW_KEY_S;
    _binds[Bind::MOVELEFT]  = GLFW_KEY_A;
    _binds[Bind::MOVERIGHT] = GLFW_KEY_D;

    SetPos(x, y);
}

Player::~Player() {
    delete _object;
}

void Player::BindKey(const Bind &bind, int action) {
    _binds[bind] = action;
}

void Player::Move(float x, float y) {
    _object->Move(x, y);
}

void Player::SetPos(float x, float y) {
    _object->SetPos(x, y);
}

void Player::RotateR(float radians, float pitch, float yaw, float roll) {
    _object->RotateR(radians, pitch, yaw, roll);
}

void Player::RotateD(float degrees, float pitch, float yaw, float roll) {
    _object->RotateD(degrees, pitch, yaw, roll);
}

void Player::SetRotR(float radians, float pitch, float yaw, float roll) {
    _object->SetRotR(radians, pitch, yaw, roll);
}

void Player::SetRotD(float degrees, float pitch, float yaw, float roll) {
    _object->SetRotD(degrees, pitch, yaw, roll);
}

void Player::Draw(double Delta) {
    CheckInput(Delta);
    _object->Draw();
}

void Player::CheckInput(double Delta) {
    if(Input::keydown[_binds[Bind::MOVEUP]]) {
        Move( 0.0f, MOVE_SPEED * Delta );
    }
    if(Input::keydown[_binds[Bind::MOVEDOWN]]) {
        Move( 0.0f, - ( MOVE_SPEED * Delta ) );
    }
    if(Input::keydown[_binds[Bind::MOVELEFT]]) {
        Move( - (MOVE_SPEED * Delta ), 0.0f );
    }
    if(Input::keydown[_binds[Bind::MOVERIGHT]]) {
        Move( MOVE_SPEED * Delta, 0.0f );
    }
}
