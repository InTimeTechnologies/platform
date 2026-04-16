#pragma once

// Dependencies | std
#include <vector>
#include <string>
#include <array>
#include <functional>

// Dependencies | it::platform
#include "JoystickButton.h"
#include "JoystickAxis.h"
#include "JoystickCode.h"

namespace it {
	namespace platform {
		class Joystick {
			// Friends
			friend class JoystickInput;
			friend class PlatformImplementation;

			// Object
			private:
				// Properties
				std::string name{ "unknown" };
				JoystickCode code{ JoystickCode::UNKNOWN };
				bool connected{ false };
				std::vector<JoystickButton> buttons{
					{ JoystickButtonCode::A, false, false, false, "A" },
					{ JoystickButtonCode::B, false, false, false, "B" },
					{ JoystickButtonCode::X, false, false, false, "X" },
					{ JoystickButtonCode::Y, false, false, false, "Y" },
					{ JoystickButtonCode::LEFT_BUMPER, false, false, false, "left_bumper" },
					{ JoystickButtonCode::RIGHT_BUMPER, false, false, false, "right_bumper" },
					{ JoystickButtonCode::BACK, false, false, false, "back" },
					{ JoystickButtonCode::START, false, false, false, "start" },
					{ JoystickButtonCode::GUIDE, false, false, false, "guide" },
					{ JoystickButtonCode::LEFT_THUMB, false, false, false, "left_thumb" },
					{ JoystickButtonCode::RIGHT_THUMB, false, false, false, "right_thumb" },
					{ JoystickButtonCode::DPAD_UP, false, false, false, "dpad_up" },
					{ JoystickButtonCode::DPAD_RIGHT, false, false, false, "dpad_right" },
					{ JoystickButtonCode::DPAD_LEFT, false, false, false, "dpad_left" },
					{ JoystickButtonCode::DPAD_DOWN, false, false, false, "dpad_down" }
				};
				std::vector<JoystickAxis> axes{
					{ JoystickAxis(JoystickAxisCode::LEFT_X, 0.0f, "left_x") },
					{ JoystickAxis(JoystickAxisCode::LEFT_Y, 0.0f, "left_y") },
					{ JoystickAxis(JoystickAxisCode::RIGHT_X, 0.0f, "right_x") },
					{ JoystickAxis(JoystickAxisCode::RIGHT_Y, 0.0f, "right_y") },
					{ JoystickAxis(JoystickAxisCode::LEFT_TRIGGER, 0.0f, "left_trigger") },
					{ JoystickAxis(JoystickAxisCode::RIGHT_TRIGGER, 0.0f, "right_trigger") }
				};
				int buttonsPressedCount{ 0 };

			public:
				// Properties | callbacks
				std::function<void(bool)> onConnection;
				std::function<void(JoystickButtonCode, JoystickButtonAction)> onGamepadButton;
		
				// Constructor / Destructor
				Joystick() = default;
				Joystick(JoystickCode gamepadCode);
				Joystick(const Joystick& other) = default;
				Joystick(Joystick&& other) noexcept = default;
				~Joystick() = default;
				
				// Operators | assignment
				Joystick& operator=(const Joystick& other) = default;
				Joystick& operator=(Joystick&& other) noexcept = default;

				// Getters
				std::string getName() const;
				JoystickCode getCode() const;
				bool getConnected() const;
				const std::vector<JoystickButton>& getButtons() const;
				const std::vector<JoystickAxis>& getAxes() const;
				const JoystickButton& getButton(JoystickButtonCode buttonCode) const;
				const JoystickAxis& getAxis(JoystickAxisCode axisCode) const;
				const JoystickButton& getButton(size_t i) const;
				const JoystickAxis& getAxis(size_t i) const;

			private:
				// Functions
				void feedConnected(bool connected);
				void feedEvent(JoystickButtonCode gamepadButtonCode, JoystickButtonAction action);
				void feedEvent(JoystickAxisCode gamepadAxisCode, float value);
				void reset();
				void resetTransientState();
		};
	}
}
