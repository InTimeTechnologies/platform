#include "MouseButton.h"

namespace it {
	namespace platform {
		// class MouseButton
	
		// Object | public
	
		// Functions
		bool MouseButton::inTransientState() const {
			return justPressed || justReleased;
		}
		bool MouseButton::feedAction(MouseButtonAction action) {
			bool differentAction = true;

			switch (action) {
				case MouseButtonAction::PRESS:
					if (!pressed) {
						if (justPressed)
							differentAction = false;
						justPressed = true;
					}
					pressed = true;
					break;
				case MouseButtonAction::RELEASE:
					if (pressed) {
						if (justReleased)
							differentAction = false;
						justReleased = true;
					}
					pressed = false;
					break;
				case MouseButtonAction::UNKNOWN:
				default:
					differentAction = false;
					break;
			}

			return differentAction;
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
