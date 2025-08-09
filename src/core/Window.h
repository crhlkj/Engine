#pragma once
#include <iostream>
#include <GLFW/glfw3.h>
#include <glad/glad.h>

class WindowEngine {
private:
	GLFWwindow* window = nullptr;

public:
	WindowEngine();
	~WindowEngine();

	GLFWwindow* getWindow() const { return window; }

	int initGlfw();
	int createWindow(GLuint width, GLuint height, const GLchar* name);
	void mainLoop();
	void cleanup();
};
