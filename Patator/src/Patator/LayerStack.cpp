#include <patpch.h>
#include "LayerStack.h"
#include <Patator/Log.h>

namespace pat {
	LayerStack::LayerStack() {
	}

	LayerStack::~LayerStack() {
		for (auto layer : layers) {
			delete layer;
		}
	}

	void LayerStack::pushLayer(Layer* layer) {
		layers.emplace(layers.begin() + layerInsertIndex, layer);
		layerInsertIndex++;
	}

	void LayerStack::popLayer(Layer* layer) {
		auto it = std::find(layers.begin(), layers.end(), layer);
		if (it != layers.end()) {
			layers.erase(it);
			layerInsertIndex--;
		}
	}

	void LayerStack::pushOverLay(Layer* overlay) {
		layers.emplace_back(overlay);
	}

	void LayerStack::popOverlay(Layer* overlay) {
		auto it = std::find(layers.begin(), layers.end(), overlay);
		if (it != layers.end()) {
			layers.erase(it);
		}
	}
}
