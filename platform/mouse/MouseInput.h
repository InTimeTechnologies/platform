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
			// Friends
			friend class PlatformImplementation;

			// Object
			private:
				// Properties
				std::vector<MouseButton> mouseButtons{};
				int x{ 0 };
				int y{ 0 };
				double xScroll{ 0.0 };
				double yScroll{ 0.0 };
				std::forward_list<MouseButton*> mouseButtonsInTransientState{};
				int mouseButtonsPressedCount{ 0 };
	
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
				const std::vector<MouseButton>& getMouseButtons() const;
				int getMouseButtonsPressedCount() const;
				const std::forward_list<MouseButton*>& getMouseButtonsToReset() const;
				const MouseButton& getMouseButton(MouseButtonCode mouseButtonCode) const;
	
			private:
				// Functions
				void feedEvent(MouseButtonCode code, MouseButtonAction action);
				void reset();
				void resetTransientStates();
		};
	}
}
