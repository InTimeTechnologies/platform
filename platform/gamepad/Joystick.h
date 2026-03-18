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
			friend class Platform;

			// Object
			private:
				// Properties
				JoystickCode code{ JoystickCode::UNKNOWN };
		
				bool connected{ false };

				JoystickButton buttonA{ JoystickButtonCode::A, false, false, false, "A" };
				JoystickButton buttonB{ JoystickButtonCode::B, false, false, false, "B" };
				JoystickButton buttonX{ JoystickButtonCode::X, false, false, false, "X" };
				JoystickButton buttonY{ JoystickButtonCode::Y, false, false, false, "Y" };
		
				JoystickButton buttonLeftBumper{ JoystickButtonCode::LEFT_BUMPER, false, false, false, "left_bumper" };
				JoystickButton buttonRightBumper{ JoystickButtonCode::RIGHT_BUMPER, false, false, false, "right_bumper" };
		
				JoystickButton buttonBack{ JoystickButtonCode::BACK, false, false, false, "back" };
				JoystickButton buttonStart{ JoystickButtonCode::START, false, false, false, "start" };
				JoystickButton buttonGuide{ JoystickButtonCode::GUIDE, false, false, false, "guide" };
		
				JoystickButton buttonLeftThumb{ JoystickButtonCode::LEFT_THUMB, false, false, false, "left_thumb" };
				JoystickButton buttonRightThumb{ JoystickButtonCode::RIGHT_THUMB, false, false, false, "right_thumb" };
		
				JoystickButton buttonDpadUp{ JoystickButtonCode::DPAD_UP, false, false, false, "dpad_up" };
				JoystickButton buttonDpadRight{ JoystickButtonCode::DPAD_RIGHT, false, false, false, "dpad_right" };
				JoystickButton buttonDpadLeft{ JoystickButtonCode::DPAD_LEFT, false, false, false, "dpad_left" };
				JoystickButton buttonDpadDown{ JoystickButtonCode::DPAD_DOWN, false, false, false, "dpad_down" };
		
				JoystickAxis axisLeftX{ JoystickAxis(JoystickAxisCode::LEFT_X, 0.0f, "left_x") };
				JoystickAxis axisLeftY{ JoystickAxis(JoystickAxisCode::LEFT_Y, 0.0f, "left_y") };
				JoystickAxis axisRightX{ JoystickAxis(JoystickAxisCode::RIGHT_X, 0.0f, "right_x") };
				JoystickAxis axisRightY{ JoystickAxis(JoystickAxisCode::RIGHT_Y, 0.0f, "right_y") };
				JoystickAxis axisLeftTrigger{ JoystickAxis(JoystickAxisCode::LEFT_TRIGGER, 0.0f, "left_trigger") };
				JoystickAxis axisRightTrigger{ JoystickAxis(JoystickAxisCode::RIGHT_TRIGGER, 0.0f, "right_trigger") };

			public:
				// Properties
				std::string name{ "unknown" };

				// Properties | callbacks
				std::function<void(bool)> onConnection;
				std::function<void(JoystickButtonCode, JoystickButtonAction)> onGamepadButton;
		
				// Constructor / Destructor
				Joystick() = default;
				Joystick(JoystickCode gamepadCode);
				Joystick(const Joystick& other) = delete;
				Joystick(Joystick&& other) noexcept = delete;
				~Joystick() = default;
				
				// Operators | assignment
				Joystick& operator=(const Joystick& other) = delete;
				Joystick& operator=(Joystick&& other) noexcept = delete;

				// Getters
				JoystickCode getCode() const;
				bool getConnected() const;
				const JoystickButton& getButtonA() const;
				const JoystickButton& getButtonB() const;
				const JoystickButton& getButtonX() const;
				const JoystickButton& getButtonY() const;
				const JoystickButton& getButtonLeftBumper() const;
				const JoystickButton& getButtonRightBumper() const;
				const JoystickButton& getButtonBack() const;
				const JoystickButton& getButtonStart() const;
				const JoystickButton& getButtonGuide() const;
				const JoystickButton& getButtonLeftThumb() const;
				const JoystickButton& getButtonRightThumb() const;
				const JoystickButton& getButtonDpadUp() const;
				const JoystickButton& getButtonDpadRight() const;
				const JoystickButton& getButtonDpadDown() const;
				const JoystickButton& getButtonDpadLeft() const;
				
				const JoystickAxis& getAxisLeftX() const;
				const JoystickAxis& getAxisLeftY() const;
				const JoystickAxis& getAxisRightX() const;
				const JoystickAxis& getAxisRightY() const;
				const JoystickAxis& getAxisLeftTrigger() const;
				const JoystickAxis& getAxisRightTrigger() const;

				std::string getName() const;

				// Functions
				void feedConnected(bool connected);
				void feedEvent(JoystickButtonCode gamepadButtonCode, JoystickButtonAction action);
				void feedEvent(JoystickAxisCode gamepadAxisCode, float value);
				void reset();
				void resetTransientState();
		};
	}
}
