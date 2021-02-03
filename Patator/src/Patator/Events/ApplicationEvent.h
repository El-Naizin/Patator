#pragma once

#include "Event.h"

namespace pat {
	class WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: width(width), height(height) {}

		inline unsigned int getWidth() const { return width; }
		inline unsigned int getHeight() const { return height; }

		std::string toString() const override {
			std::string res;
			res = "WindowResizeEvent: Width=";
			res.append(std::to_string(width));
			res.append(", Height=");
			res.append(std::to_string(height));
			return res;
		}

		EVENT_CLASS_TYPE(PAT_WINDOW_RESIZE)
		EVENT_CLASS_CATEGORY(EventCategory::APPLICATION)
	private:
		unsigned int width, height;
	};

	class WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() {}

		std::string toString() const override {
			std::string res;
			res = "WindowCloseEvent.";
			return res;
		}

		EVENT_CLASS_TYPE(PAT_WINDOW_CLOSE)
		EVENT_CLASS_CATEGORY(EventCategory::APPLICATION)
	};
}
