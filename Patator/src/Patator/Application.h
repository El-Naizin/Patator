#pragma once

#include "Core.h"

namespace pat {

	class PAT_API Application
	{
	public:
		Application();
		virtual ~Application();
		void run();
	};

	//To be defined in app
	Application* createApplication();

}

