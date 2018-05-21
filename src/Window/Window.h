#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

class Window {
public:
    Window(const std::string &title, int width, int height);
    ~Window();
    void Swap() const;
    void Update();
    bool ShouldClose() const;
    void Terminate() const;
    double GetDelta() const { return _deltaTime; }
    int GetFPS() const { return _FPS; }
private:
    GLFWwindow *_window;
    int _width;
    int _height;
    double _lastTime;
    double _currentTime;
    double _fLastTime;
    double _deltaTime;
    int _nFrames;
    int _FPS;
};