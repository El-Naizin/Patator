#include "Application.h"


namespace pat {

	Application::Application() {
		m_window = std::unique_ptr<Window>(Window::create());
	}

	Application::~Application() {

	}

	void Application::run() {
		while (m_running) {
			m_window->onUpdate();
		};
	}
}
