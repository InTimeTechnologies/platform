#pragma once

// Dependencies | std
#include <array>

// Dependencies | it::platform
#include "Gamepad.h"

namespace it {
	namespace platform {
		class GamepadInput {
			// Friends
			friend class Platform;

			// Object
			private:
				// Properties
				std::array<Gamepad, static_cast<size_t>(GamepadCode::COUNT)> gamepads{
					Gamepad{ GamepadCode::GAMEPAD_0 },
					Gamepad{ GamepadCode::GAMEPAD_1 },
					Gamepad{ GamepadCode::GAMEPAD_2 },
					Gamepad{ GamepadCode::GAMEPAD_3 },
					Gamepad{ GamepadCode::GAMEPAD_4 },
					Gamepad{ GamepadCode::GAMEPAD_5 },
					Gamepad{ GamepadCode::GAMEPAD_6 },
					Gamepad{ GamepadCode::GAMEPAD_7 },
					Gamepad{ GamepadCode::GAMEPAD_8 },
					Gamepad{ GamepadCode::GAMEPAD_9 },
					Gamepad{ GamepadCode::GAMEPAD_10 },
					Gamepad{ GamepadCode::GAMEPAD_11 },
					Gamepad{ GamepadCode::GAMEPAD_12 },
					Gamepad{ GamepadCode::GAMEPAD_13 },
					Gamepad{ GamepadCode::GAMEPAD_14 },
					Gamepad{ GamepadCode::GAMEPAD_15 }
				};
	
			public:
				// Getters
				const std::array<Gamepad, static_cast<size_t>(GamepadCode::COUNT)>& getGamepads() const;
	
				Gamepad& getGamepad(GamepadCode joystickCode);
				size_t getGamepadIndex(GamepadCode joystickCode) const;
	
				void feedAction(GamepadCode joystickCode, bool connected);
				void feedAction(GamepadCode joystickCode, GamepadButtonCode joystickButtoneCode, GamepadButtonAction action);
				void feedAction(GamepadCode joystickCode, GamepadAxisCode joystickAxisCode, float value);
				void reset();
				void resetTransientStates();
		};
	}
}
