#include "MouseButton.h"

namespace it {
	namespace platform {
		// class MouseButton
	
		// Object | public
	
		// Functions
		bool MouseButton::inTransientState() const {
			return justPressed || justReleased;
		}
		void MouseButton::feedAction(Action action) {
			switch (action) {
				case Action::PRESS:
					justPressed = true;
					pressed = true;
					break;
				case Action::RELEASE:
					justReleased = true;
					pressed = false;
					break;
				case Action::UNKNOWN:
				default:
					break;
			}
		}
		void MouseButton::reset() {
			pressed = false;
			justPressed = false;
			justReleased = false;
		}
		void MouseButton::resetTransientState() {
			justPressed = false;
			justReleased = false;
		}
		void MouseButton::resetJustPressed() {
			justPressed = false;
		}
		void MouseButton::resetJustReleased() {
			justReleased = false;
		}
	}
}
