#include "JoystickButton.h"

namespace it {
	namespace platform {
		// struct JoysticButton
	
		// Functions
		bool JoystickButton::inTransientState() const {
			return justPressed || justReleased;
		}
		void JoystickButton::feedAction(JoystickButtonAction action) {
			switch (action) {
				case JoystickButtonAction::PRESSED:
					justPressed = true;
					pressed = true;
					break;
				case JoystickButtonAction::RELEASED:
					justReleased = true;
					pressed = false;
					break;
				case JoystickButtonAction::UNKNOWN:
				default:
					break;
			}
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
