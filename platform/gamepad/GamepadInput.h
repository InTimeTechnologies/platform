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
					Gamepad{ GamepadCode::CONTROLLER_0 },
					Gamepad{ GamepadCode::CONTROLLER_1 },
					Gamepad{ GamepadCode::CONTROLLER_2 },
					Gamepad{ GamepadCode::CONTROLLER_3 },
					Gamepad{ GamepadCode::CONTROLLER_4 },
					Gamepad{ GamepadCode::CONTROLLER_5 },
					Gamepad{ GamepadCode::CONTROLLER_6 },
					Gamepad{ GamepadCode::CONTROLLER_7 },
					Gamepad{ GamepadCode::CONTROLLER_8 },
					Gamepad{ GamepadCode::CONTROLLER_9 },
					Gamepad{ GamepadCode::CONTROLLER_10 },
					Gamepad{ GamepadCode::CONTROLLER_11 },
					Gamepad{ GamepadCode::CONTROLLER_12 },
					Gamepad{ GamepadCode::CONTROLLER_13 },
					Gamepad{ GamepadCode::CONTROLLER_14 },
					Gamepad{ GamepadCode::CONTROLLER_15 }
				};
	
			public:
				// Getters
				const std::array<Gamepad, static_cast<size_t>(GamepadCode::COUNT)>& getJoysticks() const;
	
				const Gamepad& getJoystick(GamepadCode joystickCode) const;
				size_t getJoystickIndex(GamepadCode joystickCode) const;
	
				void feedAction(GamepadCode joystickCode, bool connected);
				void feedAction(GamepadCode joystickCode, GamepadButtonCode joystickButtoneCode, GamepadButtonAction action);
				void feedAction(GamepadCode joystickCode, GamepadAxisCode joystickAxisCode, float value);
				void reset();
				void resetTransientStates();
		};
	}
}
