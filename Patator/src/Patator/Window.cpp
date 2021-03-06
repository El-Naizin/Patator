#include <patpch.h>
#include "Window.h"
#include "Log.h"
// Include events
#include <Patator/Events/ApplicationEvent.h>
#include <Patator/Events/KeyEvent.h>
#include <Patator/Events/MouseEvent.h>
#include <Platform/OpenGL/OpenGLContext.h>

namespace pat {
	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* description) {
		PAT_CORE_ERROR("GLFW_ERROR: {0}: {1}", error, description);
	}

	Window* Window::create(const WindowProps& props) {
		return new Window(props);
	}

	Window::Window(const WindowProps& props) {
		init(props);
	}

	Window::~Window() {
		shutDown();
	}

	void Window::shutDown() {
		glfwDestroyWindow(this->window);
	}

	void Window::init(const WindowProps& props) {
		data.title = props.title;
		data.width = props.width;
		data.height = props.height;
		PAT_CORE_INFO("Creating window {0} ({1}, {2})", props.title, props.width, props.height);

		if (!s_GLFWInitialized) {
			int success = glfwInit();
			PAT_CORE_ASSERT(success, "Erreur lors de l'initialisation de GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}
		this->window = glfwCreateWindow((int)props.width, (int)props.height, data.title.c_str(), nullptr, nullptr);

		// Create the openGL specific context
		// Will Have to change here when migrating to Vulkan
		this->context = new OpenGLContext(this->window);
		this->context->init();

		// Set the userPointer to send back a pointer to data
		glfwSetWindowUserPointer(this->window, &data);
		setVSync(true);
		//Initialize input:
		this->input = new Input(this->window);

		// Set GLFW callbacks:
		glfwSetWindowSizeCallback(this->window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.width = width;
				data.height = height;

				WindowResizeEvent event(width, height);
				data.eventCallback(event);
			});

		glfwSetWindowCloseCallback(this->window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent event;
				data.eventCallback(event);
			});

		glfwSetKeyCallback(this->window, [](GLFWwindow* window, int key, int scanCode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				// TODO convert keycodes.

				switch (action) {
					case GLFW_PRESS: {
						KeyPressedEvent event(key);
						data.eventCallback(event);
						break;
					}
					case GLFW_RELEASE: {
						KeyReleasedEvent event(key);
						data.eventCallback(event);
						break;
					}
					case GLFW_REPEAT: {
						//TODO: find out what i want to do with this, probably nothing
						break;
					}
				}

			});

		glfwSetMouseButtonCallback(this->window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action) {
					case GLFW_PRESS: {
						MouseButtonPressedEvent event(button);
						data.eventCallback(event);
						break;
					}
					case GLFW_RELEASE: {
						MouseButtonReleasedEvent event(button);
						data.eventCallback(event);
						break;
					}
				}

			});

		glfwSetScrollCallback(this->window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseScrolledEvent event((float)xOffset, (float)yOffset);
				data.eventCallback(event);
			});

		glfwSetCursorPosCallback(this->window, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseMovedEvent event((float)xPos, (float)yPos);
				data.eventCallback(event);
			});

		glfwSetCharCallback(this->window, [](GLFWwindow* window, unsigned int keyCode)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				KeyTypedEvent event(keyCode);
				data.eventCallback(event);
			});
	}

	void Window::onUpdate() {
		glfwPollEvents();
		this->context->swapBuffers();
	}

	void Window::setVSync(bool enabled) {
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
		this->data.vSync = enabled;
	}

	bool Window::isSync() {
		return this->data.vSync;
	}

}





