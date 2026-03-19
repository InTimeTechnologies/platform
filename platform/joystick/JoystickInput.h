#pragma once

// Dependencies | std
#include <vector>

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
				std::vector<Joystick> joysticks {
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
				const std::vector<Joystick>& getGamepads() const;
				const Joystick& getJoystick(JoystickCode joystickCode) const;
	
				void reset();
				void resetTransientStates();
		};
	}
}
