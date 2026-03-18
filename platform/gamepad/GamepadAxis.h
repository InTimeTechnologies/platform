#pragma once

// Dependencies | std
#include <string>

// Dependencies | it::platform
#include "GamepadAxisCode.h"

namespace it {
	namespace platform {
		struct GamepadAxis {
			// Properties
			GamepadAxisCode axisCode{ GamepadAxisCode::UNKNOWN };
			float value{ 0.0f };
			std::string description{};
	
			// Functions
			void reset();
		};
	}
}