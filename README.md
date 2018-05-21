# Kobe2D

A 2D Game Engine

## What exactly is Kobe2D?

Kobe2D is a 2D Game Engine written in C++, uses GLFW Library for Window Managment and GLEW "Library" for OpenGL "stuff".
This is my Third Attempt at making a Game Engine in my Spare Time while in High School for (presumably) my Future Projects.

## How to build it?

###### Linux (Ubuntu/Debian)

To build the code you will need to install a couple of things from terminal:
```
apt install gcc
apt install cmake
apt install libglfw3
apt install libglfw3-dev
apt install libglew2.0
apt install libglew2.0-dev
apt install libglm-dev
```
After installing everything we need to build our project.
Go in the directory you downloaded and type following commands:
```
mkdir build
cd build
cmake ..
make
cp -r ../res .
./Kobe2D
```
And you're done.
###### Windows
I will make a tutorial on how to setup Kobe2D on Windows in the near future. Feel free to contribute.
