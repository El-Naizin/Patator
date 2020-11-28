#pragma once
#include <sstream>
#include <string>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <Patator/Events/Event.h>

namespace pat {

	struct WindowProps {
		std::string title;
		unsigned int width;
		unsigned int height;

		WindowProps(const std::string& title = "Patator Engine",
			unsigned int width = 1280,
			unsigned int height = 720) : title(title), width(width), height(height) {
		}


	};
	
	class Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;
		Window(const WindowProps& props);
		virtual ~Window();

		void onUpdate();
		inline unsigned int getWidth() const { return m_data.width; }
		inline unsigned int getHeight() const { return m_data.height; }

		bool isSync();
		static Window* create(const WindowProps& props = WindowProps());
	private:
		virtual void init(const WindowProps& props);
		virtual void shutDown();

	private:
		GLFWwindow* window;
		struct WindowData
		{
			std::string title;
			unsigned int width, height;
			bool vSync;

			EventCallbackFn eventCallback;
		};
		WindowData m_data;
		void setVSync(bool enabled);
	};
}
