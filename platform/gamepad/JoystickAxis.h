#pragma once

// Dependencies | std
#include <string>

// Dependencies | it::platform
#include "JoystickAxisCode.h"

namespace it {
	namespace platform {
		struct JoystickAxis {
			// Properties
			JoystickAxisCode axisCode{ JoystickAxisCode::UNKNOWN };
			float value{ 0.0f };
			std::string description{};
	
			// Functions
			void reset();
		};
	}
}