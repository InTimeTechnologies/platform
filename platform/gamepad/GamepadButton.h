#pragma once

// Dependencies | std
#include <string>

// Dependencies | it::platform
#include "GamepadButtonCode.h"
#include "GamepadButtonAction.h"

namespace it {
	namespace platform {
		struct GamepadButton {
			// Properties
			GamepadButtonCode buttonCode{ GamepadButtonCode::UNKNOWN };
			bool justPressed{ false };
			bool justReleased{ false };
			bool pressed{ false };
			std::string description{};
	
			// Functions
			bool inTransientState() const;
			void feedAction(GamepadButtonAction action);
			void reset();
			void resetTransientState();
			void resetJustPressed();
			void resetJustReleased();
		};
	}
}
