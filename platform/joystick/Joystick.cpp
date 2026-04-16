#include "Joystick.h"

// Dependencies | std
#include <cassert>

namespace it {
	namespace platform {
		// class Joystick

		// Object | public

		// Constructor / Destructor
		Joystick::Joystick(JoystickCode gamepadCode) : code(gamepadCode) {
			// Left empty intentionally
			// Properties defined in header
		}

		// Getters
		JoystickCode Joystick::getCode() const {
			return code;
		}
		bool Joystick::getConnected() const {
			return connected;
		}
		const std::vector<JoystickButton>& Joystick::getButtons() const {
			return buttons;
		}
		const std::vector<JoystickAxis>& Joystick::getAxes() const {
			return axes;
		}
		const JoystickButton& Joystick::getButton(JoystickButtonCode buttonCode) const {
			size_t i = static_cast<size_t>(buttonCode);
			assert(i < buttons.size() && "Index i out of bounds.");
			return buttons[i];
		}
		const JoystickAxis& Joystick::getAxis(JoystickAxisCode axisCode) const {
			size_t i = static_cast<size_t>(axisCode);
			assert(i < axes.size() && "Index i out of bounds.");
			return axes[i];
		}
		const JoystickButton& Joystick::getButton(size_t i) const {
			assert(i < buttons.size() && "Index i out of bounds.");
			return buttons[i];
		}
		const JoystickAxis& Joystick::getAxis(size_t i) const {
			assert(i < axes.size() && "Index i out of bounds.");
			return axes[i];
		}
		std::string Joystick::getName() const {
			return name;
		}

		// Object | private
		
		// Functions
		void Joystick::feedConnected(bool connected) {
			bool connectionChanged = this->connected != connected;
			this->connected = connected;
			
			if (connectionChanged && static_cast<bool>(onConnection))
				onConnection(connected);
		}
		void Joystick::feedEvent(JoystickButtonCode buttonCode, JoystickButtonAction action) {
			size_t i = static_cast<size_t>(buttonCode);
			assert(i < axes.size() && "Index i out of bounds.");

			bool differentAction = buttons[i].feedAction(action);

			if (static_cast<bool>(onGamepadButton))
				onGamepadButton(buttonCode, action);

			if (differentAction) {
				if (buttons[i].justPressed) {
					buttonsPressedCount++;
					if (static_cast<size_t>(buttonsPressedCount) > buttons.size())
						buttonsPressedCount = buttons.size();
				}
				if (buttons[i].justReleased) {
					buttonsPressedCount--;
					if (buttonsPressedCount < 0)
						buttonsPressedCount = 0;
				}
			}
		}
		void Joystick::feedEvent(JoystickAxisCode axisCode, float value) {
			size_t i = static_cast<size_t>(axisCode);
			assert(i < axes.size() && "Index i out of bounds.");
		
			axes[i].value = value;
		}
		void Joystick::reset() {
			for (size_t i = 0; i < buttons.size(); i++)
				buttons[i].reset();
			buttonsPressedCount = 0;
			for (size_t i = 0; i < axes.size(); i++)
				axes[i].reset();
		}
		void Joystick::resetTransientState() {
			for (size_t i = 0; i < buttons.size(); i++)
				buttons[i].resetTransientState();
		}
	}
}
