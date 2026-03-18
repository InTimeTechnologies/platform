#pragma once

// Dependencies | std
#include <string>
#include <array>
#include <functional>

// Dependencies | it::platform
#include "JoystickButtonCode.h"
#include "JoystickButtonAction.h"
#include "JoystickButton.h"
#include "JoystickAxis.h"
#include "JoystickCode.h"
#include "JoystickAxisCode.h"

namespace it {
	namespace platform {
		struct Joystick {
			// Properties
			JoystickCode code{ JoystickCode::COUNT };
	
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

			// Properties | callbacks
			std::function<void(bool)> onConnectionChange;
			std::function<void(JoystickButtonCode, JoystickButtonAction)> onJoystickButton;
	
			// Functions
			void feedConnected(bool connected);
			void feedEvent(JoystickButtonCode joystickButtonCode, JoystickButtonAction action);
			void feedEvent(JoystickAxisCode joystickAxisCode, float value);
			void reset();
			void resetTransientState();
		};
	}
}
