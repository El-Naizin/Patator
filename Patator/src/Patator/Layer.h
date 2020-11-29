#pragma once

#include <Patator/Core.h>
#include <Patator/Events/Event.h>
#include <string>

namespace pat {

	class PAT_API Layer {
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void onAttach() {}
		virtual void onDetach() {}
		virtual void onUpdate() {}
		virtual void onEvent(Event& event) {}

		inline const std::string& getName() const { return this->debugName; }
	protected:
		std::string debugName;
	};

}
