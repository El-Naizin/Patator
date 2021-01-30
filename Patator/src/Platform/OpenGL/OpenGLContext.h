#pragma once

#include <Patator/Renderer/GraphicsContext.h>

struct GLFWwindow;

namespace pat {

	class OpenGLContext : public GraphicsContext {
	public:
		OpenGLContext(GLFWwindow* windowHandle);
		
		virtual void init() override;
		virtual void swapBuffers() override;

	private:
		GLFWwindow* windowHandle;
	};
}
