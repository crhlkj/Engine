#include "Engine.h"
using namespace std;


GLfloat vertices[] = {
	-0.5f, -0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	0.0f,  0.5f, 0.0f
};

GLfloat indices[] = {};

int main() {
	windowEngine.initGlfw();
	windowEngine.createWindow(1280, 800, "Engine");


	glViewport(0, 0, 1280, 800);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	while (!glfwWindowShouldClose(windowEngine.getWindow())) {
		windowEngine.mainLoop();

	};

	windowEngine.cleanup();
	return 0;
}
