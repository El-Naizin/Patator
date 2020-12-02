#include <patpch.h>
#include <Patator.h>

class ExampleLayer : public pat::Layer {
public:
	ExampleLayer()
		: Layer("Example") {

	}

	void onUpdate() override {
	}

	void onEvent(pat::Event& event) override {
	}
};

class App : public pat::Application {
public:

	App() {
		pushLayer(new ExampleLayer());
		pushOverlay(new pat::ImGuiLayer());
	}

	~App() {

	}
};

pat::Application* pat::createApplication() {
	return new App();
}
