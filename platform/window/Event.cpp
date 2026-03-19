#include "Event.h"

namespace it {
	namespace platform {
		// struct MoveEvent
	
		// Functions | Event
		EventType MoveEvent::getType() const {
			return EventType::MOVE;
		}

		// struct ResizeEvent

		// Functions
		EventType ResizeEvent::getType() const {
			return EventType::RESIZE;
		}

		// struct WindowCloseEvent

		// Functions
		EventType WindowCloseEvent::getType() const {
			return EventType::WINDOW_CLOSE;
		}

		// struct FocusEvent

		// Functions
		EventType FocusEvent::getType() const {
			return EventType::FOCUS;
		}

		// struct IconifyEvent

		// Functions
		EventType IconifyEvent::getType() const {
			return EventType::ICONIFY;
		}
		
		// struct RefreshEvent

		// Functions
		EventType RefreshEvent::getType() const {
			return EventType::REFRESH;
		}

		// struct WindowMaximizeEvent

		// Functions
		EventType WindowMaximizeEvent::getType() const {
			return EventType::WINDOW_MAXIMIZE;
		}

		// struct ContentScaleEvent

		// Functions
		EventType ContentScaleEvent::getType() const {
			return EventType::CONTENT_SCALE;
		}

		// struct KeyEvent

		// Functions
		EventType KeyEvent::getType() const {
			return EventType::KEY;
		}

		// struct MouseButtonEvent

		// Functions
		EventType MouseButtonEvent::getType() const {
			return EventType::MOUSE_BUTTON;
		}

		// struct MousePositionEvent

		// Functions
		EventType MousePositionEvent::getType() const {
			return EventType::MOUSE_POSITION;
		}
	}
}
