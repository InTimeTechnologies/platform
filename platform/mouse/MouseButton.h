#pragma once

// Dependencies | std
#include <string>

// Dependencies | it
#include "MouseButtonCode.h"
#include "MouseButtonAction.h"

namespace it {
	namespace platform {
		struct MouseButton {
			// Properties
			MouseButtonCode buttonCode{ MouseButtonCode::UNKNOWN };
			bool pressed{ false };
			bool justPressed{ false };
			bool justReleased{ false };
			std::string description{};
	
			// Functions
			bool inTransientState() const;
			void feedAction(MouseButtonAction action);
			void reset();
			void resetTransientState();
			void resetJustPressed();
			void resetJustReleased();
		};
	}
}
