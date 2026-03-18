#include "GamepadInput.h"

namespace it {
	namespace platform {
		// class GamepadInput
	
		// Object | public
	
		// Getters
		const std::array<Gamepad, static_cast<size_t>(GamepadCode::COUNT)>& GamepadInput::getGamepads() const {
			return gamepads;
		}
	
		Gamepad& GamepadInput::getGamepad(GamepadCode gamepadCode) {
			size_t i = getGamepadIndex(gamepadCode);
			return gamepads[i];
		}
		size_t GamepadInput::getGamepadIndex(GamepadCode gamepadCode) const {
			size_t i = static_cast<size_t>(gamepadCode);
			size_t count = static_cast<size_t>(GamepadCode::COUNT);
			return i < count ? i : 0;
		}
	
		// Functions
		void GamepadInput::feedAction(GamepadCode gamepadCode, bool connected) {
			size_t i = getGamepadIndex(gamepadCode);
			gamepads[i].connected = connected;
		}
		void GamepadInput::feedAction(GamepadCode gamepadCode, GamepadButtonCode gamepadButtonCode, GamepadButtonAction action) {
			size_t i = getGamepadIndex(gamepadCode);
			gamepads[i].feedEvent(gamepadButtonCode, action);
		}
		void GamepadInput::feedAction(GamepadCode gamepadCode, GamepadAxisCode gamepadAxisCode, float value) {
			size_t i = getGamepadIndex(gamepadCode);
			gamepads[i].feedEvent(gamepadAxisCode, value);
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
