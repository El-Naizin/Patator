#include <patpch.h>
#include "Application.h"

#include <Patator/Log.h>
#include <glad/glad.h>

namespace pat {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_instance = nullptr;

	Application::Application() {
		Application::s_instance = this;

		this->window = std::unique_ptr<Window>(Window::create());
		this->window->setEventCallback(BIND_EVENT_FN(onEvent));

		this->imGuiLayer = new ImGuiLayer();
		this->pushOverlay(imGuiLayer);

		glGenVertexArrays(1, &this->vertexArray);
		glBindVertexArray(vertexArray);
		
		glGenBuffers(1, &this->vertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);

		float vertices[3 * 3] = {
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			0.0f, 0.5f, 0.0f,
		};

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

		glGenBuffers(1, &this->indexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indexBuffer);

		unsigned int indices[3] = { 0, 1, 2 };
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
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
		running = false;
		return true;
	}

	void Application::run() {
		while (running) {
			//Clear screen
			glClearColor(0.1f, 0.1f, 0.1f, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			//Draw what's in the vertex buffer
			glBindVertexArray(this->vertexArray);
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

			//Update all layers
			for (Layer* layer : layerStack) {
				layer->onUpdate();
			}
			this->imGuiLayer->begin();
			//Render all imgui layers
			for (Layer* layer : layerStack) {
				layer->onImGuiRender();
			}
			this->imGuiLayer->end();
			//Update window
			window->onUpdate();
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
