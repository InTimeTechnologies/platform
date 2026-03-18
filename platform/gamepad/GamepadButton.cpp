#include "GamepadButton.h"

namespace it {
	namespace platform {
		// struct GamepadButton
	
		// Functions
		bool GamepadButton::inTransientState() const {
			return justPressed || justReleased;
		}
		void GamepadButton::feedAction(GamepadButtonAction action) {
			switch (action) {
				case GamepadButtonAction::PRESSED:
					if (!pressed)
						justPressed = true;
					pressed = true;
					break;
				case GamepadButtonAction::RELEASED:
					if (pressed)
						justReleased = true;
					pressed = false;
					break;
				case GamepadButtonAction::UNKNOWN:
				default:
					break;
			}
		}
		void GamepadButton::reset() {
			justPressed = false;
			justReleased = false;
			pressed = false;
		}
		void GamepadButton::resetTransientState() {
			justPressed = false;
			justReleased = false;
		}
		void GamepadButton::resetJustPressed() {
			justPressed = false;
		}
		void GamepadButton::resetJustReleased() {
			justReleased = false;
		}
	}
}
