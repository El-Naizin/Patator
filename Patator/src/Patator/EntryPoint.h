#pragma once
#include "Application.h"

extern pat::Application* pat::createApplication();

int main(int argc, char** argv) {
	pat::Application* app = pat::createApplication();
	app->run();
	delete(app);
}
