#include "Window.h"
#include "Log.h"

namespace pat {
	static bool s_GLFWInitialized = false;

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
		m_data.title = props.title;
		m_data.width = props.width;
		m_data.height = props.height;
		PAT_CORE_INFO("Creating window {0} ({1}, {2})", props.title, props.width, props.height);

		if (!s_GLFWInitialized) {
			int success = glfwInit();
			PAT_CORE_ASSERT(success, "Erreur lors de l'initialisation de GLFW!");
		}
		this->window = glfwCreateWindow((int)props.width, (int)props.height, m_data.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(this->window);
		glfwSetWindowUserPointer(this->window, &m_data);
		setVSync(true);
	}

	void Window::onUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	void Window::setVSync(bool enabled) {
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
		this->m_data.vSync = enabled;
	}

	bool Window::isSync() {
		return this->m_data.vSync;
	}

}





