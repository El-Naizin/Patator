#include <patpch.h>
#include "Application.h"

#include <Patator/Log.h>
#include <glad/glad.h>

namespace pat {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_instance = nullptr;

	Application::Application() {
		Application::s_instance = this;

		this->m_window = std::unique_ptr<Window>(Window::create());
		this->m_window->setEventCallback(BIND_EVENT_FN(onEvent));

		this->m_ImGuiLayer = new ImGuiLayer();
		this->pushOverlay(m_ImGuiLayer);
	}

	Application::~Application() {

	}

	void Application::onEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClose));

		for (auto it = layerStack.end(); it != layerStack.begin();) {
			(*--it)->onEvent(e);
			if (e.handled)
				break;
		}
	}

	bool Application::onWindowClose(WindowCloseEvent& e) {
		m_running = false;
		return true;
	}

	void Application::run() {
		while (m_running) {
			//Clear screen
			glClearColor(1, 1, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			//Update all layers
			for (Layer* layer : layerStack) {
				layer->onUpdate();
			}
			this->m_ImGuiLayer->begin();
			//Render all imgui layers
			for (Layer* layer : layerStack) {
				layer->onImGuiRender();
			}
			this->m_ImGuiLayer->end();
			//Update window
			m_window->onUpdate();
		};
	}

	void Application::pushLayer(Layer* layer) {
		layerStack.pushLayer(layer);
		layer->onAttach();
	}

	void Application::pushOverlay(Layer* overlay) {
		layerStack.pushOverLay(overlay);
		overlay->onAttach();
	}
}
