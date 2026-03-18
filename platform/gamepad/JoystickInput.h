#pragma once

// Dependencies | std
#include <array>

// Dependencies | it::platform
#include "Joystick.h"

namespace it {
	namespace platform {
		class JoystickInput {
			// Friends
			friend class Platform;

			// Object
			private:
				// Properties
				std::array<Joystick, static_cast<size_t>(16)> gamepads{
					Joystick{ JoystickCode::JOYSTICK_0 },
					Joystick{ JoystickCode::JOYSTICK_1 },
					Joystick{ JoystickCode::JOYSTICK_2 },
					Joystick{ JoystickCode::JOYSTICK_3 },
					Joystick{ JoystickCode::JOYSTICK_4 },
					Joystick{ JoystickCode::JOYSTICK_5 },
					Joystick{ JoystickCode::JOYSTICK_6 },
					Joystick{ JoystickCode::JOYSTICK_7 },
					Joystick{ JoystickCode::JOYSTICK_8 },
					Joystick{ JoystickCode::JOYSTICK_9 },
					Joystick{ JoystickCode::JOYSTICK_10 },
					Joystick{ JoystickCode::JOYSTICK_11 },
					Joystick{ JoystickCode::JOYSTICK_12 },
					Joystick{ JoystickCode::JOYSTICK_13 },
					Joystick{ JoystickCode::JOYSTICK_14 },
					Joystick{ JoystickCode::JOYSTICK_15 }
				};
	
			public:
				// Getters
				const std::array<Joystick, static_cast<size_t>(16)>& getGamepads() const;
	
				Joystick& getGamepad(JoystickCode joystickCode);
				size_t getGamepadIndex(JoystickCode joystickCode) const;
	
				void feedAction(JoystickCode joystickCode, bool connected);
				void feedAction(JoystickCode joystickCode, JoystickButtonCode joystickButtoneCode, JoystickButtonAction action);
				void feedAction(JoystickCode joystickCode, JoystickAxisCode joystickAxisCode, float value);
				void reset();
				void resetTransientStates();
		};
	}
}
