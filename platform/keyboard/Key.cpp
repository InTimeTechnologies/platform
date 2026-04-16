#include "Key.h"

namespace it {
	namespace platform {
		bool Key::inTransientState() const {
			return justPressed || repeat || justReleased;
		}
		bool Key::feedAction(KeyAction action) {
			bool differentAction = true;

			switch (action) {
				case KeyAction::PRESS:
					if (!pressed) {
						if (justPressed == true)
							differentAction = false;
						justPressed = true;
					}
					pressed = true;
					break;
				case KeyAction::REPEAT:
					repeat = true;
					break;
				case KeyAction::RELEASE:
					if (pressed) {
						if (justReleased)
							differentAction = false;
						justReleased = true;
					}
					pressed = false;
					break;
				case KeyAction::UNKNOWN:
				default:
					differentAction = false;
					break;
			}

			return differentAction;
		}
		void Key::reset() {
			justPressed = false;
			repeat = false;
			justReleased = false;
			pressed = false;
		}
		void Key::resetTransientState() {
			justPressed = false;
			repeat = false;
			justReleased = false;
		}
		void Key::resetJustPressed() {
			justPressed = false;
			repeat = false;
		}
		void Key::resetJustReleased() {
			justReleased = false;
		}
	}
}
