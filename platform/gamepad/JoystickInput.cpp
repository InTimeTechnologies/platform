#include "JoystickInput.h"

namespace it {
	namespace platform {
		// class JoystickInput
	
		// Object | public
	
		// Getters
		const std::array<Joystick, static_cast<size_t>(16)>& JoystickInput::getGamepads() const {
			return gamepads;
		}
	
		Joystick& JoystickInput::getGamepad(JoystickCode gamepadCode) {
			size_t i = getGamepadIndex(gamepadCode);
			return gamepads[i];
		}
		size_t JoystickInput::getGamepadIndex(JoystickCode gamepadCode) const {
			size_t i = static_cast<size_t>(gamepadCode);
			size_t count = static_cast<size_t>(16);
			return i < count ? i : 0;
		}
	
		// Functions
		void JoystickInput::feedAction(JoystickCode gamepadCode, bool connected) {
			size_t i = getGamepadIndex(gamepadCode);
			gamepads[i].connected = connected;
		}
		void JoystickInput::feedAction(JoystickCode gamepadCode, JoystickButtonCode gamepadButtonCode, JoystickButtonAction action) {
			size_t i = getGamepadIndex(gamepadCode);
			gamepads[i].feedEvent(gamepadButtonCode, action);
		}
		void JoystickInput::feedAction(JoystickCode gamepadCode, JoystickAxisCode gamepadAxisCode, float value) {
			size_t i = getGamepadIndex(gamepadCode);
			gamepads[i].feedEvent(gamepadAxisCode, value);
		}
		void JoystickInput::reset() {
			for (size_t i = 0; i < gamepads.size(); i++)
				gamepads[i].reset();
		}
		void JoystickInput::resetTransientStates() {
			for (size_t i = 0; i < gamepads.size(); i++)
				gamepads[i].resetTransientState();
		}
	}
}
