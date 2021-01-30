#pragma once

#include "Patator/Layer.h"
#include <Patator/Events/MouseEvent.h>
#include <Patator/Events/KeyEvent.h>
#include <Patator/Events/ApplicationEvent.h>

namespace pat {

	class ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void onAttach() override;
		virtual void onDetach() override;
		virtual void onImGuiRender() override;

		void begin();
		void end();
	private:
		float time = 0.0f;
	};
}
