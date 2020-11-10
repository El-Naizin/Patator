#include "Application.h"

//Temporary includes, to remove
#include "Patator/Events/ApplicationEvent.h"
#include "Patator/Log.h"

namespace pat {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::run() {
		WindowResizeEvent e(1280, 720);
		PAT_TRACE(e);
		while (true);
	}
}
