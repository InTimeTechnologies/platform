#include "GamepadInput.h"

namespace it {
	namespace platform {
		// class GamepadInput
	
		// Object | public
	
		// Getters
		const std::array<Gamepad, static_cast<size_t>(GamepadCode::COUNT)>& GamepadInput::getJoysticks() const {
			return gamepads;
		}
	
		const Gamepad& GamepadInput::getJoystick(GamepadCode joystickCode) const {
			size_t i = getJoystickIndex(joystickCode);
			return gamepads[i];
		}
		size_t GamepadInput::getJoystickIndex(GamepadCode joystickCode) const {
			size_t i = static_cast<size_t>(joystickCode);
			size_t count = static_cast<size_t>(GamepadCode::COUNT);
			return i < count ? i : 0;
		}
	
		// Functions
		void GamepadInput::feedAction(GamepadCode joystickCode, bool connected) {
			size_t i = getJoystickIndex(joystickCode);
			gamepads[i].connected = connected;
		}
		void GamepadInput::feedAction(GamepadCode joystickCode, GamepadButtonCode joystickButtonCode, GamepadButtonAction action) {
			size_t i = getJoystickIndex(joystickCode);
			gamepads[i].feedEvent(joystickButtonCode, action);
		}
		void GamepadInput::feedAction(GamepadCode joystickCode, GamepadAxisCode joystickAxisCode, float value) {
			size_t i = getJoystickIndex(joystickCode);
			gamepads[i].feedEvent(joystickAxisCode, value);
		}
		void GamepadInput::reset() {
			for (size_t i = 0; i < gamepads.size(); i++)
				gamepads[i].reset();
		}
		void GamepadInput::resetTransientStates() {
			for (size_t i = 0; i < gamepads.size(); i++)
				gamepads[i].resetTransientState();
		}
	}
}
