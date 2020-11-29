#include "Application.h"

#include <Patator/Log.h>

namespace pat {

	Application::Application() {
		m_window = std::unique_ptr<Window>(Window::create());
		m_window->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));
	}

	Application::~Application() {

	}

	void Application::onEvent(Event& e) {
		PAT_CORE_INFO("{0}", e);
	}

	void Application::run() {
		while (m_running) {
			m_window->onUpdate();
		};
	}
}
