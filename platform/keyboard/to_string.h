#pragma once

// Dependencies | std
#include <string>

// Dependencies | it::platform
#include "KeyCode.h"
#include "KeyAction.h"
#include "Key.h"
#include "KeyEvent.h"

namespace it {
	namespace platform {
		std::string to_string(KeyCode keyCode);
		std::string to_string(KeyAction keyAction);
		std::string to_string(const Key& key);
		std::string to_string(const KeyEvent& keyEvent);
	}
}
