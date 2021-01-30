#include <patpch.h>

#include <GLFW/glfw3.h>
#include "Input.h"
#include <Patator/Application.h>
#include <Patator/Window.h>
#include <Patator/Log.h>

namespace pat {

	Input* Input::s_instance = nullptr;
	
	Input::Input(GLFWwindow* window) {
		PAT_TRACE("Input en train de s'activer");
		this->window = window;
		this->s_instance = this;
	}

	Input::~Input() {

	}

	float Input::getMouseX() {
		double x, y;
		glfwGetCursorPos(this->window, &x, &y);
		return (float)x;
	}

	float Input::getMouseY() {
		double x, y;
		glfwGetCursorPos(this->window, &x, &y);
		return (float)y;
	}

	bool Input::isKeyPressed(int keyCode) {
		int state = glfwGetKey(this->window, keyCode);
		return state == GLFW_PRESS;
	}

	bool Input::isMouseButtonPressed(int mouseCode) {
		int state = glfwGetMouseButton(this->window, mouseCode);
		return state == GLFW_PRESS;
	}

	Input* Input::get() {
		return Input::s_instance;
	}
}