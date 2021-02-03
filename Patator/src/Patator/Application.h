#pragma once

#include "Core.h"
#include <Patator/Window.h>
#include <Patator/Events/Event.h>
#include <Patator/Events/ApplicationEvent.h>
#include <Patator/LayerStack.h>
#include <Patator/ImGui/ImGuiLayer.h>

namespace pat {

	class Application
	{
	public:
		Application();
		virtual ~Application();
		void run();
		void onEvent(Event& e);

		void pushLayer(Layer* layer);
		void pushOverlay(Layer* overlay);

		static inline Application& get() { return *s_instance; }
		inline Window& getWindow() { return *window; }
	private:
		bool onWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> window;
		ImGuiLayer* imGuiLayer;
		bool running = true;
		LayerStack layerStack;

		static Application* s_instance;

		unsigned int vertexArray, vertexBuffer, indexBuffer;
	};

	//To be defined in app
	Application* createApplication();

}

