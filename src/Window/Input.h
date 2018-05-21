#pragma once
#include <GLFW/glfw3.h>
#include <unordered_map>

namespace Input {
    inline std::unordered_map<int, bool> keydown;
    inline void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        if (action == GLFW_PRESS) {
		    keydown[key] = true;
        }
        if (action == GLFW_RELEASE) {
            keydown[key] = false;
        }
    }
}