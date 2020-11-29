#pragma once

#include "Core.h"
#include <Patator/Window.h>
#include <Patator/Events/Event.h>
#include <Patator/Events/ApplicationEvent.h>

namespace pat {

	class PAT_API Application
	{
	public:
		Application();
		virtual ~Application();
		void run();
		void onEvent(Event& e);
	private:
		bool onWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_window;
		bool m_running = true;
	};

	//To be defined in app
	Application* createApplication();

}

