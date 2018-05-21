#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>

#include "../Buffer/VertexArray.h"
#include "../Buffer/IndexBuffer.h"
#include "../Shader/Shader.h"

//#define ASSERT(x) if(!(x)) __debugbreak();
#define ASSERT(x) if(!(x)) __builtin_trap();

#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();
bool GLLogCall(const char *function, const char *file, int line);

class Renderer {
public:
	void Draw(const VertexArray &va, const IndexBuffer &ib, const Shader &shader) const;
	void Init();
	void Clear() const;
	glm::mat4 GetProjMat() const { return _projMat; }
private:
	glm::mat4 _projMat;
};
