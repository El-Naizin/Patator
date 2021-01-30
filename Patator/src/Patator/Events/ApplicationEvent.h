#pragma once

#include "Event.h"

namespace pat {
	class WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_width(width), m_height(height) {}

		inline unsigned int getWidth() const { return m_width; }
		inline unsigned int getHeight() const { return m_height; }

		std::string toString() const override {
			std::string res;
			res = "WindowResizeEvent: Width=";
			res.append(std::to_string(m_width));
			res.append(", Height=");
			res.append(std::to_string(m_height));
			return res;
		}

		EVENT_CLASS_TYPE(PAT_WINDOW_RESIZE)
		EVENT_CLASS_CATEGORY(EventCategory::APPLICATION)
	private:
		unsigned int m_width, m_height;
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
