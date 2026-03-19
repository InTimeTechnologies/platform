#pragma once

// Dependencies | std
#include <array>
#include <vector>
#include <forward_list>

// Dependencies | it
#include "MouseButton.h"

namespace it {
	namespace platform {
		class MouseInput {
			// Object
			private:
				// Properties
				std::forward_list<MouseButton*> mouseButtonsInTransientState{};
				std::vector<MouseButton> mouseButtons{};
	
			public:
				// Constructor / Destructor
				MouseInput();
				MouseInput(const MouseInput& other) = default;
				MouseInput(MouseInput&& other) noexcept = default;
				~MouseInput() = default;
	
				// Operators | assignment
				MouseInput& operator=(const MouseInput& other) = default;
				MouseInput& operator=(MouseInput&& other) noexcept = default;
	
				// Getters
				const std::forward_list<MouseButton*>& getMouseButtonsToReset() const;
				const std::vector<MouseButton>& getMouseButtons() const;
				const MouseButton& getMouseButton(MouseButtonCode mouseButtonCode) const;
	
				// Functions
				void feedEvent(MouseButtonCode code, MouseButtonAction action);
				void reset();
				void resetTransientStates();
				void resetAllTransientStates();
		};
	}
}
