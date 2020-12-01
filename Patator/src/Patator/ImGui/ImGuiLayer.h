#pragma once

#include "Patator/Layer.h"

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
	};
}
