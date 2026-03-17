#pragma once

// Dependencies | it::platform
#include <mouse/MouseButton.h>

namespace it {
	namespace platform {
		struct MouseButtonEvent {
			// Object

			// Properties
			MouseButtonCode mouseButtonCode{ MouseButtonCode::UNKNOWN };
			MouseButton::Action action{ MouseButton::Action::UNKNOWN };
		};
	}
}
