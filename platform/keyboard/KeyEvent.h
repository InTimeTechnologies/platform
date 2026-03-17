#pragma once

// Dependencies | it::platform
#include <keyboard/Key.h>

namespace it {
	namespace platform {
		struct KeyEvent {
			// Object

			// Properties
			KeyCode keyCode{ KeyCode::UNKNOWN };
			int scanCode{ -1 };
			KeyAction action{ KeyAction::UNKNOWN };
			int modifier{ -1 };
		};
	}
}
