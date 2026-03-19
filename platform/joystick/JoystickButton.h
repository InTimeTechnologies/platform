#pragma once

// Dependencies | std
#include <string>

// Dependencies | it::platform
#include "JoystickButtonCode.h"
#include "JoystickButtonAction.h"

namespace it {
	namespace platform {
		struct JoystickButton {
			// Properties
			JoystickButtonCode buttonCode{ JoystickButtonCode::UNKNOWN };
			bool justPressed{ false };
			bool justReleased{ false };
			bool pressed{ false };
			std::string description{};
	
			// Functions
			bool inTransientState() const;
			void feedAction(JoystickButtonAction action);
			void reset();
			void resetTransientState();
			void resetJustPressed();
			void resetJustReleased();
		};
	}
}
