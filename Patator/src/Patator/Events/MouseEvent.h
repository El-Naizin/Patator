#pragma once

#include "Event.h"

namespace pat {
	
	class MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(float x, float y)
			: m_mouseX(x), m_mouseY(y) {}

		inline float getX() const { return m_mouseX; }
		inline float getY() const { return m_mouseY; }

		std::string toString() const override {
			std::string res;
			res = "MouseMovedEvent: X=";
			res.append(std::to_string(m_mouseX));
			res.append(", Y=");
			res.append(std::to_string(m_mouseY));
			return res;
		}

		EVENT_CLASS_TYPE(PAT_MOUSE_MOVED)
		EVENT_CLASS_CATEGORY(EventCategory::INPUT | EventCategory::MOUSE)
	private:
		float m_mouseX, m_mouseY;
	};

	class MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(float offsetX, float offsetY)
			: m_offsetX(offsetX), m_offsetY(offsetY) {}

		inline float getOffsetX() const { return m_offsetX; }
		inline float getOffsetY() const { return m_offsetY; }

		std::string toString() const override {
			std::string res;
			res = "MouseScrolledEvent: X=";
			res.append(std::to_string(m_offsetX));
			res.append(", Y=");
			res.append(std::to_string(m_offsetY));
			return res;
		}

		EVENT_CLASS_TYPE(PAT_MOUSE_SCROLLED)
		EVENT_CLASS_CATEGORY(EventCategory::INPUT | EventCategory::MOUSE)
	private:
		float m_offsetX, m_offsetY;
	};

	class MouseButtonEvent : public Event {
	public:
		inline int getMouseButton() const { return m_button; }

		EVENT_CLASS_CATEGORY(EventCategory::INPUT | EventCategory::MOUSE | EventCategory::MOUSE_BUTTON)
	protected:
		MouseButtonEvent(int button)
			: m_button(button) {}

		int m_button;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string toString() const override {
			std::string res;
			res = "MousePressedEvent: ";
			res.append(std::to_string(m_button));
			return res;
		}

		EVENT_CLASS_TYPE(PAT_MOUSE_BUTTON_PRESSED)
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string toString() const override {
			std::string res;
			res = "MouseReleasedEvent: ";
			res.append(std::to_string(m_button));
			return res;
		}

		EVENT_CLASS_TYPE(PAT_MOUSE_BUTTON_RELEASED)
	};
}
