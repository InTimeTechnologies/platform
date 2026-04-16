#include "MouseInput.h"

namespace it {
	namespace platform {
		// class MouseInput
	
		// Object | public
	
		// Constructor / Destructor
		MouseInput::MouseInput() {
			mouseButtons.resize(8);
			size_t i = 0;
			mouseButtons[i++] = MouseButton{ MouseButtonCode::BUTTON_CODE_1, false, false, false, "left button" };
			mouseButtons[i++] = MouseButton{ MouseButtonCode::BUTTON_CODE_2, false, false, false, "right button" };
			mouseButtons[i++] = MouseButton{ MouseButtonCode::BUTTON_CODE_3, false, false, false, "middle button" };
			mouseButtons[i++] = MouseButton{ MouseButtonCode::BUTTON_CODE_4, false, false, false, "button 4" };
			mouseButtons[i++] = MouseButton{ MouseButtonCode::BUTTON_CODE_5, false, false, false, "button 5" };
			mouseButtons[i++] = MouseButton{ MouseButtonCode::BUTTON_CODE_6, false, false, false, "button 6" };
			mouseButtons[i++] = MouseButton{ MouseButtonCode::BUTTON_CODE_7, false, false, false, "button 7" };
			mouseButtons[i++] = MouseButton{ MouseButtonCode::BUTTON_CODE_8, false, false, false, "button 8" };
		}
	
		// Getters
		const std::vector<MouseButton>& MouseInput::getMouseButtons() const {
			return mouseButtons;
		}
		int MouseInput::getMouseButtonsPressedCount() const {
			return mouseButtonsPressedCount;
		}
		const std::forward_list<MouseButton*>& MouseInput::getMouseButtonsToReset() const {
			return mouseButtonsInTransientState;
		}
		const MouseButton& MouseInput::getMouseButton(MouseButtonCode mouseButtonCode) const {
			size_t i = static_cast<size_t>(mouseButtonCode);
			return mouseButtons[i];
		}
	
		// Object | private

		// Functions
		void MouseInput::feedEvent(MouseButtonCode code, MouseButtonAction action) {
			size_t i = static_cast<size_t>(code);
	
			if (!mouseButtons[i].inTransientState())
				mouseButtonsInTransientState.push_front(&mouseButtons[i]);
	
			bool newAction = mouseButtons[i].feedAction(action);

			if (newAction) {
				if (mouseButtons[i].justPressed)
					mouseButtonsPressedCount++;
				if (mouseButtons[i].justReleased)
					mouseButtonsPressedCount--;
			}
		}
		void MouseInput::reset() {
			for (size_t i = 0; i < mouseButtons.size(); i++)
				mouseButtons[i].reset();
			mouseButtonsInTransientState.clear();
			mouseButtonsPressedCount = 0;
		}
		void MouseInput::resetTransientStates() {
			for (MouseButton* mouseButton : mouseButtonsInTransientState)
				mouseButton->resetTransientState();
			mouseButtonsInTransientState.clear();
		}
	}
}
