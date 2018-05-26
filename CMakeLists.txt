cmake_minimum_required(VERSION 3.0.0)
project(Kobe2D VERSION 0.0.1.0 LANGUAGES CXX)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(ADDITIONAL_SRC Dependencies/Linux/stb/include/stb_image.cpp)

set(MAIN_CPP src/Application.cpp)
set(WINDOW_CPP src/Window/Window.cpp)
set(RENDERER_CPP src/Renderer/Renderer.cpp)
set(TEXTURE_CPP src/Texture/Texture.cpp)
set(BUFFER_CPP src/Buffer/IndexBuffer.cpp src/Buffer/VertexArray.cpp src/Buffer/VertexBuffer.cpp)
set(SHADER_CPP src/Shader/Shader.cpp)
set(OBJECT_CPP src/Object/Object.cpp src/Object/Tile.cpp src/Object/Camera.cpp src/Object/Player.cpp)

add_executable(Kobe2D 
    ${ADDITIONAL_SRC} 
    ${MAIN_CPP}
    ${WINDOW_CPP}
    ${RENDERER_CPP}
    ${TEXTURE_CPP}
    ${BUFFER_CPP}
    ${SHADER_CPP}
    ${OBJECT_CPP}
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

find_package(OpenGL REQUIRED)
if(NOT OPENGL_FOUND)
    message("ERROR: OpenGL not found")
endif(NOT OPENGL_FOUND)
set(GL_LIBRARY GL X11 GLEW)

target_link_libraries(Kobe2D glfw ${GL_LIBRARY} m)

set_target_properties(Kobe2D PROPERTIES OUTPUT_NAME "Kobe2D V${PROJECT_VERSION}")
