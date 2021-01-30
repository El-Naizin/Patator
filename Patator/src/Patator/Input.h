#pragma once

#include <Patator/Core.h>

namespace pat {

	class Input 
	{
	public:

		Input(GLFWwindow* window);
		~Input();
		bool isKeyPressed(int keyCode);
		bool isMouseButtonPressed(int mouseButtonCode);
		float getMouseX();
		float getMouseY();
		static Input* get();
	private:
		GLFWwindow* window;
		static Input* s_instance;
	};
}
