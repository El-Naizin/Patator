#pragma once

#include "Event.h"

namespace pat {

	class KeyEvent : public Event {
	public:
		inline int getKeyCode() const { return keyCode; }

		EVENT_CLASS_CATEGORY(EventCategory::KEYBOARD | EventCategory::INPUT)
	protected:
		KeyEvent(int keyCode) : keyCode(keyCode) {} //Constructeur affecte keyCode a keyCode

		int keyCode;
	};

	class KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int keyCode) : KeyEvent(keyCode) {}

		std::string toString() const override {
			std::string res;
			res = "KeyPressedEvent: ";
			res.append(std::to_string(keyCode));
			return res;
		}

		EVENT_CLASS_TYPE(PAT_KEY_PRESSED)
	};

	class KeyTypedEvent : public KeyEvent {
	public:
		KeyTypedEvent(int keyCode) : KeyEvent(keyCode) {}

		std::string toString() const override {
			std::string res;
			res = "KeyPressedEvent: ";
			res.append(std::to_string(keyCode));
			return res;
		}

		EVENT_CLASS_TYPE(PAT_KEY_TYPED)
	private:
		int repeatCount;
	};

	class KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(int keyCode) : KeyEvent(keyCode) {}
		
		std::string toString() const override {
			std::string res;
			res = "KeyPressedEvent: ";
			res.append(std::to_string(keyCode));
			return res;
		}

		EVENT_CLASS_TYPE(PAT_KEY_RELEASED)
	};

}
