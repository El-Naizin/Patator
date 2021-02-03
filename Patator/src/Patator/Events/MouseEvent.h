#pragma once

#include "Event.h"

namespace pat {
	
	class MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(float x, float y)
			: mouseX(x), mouseY(y) {}

		inline float getX() const { return mouseX; }
		inline float getY() const { return mouseY; }

		std::string toString() const override {
			std::string res;
			res = "MouseMovedEvent: X=";
			res.append(std::to_string(mouseX));
			res.append(", Y=");
			res.append(std::to_string(mouseY));
			return res;
		}

		EVENT_CLASS_TYPE(PAT_MOUSE_MOVED)
		EVENT_CLASS_CATEGORY(EventCategory::INPUT | EventCategory::MOUSE)
	private:
		float mouseX, mouseY;
	};

	class MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(float offsetX, float offsetY)
			: offsetX(offsetX), offsetY(offsetY) {}

		inline float getOffsetX() const { return offsetX; }
		inline float getOffsetY() const { return offsetY; }

		std::string toString() const override {
			std::string res;
			res = "MouseScrolledEvent: X=";
			res.append(std::to_string(offsetX));
			res.append(", Y=");
			res.append(std::to_string(offsetY));
			return res;
		}

		EVENT_CLASS_TYPE(PAT_MOUSE_SCROLLED)
		EVENT_CLASS_CATEGORY(EventCategory::INPUT | EventCategory::MOUSE)
	private:
		float offsetX, offsetY;
	};

	class MouseButtonEvent : public Event {
	public:
		inline int getMouseButton() const { return button; }

		EVENT_CLASS_CATEGORY(EventCategory::INPUT | EventCategory::MOUSE | EventCategory::MOUSE_BUTTON)
	protected:
		MouseButtonEvent(int button)
			: button(button) {}

		int button;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string toString() const override {
			std::string res;
			res = "MousePressedEvent: ";
			res.append(std::to_string(button));
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
			res.append(std::to_string(button));
			return res;
		}

		EVENT_CLASS_TYPE(PAT_MOUSE_BUTTON_RELEASED)
	};
}
