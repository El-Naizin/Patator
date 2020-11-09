#pragma once
#include "Application.h"
#include "Log.h"

extern pat::Application* pat::createApplication();

int main(int argc, char** argv) {
	pat::Log::init();
	PAT_CORE_WARN("Initialized log!");
	PAT_INFO("Hello world!");
	pat::Application* app = pat::createApplication();
	app->run();
	delete(app);
}
