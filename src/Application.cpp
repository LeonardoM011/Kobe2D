#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <vector>

#include "Renderer/Renderer.h"
#include "Window/Window.h"
#include "Buffer/VertexBufferLayout.h"
#include "Texture/Texture.h"
#include "Object/Object.h"
#include "Object/Tile.h"
#include "Window/Input.h"

int main(int argc, char **argv) {
	// Creating Window
    Window window("Kobe2D", 640, 480);

	// Printing our latest OpenGL Version
    std::cout << glGetString(GL_VERSION) << std::endl;

	// Creating our Renderer Object
	Renderer renderer;
	// Process our GL Blending
	renderer.Init();

	Camera camera(0.0f, 0.0f);

	// Creating our Shader
	Shader shader("res/shaders/Basic.shader");

	Tile object(-0.5f, -0.5f, shader, renderer, camera, "res/textures/Leo.png");
	Tile object2(0.0f, 0.0f, shader, renderer, camera, "res/textures/Leo.png");


	GLCall(glClearColor(1.0f, 1.0f, 1.0f, 1.0f));
	while (!window.ShouldClose()) {
		// Flush Depth and Color Buffer
		renderer.Clear();
		window.Update();

		double Delta = window.GetDelta();

		object.Draw();
		object2.Draw();
		object2.Move(0.0f, 0.1f * Delta);
		if(Input::keydown[GLFW_KEY_E]) {
			object.Move(0.1f * Delta, 0.0f);
		}
		if(Input::keydown[GLFW_KEY_R]) {
			object.RotateD(50.0f * Delta, 0.0f, 0.0f, 1.0f);
		}
		// Calling Window Swap
		window.Swap();
	}
	
	// Terminating Window
	window.Terminate();
    return 0;
}
