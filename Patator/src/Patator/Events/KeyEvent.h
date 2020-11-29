#pragma once

#include "Event.h"

namespace pat {

	class PAT_API KeyEvent : public Event {
	public:
		inline int getKeyCode() const { return m_keyCode; }

		EVENT_CLASS_CATEGORY(EventCategory::KEYBOARD | EventCategory::INPUT)
	protected:
		KeyEvent(int keyCode) : m_keyCode(keyCode) {} //Constructeur affecte keyCode a m_keyCode

		int m_keyCode;
	};

	class PAT_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int keyCode) : KeyEvent(keyCode) {}

		std::string toString() const override {
			std::string res;
			res = "KeyPressedEvent: ";
			res.append(std::to_string(m_keyCode));
			return res;
		}

		EVENT_CLASS_TYPE(PAT_KEY_PRESSED)
	};

	class PAT_API KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(int keyCode) : KeyEvent(keyCode) {}
		
		std::string toString() const override {
			std::string res;
			res = "KeyPressedEvent: ";
			res.append(std::to_string(m_keyCode));
			return res;
		}

		EVENT_CLASS_TYPE(PAT_KEY_RELEASED)
	};

}
