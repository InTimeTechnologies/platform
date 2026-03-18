#pragma once

// Dependencies | std
#include <string>
#include <array>
#include <functional>

// Dependencies | it::platform
#include "GamepadButtonCode.h"
#include "GamepadButtonAction.h"
#include "GamepadButton.h"
#include "GamepadAxis.h"
#include "GamepadCode.h"
#include "GamepadAxisCode.h"

namespace it {
	namespace platform {
		class Gamepad {
			// Friends
			friend class GamepadInput;
			friend class Platform;

			// Object
			private:
				// Properties
				GamepadCode code{ GamepadCode::COUNT };
		
				bool connected{ false };

				GamepadButton buttonA{ GamepadButtonCode::A, false, false, false, "A" };
				GamepadButton buttonB{ GamepadButtonCode::B, false, false, false, "B" };
				GamepadButton buttonX{ GamepadButtonCode::X, false, false, false, "X" };
				GamepadButton buttonY{ GamepadButtonCode::Y, false, false, false, "Y" };
		
				GamepadButton buttonLeftBumper{ GamepadButtonCode::LEFT_BUMPER, false, false, false, "left_bumper" };
				GamepadButton buttonRightBumper{ GamepadButtonCode::RIGHT_BUMPER, false, false, false, "right_bumper" };
		
				GamepadButton buttonBack{ GamepadButtonCode::BACK, false, false, false, "back" };
				GamepadButton buttonStart{ GamepadButtonCode::START, false, false, false, "start" };
				GamepadButton buttonGuide{ GamepadButtonCode::GUIDE, false, false, false, "guide" };
		
				GamepadButton buttonLeftThumb{ GamepadButtonCode::LEFT_THUMB, false, false, false, "left_thumb" };
				GamepadButton buttonRightThumb{ GamepadButtonCode::RIGHT_THUMB, false, false, false, "right_thumb" };
		
				GamepadButton buttonDpadUp{ GamepadButtonCode::DPAD_UP, false, false, false, "dpad_up" };
				GamepadButton buttonDpadRight{ GamepadButtonCode::DPAD_RIGHT, false, false, false, "dpad_right" };
				GamepadButton buttonDpadLeft{ GamepadButtonCode::DPAD_LEFT, false, false, false, "dpad_left" };
				GamepadButton buttonDpadDown{ GamepadButtonCode::DPAD_DOWN, false, false, false, "dpad_down" };
		
				GamepadAxis axisLeftX{ GamepadAxis(GamepadAxisCode::LEFT_X, 0.0f, "left_x") };
				GamepadAxis axisLeftY{ GamepadAxis(GamepadAxisCode::LEFT_Y, 0.0f, "left_y") };
				GamepadAxis axisRightX{ GamepadAxis(GamepadAxisCode::RIGHT_X, 0.0f, "right_x") };
				GamepadAxis axisRightY{ GamepadAxis(GamepadAxisCode::RIGHT_Y, 0.0f, "right_y") };
				GamepadAxis axisLeftTrigger{ GamepadAxis(GamepadAxisCode::LEFT_TRIGGER, 0.0f, "left_trigger") };
				GamepadAxis axisRightTrigger{ GamepadAxis(GamepadAxisCode::RIGHT_TRIGGER, 0.0f, "right_trigger") };

			public:
				// Properties
				std::string name{ "unknown" };

				// Properties | callbacks
				std::function<void(bool)> onConnection;
				std::function<void(GamepadButtonCode, GamepadButtonAction)> onGamepadButton;
		
				// Constructor / Destructor
				Gamepad() = default;
				Gamepad(GamepadCode gamepadCode);
				Gamepad(const Gamepad& other) = delete;
				Gamepad(Gamepad&& other) noexcept = delete;
				~Gamepad() = default;
				
				// Operators | assignment
				Gamepad& operator=(const Gamepad& other) = delete;
				Gamepad& operator=(Gamepad&& other) noexcept = delete;

				// Getters
				GamepadCode getCode() const;
				bool getConnected() const;
				const GamepadButton& getButtonA() const;
				const GamepadButton& getButtonB() const;
				const GamepadButton& getButtonX() const;
				const GamepadButton& getButtonY() const;
				const GamepadButton& getButtonLeftBumper() const;
				const GamepadButton& getButtonRightBumper() const;
				const GamepadButton& getButtonBack() const;
				const GamepadButton& getButtonStart() const;
				const GamepadButton& getButtonGuide() const;
				const GamepadButton& getButtonLeftThumb() const;
				const GamepadButton& getButtonRightThumb() const;
				const GamepadButton& getButtonDpadUp() const;
				const GamepadButton& getButtonDpadRight() const;
				const GamepadButton& getButtonDpadDown() const;
				const GamepadButton& getButtonDpadLeft() const;
				
				const GamepadAxis& getAxisLeftX() const;
				const GamepadAxis& getAxisLeftY() const;
				const GamepadAxis& getAxisRightX() const;
				const GamepadAxis& getAxisRightY() const;
				const GamepadAxis& getAxisLeftTrigger() const;
				const GamepadAxis& getAxisRightTrigger() const;

				std::string getName() const;

				// Functions
				void feedConnected(bool connected);
				void feedEvent(GamepadButtonCode gamepadButtonCode, GamepadButtonAction action);
				void feedEvent(GamepadAxisCode gamepadAxisCode, float value);
				void reset();
				void resetTransientState();
		};
	}
}
