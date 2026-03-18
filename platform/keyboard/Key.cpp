#include "Key.h"

namespace it {
	namespace platform {
		bool Key::inTransientState() const {
			return justPressed || repeat || justReleased;
		}
		void Key::feedAction(KeyAction action) {
			switch (action) {
				case KeyAction::PRESS:
					if (!pressed)
						justPressed = true;
					pressed = true;
					break;
				case KeyAction::REPEAT:
					repeat = true;
					break;
				case KeyAction::RELEASE:
					if (pressed)
						justReleased = true;
					pressed = false;
					break;
				case KeyAction::UNKNOWN:
				default:
					break;
			}
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
