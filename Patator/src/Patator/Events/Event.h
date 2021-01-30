#pragma once

#include "Patator/Core.h"

namespace pat {

	enum class EventType
	{
		NONE = 0,
		PAT_WINDOW_CLOSE, PAT_WINDOW_RESIZE, PAT_WINDOW_FOCUS, PAT_WINDOW_LOST_FOCUS, PAT_WINDOW_MOVED,
		PAT_KEY_PRESSED, PAT_KEY_RELEASED, PAT_KEY_TYPED,
		PAT_MOUSE_BUTTON_PRESSED, PAT_MOUSE_BUTTON_RELEASED, PAT_MOUSE_MOVED, PAT_MOUSE_SCROLLED
	};

	enum EventCategory {
		NONE = 0,
		APPLICATION   = BIT(0),
		INPUT         = BIT(1),
		KEYBOARD      = BIT(2),
		MOUSE         = BIT(3),
		MOUSE_BUTTON  = BIT(4)
	};

	//Macros usefull for declaring Event classes:
#define EVENT_CLASS_TYPE(type) static EventType getStaticType() { return EventType::##type; }\
	                            virtual EventType getEventType() const override { return getStaticType(); }\
	                            virtual const char* getName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return category; }

	class Event {
		friend class EventDispatcher;
	public:
		virtual EventType getEventType() const = 0;
		virtual const char* getName() const = 0;
		virtual int getCategoryFlags() const = 0;
		virtual std::string toString() const { return getName(); }

		inline bool isInCategory(EventCategory category) {
			return getCategoryFlags() & category;
		}
		//Need this to be public so we can check it in Application runtime
		bool handled = false;
	};

	class EventDispatcher {
		template<typename T>
		using eventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			: m_event(event) {}

		template <typename T>
		bool dispatch(eventFn<T> func) {
			if (m_event.getEventType() == T::getStaticType()) {
				m_event.handled = func(*(T*)&m_event);
				return true;
			}
			return false;
		}

	private:
		Event& m_event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.toString();
	}
}







