#include "JoystickButton.h"

namespace it {
	namespace platform {
		// struct JoystickButton
	
		// Functions
		bool JoystickButton::inTransientState() const {
			return justPressed || justReleased;
		}
		bool JoystickButton::feedAction(JoystickButtonAction action) {
			bool differentAction = true;

			switch (action) {
				case JoystickButtonAction::PRESSED:
					if (!pressed) {
						if (justPressed)
							differentAction = false;
						justPressed = true;
					}
					pressed = true;
					break;
				case JoystickButtonAction::RELEASED:
					if (pressed) {
						if (justReleased)
							differentAction = false;
						justReleased = true;
					}
					pressed = false;
					break;
				case JoystickButtonAction::UNKNOWN:
				default:
					differentAction = false;
					break;
			}

			return differentAction;
		}
		void JoystickButton::reset() {
			justPressed = false;
			justReleased = false;
			pressed = false;
		}
		void JoystickButton::resetTransientState() {
			justPressed = false;
			justReleased = false;
		}
		void JoystickButton::resetJustPressed() {
			justPressed = false;
		}
		void JoystickButton::resetJustReleased() {
			justReleased = false;
		}
	}
}
