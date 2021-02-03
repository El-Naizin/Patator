#include "patpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>
#include <Patator/Log.h>

namespace pat {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) {
		this->windowHandle = windowHandle;
		PAT_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::init() {
		glfwMakeContextCurrent(this->windowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		PAT_CORE_ASSERT(status, "Failed to initialize GLAD!");

		PAT_CORE_INFO("OpenGL Info:");
		PAT_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		PAT_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		PAT_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::swapBuffers() {
		glfwSwapBuffers(this->windowHandle);
	}
}