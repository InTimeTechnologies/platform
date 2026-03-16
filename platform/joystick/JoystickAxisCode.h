#pragma once

namespace it {
	namespace platform {
		enum class JoystickAxisCode : size_t {
			UNKNOWN,
			LEFT_X,
			LEFT_Y,
			RIGHT_X,
			RIGHT_Y,
			LEFT_TRIGGER,
			RIGHT_TRIGGER,
			COUNT
		};
	}
}
