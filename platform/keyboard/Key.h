#pragma once

// Dependencies | std
#include <string>

// Dependencies | it
#include "KeyCode.h"
#include "KeyAction.h"

namespace it {
	namespace platform {
		struct Key {
			// Properties
			KeyCode keyCode{ KeyCode::UNKNOWN };
			bool justPressed{ false };
			bool repeat{ false };
			bool justReleased{ false };
			bool pressed{ false };
			std::string description{};
	
			// Functions
			bool inTransientState() const;
			bool feedAction(KeyAction action);
			void reset();
			void resetTransientState();
			void resetJustPressed();
			void resetJustReleased();
		};
	}
}
