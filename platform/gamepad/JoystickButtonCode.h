#pragma once

namespace it {
	namespace platform {
		enum class JoystickButtonCode : int {
			UNKNOWN = -1,
			A,
			B,
			X,
			Y,
			LEFT_BUMPER,
			RIGHT_BUMPER,
			BACK,
			START,
			GUIDE,
			LEFT_THUMB,
			RIGHT_THUMB,
			DPAD_UP,
			DPAD_RIGHT,
			DPAD_DOWN,
			DPAD_LEFT,
			COUNT
		};
	}
}
