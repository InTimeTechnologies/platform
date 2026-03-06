#include "Key.h"

namespace it {
	bool Key::inTransientState() const {
		return justPressed || repeat || justReleased;
	}
 	void Key::feedAction(Action action) {
		switch (action) {
			case Action::PRESS:
				justPressed = true;
				pressed = true;
				break;
			case Action::REPEAT:
				repeat = true;
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
