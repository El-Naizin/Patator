#include <patpch.h>
#include <Patator.h>

class ExampleLayer : public pat::Layer {
public:
	ExampleLayer()
		: Layer("Example") {

	}

	void onUpdate() override {
		auto input = pat::Input::get();
		input->isKeyPressed(PAT_KEY_TAB);
	}

	void onEvent(pat::Event& event) override {
	}
};

class App : public pat::Application {
public:

	App() {
		pushLayer(new ExampleLayer());
	}

	~App() {

	}
};

pat::Application* pat::createApplication() {
	return new App();
}
