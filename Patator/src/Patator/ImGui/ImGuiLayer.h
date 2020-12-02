#pragma once

#include "Patator/Layer.h"
#include <Patator/Events/MouseEvent.h>
#include <Patator/Events/KeyEvent.h>
#include <Patator/Events/ApplicationEvent.h>

namespace pat {

	class PAT_API ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void onAttach();
		virtual void onDetach();
		void onUpdate();
		void onEvent(Event& event);
	private:
		float time = 0.0f;
		bool mouseJustPressed[3] = { false, false, false };

	private:
		bool onMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool onMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool onMouseMovedEvent(MouseMovedEvent& e);
		bool onMouseScrolledEvent(MouseScrolledEvent& e);
		bool onKeyPressedEvent(KeyPressedEvent& e);
		bool onKeyReleasedEvent(KeyReleasedEvent& e);
		bool onKeyTypedEvent(KeyTypedEvent& e);
		bool onWindowResizedEvent(WindowResizeEvent& e);
	};
}
