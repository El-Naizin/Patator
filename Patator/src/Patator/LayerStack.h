#pragma once

#include <Patator/Core.h>
#include "Layer.h"

#include <vector>

namespace pat {

	class PAT_API LayerStack {
	public:
		LayerStack();
		~LayerStack();

		void pushLayer(Layer* layer);
		void pushOverLay(Layer* overlay);
		void popLayer(Layer* layer);
		void popOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return layers.begin(); }
		std::vector<Layer*>::iterator end() { return layers.end(); }
	private:
		std::vector<Layer*> layers;
		std::vector<Layer*>::iterator layerInsert;
	};
}
