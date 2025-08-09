#include "Window.h"

WindowEngine::WindowEngine() : window(nullptr) {}

WindowEngine::~WindowEngine() {
	cleanup();
}

int WindowEngine::initGlfw() {
	if (!glfwInit())
	{
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	return 0;
};

int WindowEngine::createWindow(GLuint width, GLuint height, const GLchar name[]) {
	window = glfwCreateWindow(width, height, name, nullptr, nullptr);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

	return 0;
};

void WindowEngine::mainLoop() {
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);
	glfwPollEvents();
};

void WindowEngine::cleanup() {
	glfwDestroyWindow(window);
	glfwTerminate();
}