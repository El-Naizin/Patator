#include <Patator.h>

class App : public pat::Application {
public:

	App() {

	}

	~App() {

	}
};

pat::Application* pat::createApplication() {
	return new App();
}
