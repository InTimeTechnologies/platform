#include "Gamepad.h"

namespace it {
	namespace platform {
		// class Gamepad

		// Object | public

		// Constructor / Destructor
		Gamepad::Gamepad(GamepadCode gamepadCode) : code(gamepadCode) {
			// Left empty intentionally
			// Properties defined in header
		}

		// Getters
		GamepadCode Gamepad::getCode() const {
			return code;
		}
		bool Gamepad::getConnected() const {
			return connected;
		}
		const GamepadButton& Gamepad::getButtonA() const {
			return buttonA;
		}
		const GamepadButton& Gamepad::getButtonB() const {
			return buttonB;
		}
		const GamepadButton& Gamepad::getButtonX() const {
			return buttonX;
		}
		const GamepadButton& Gamepad::getButtonY() const {
			return buttonY;
		}
		const GamepadButton& Gamepad::getButtonLeftBumper() const {
			return buttonLeftBumper;
		}
		const GamepadButton& Gamepad::getButtonRightBumper() const {
			return buttonRightBumper;
		}
		const GamepadButton& Gamepad::getButtonBack() const {
			return buttonBack;
		}
		const GamepadButton& Gamepad::getButtonStart() const {
			return buttonStart;
		}
		const GamepadButton& Gamepad::getButtonGuide() const {
			return buttonGuide;
		}
		const GamepadButton& Gamepad::getButtonLeftThumb() const {
			return buttonLeftThumb;
		}
		const GamepadButton& Gamepad::getButtonRightThumb() const {
			return buttonRightThumb;
		}
		const GamepadButton& Gamepad::getButtonDpadUp() const {
			return buttonDpadUp;
		}
		const GamepadButton& Gamepad::getButtonDpadRight() const {
			return buttonDpadRight;
		}
		const GamepadButton& Gamepad::getButtonDpadDown() const {
			return buttonDpadDown;
		}
		const GamepadButton& Gamepad::getButtonDpadLeft() const {
			return buttonDpadLeft;
		}
		
		const GamepadAxis& Gamepad::getAxisLeftX() const {
			return axisLeftX;
		}
		const GamepadAxis& Gamepad::getAxisLeftY() const {
			return axisLeftY;
		}
		const GamepadAxis& Gamepad::getAxisRightX() const {
			return axisRightX;
		}
		const GamepadAxis& Gamepad::getAxisRightY() const {
			return axisRightY;
		}
		const GamepadAxis& Gamepad::getAxisLeftTrigger() const {
			return axisLeftTrigger;
		}
		const GamepadAxis& Gamepad::getAxisRightTrigger() const {
			return axisRightTrigger;
		}

		std::string Gamepad::getName() const {
			return name;
		}


		// Functions
		void Gamepad::feedConnected(bool connected) {
			this->connected = connected;
		}
		void Gamepad::feedEvent(GamepadButtonCode buttonCode, GamepadButtonAction action) {
			switch (buttonCode) {
				case GamepadButtonCode::A:
					buttonA.feedAction(action);
					break;
				case GamepadButtonCode::B:
					buttonB.feedAction(action);
					break;
				case GamepadButtonCode::X:
					buttonX.feedAction(action);
					break;
				case GamepadButtonCode::Y:
					buttonY.feedAction(action);
					break;
				case GamepadButtonCode::LEFT_BUMPER:
					buttonLeftBumper.feedAction(action);
					break;
				case GamepadButtonCode::RIGHT_BUMPER:
					buttonRightBumper.feedAction(action);
					break;
				case GamepadButtonCode::BACK:
					buttonBack.feedAction(action);
					break;
				case GamepadButtonCode::START:
					buttonStart.feedAction(action);
					break;
				case GamepadButtonCode::LEFT_THUMB:
					buttonLeftThumb.feedAction(action);
					break;
				case GamepadButtonCode::RIGHT_THUMB:
					buttonRightThumb.feedAction(action);
					break;
				case GamepadButtonCode::DPAD_UP:
					buttonDpadUp.feedAction(action);
					break;
				case GamepadButtonCode::DPAD_RIGHT:
					buttonDpadRight.feedAction(action);
					break;
				case GamepadButtonCode::DPAD_DOWN:
					buttonDpadDown.feedAction(action);
					break;
				case GamepadButtonCode::DPAD_LEFT:
					buttonDpadLeft.feedAction(action);
					break;
				case GamepadButtonCode::UNKNOWN:
				default:
					break;
			}

			if (static_cast<bool>(onGamepadButton))
				onGamepadButton(buttonCode, action);
		}
		void Gamepad::feedEvent(GamepadAxisCode axisCode, float value) {
			switch (axisCode) {
				case GamepadAxisCode::LEFT_X:
					axisLeftX.value = value;
					break;
				case GamepadAxisCode::LEFT_Y:
					axisLeftY.value = value;
					break;
				case GamepadAxisCode::RIGHT_X:
					axisRightX.value = value;
					break;
				case GamepadAxisCode::RIGHT_Y:
					axisRightY.value = value;
					break;
					case GamepadAxisCode::LEFT_TRIGGER:
					axisLeftTrigger.value = value;
					break;
				case GamepadAxisCode::RIGHT_TRIGGER:
					axisRightTrigger.value = value;
					break;
				default:
					break;
			}
		}
		void Gamepad::reset() {
			buttonA.reset();
			buttonB.reset();
			buttonX.reset();
			buttonY.reset();
	
			buttonLeftBumper.reset();
			buttonRightBumper.reset();
	
			buttonBack.reset();
			buttonStart.reset();
	
			buttonLeftThumb.reset();
			buttonRightThumb.reset();
	
			buttonDpadUp.reset();
			buttonDpadRight.reset();
			buttonDpadLeft.reset();
			buttonDpadDown.reset();
	
			axisLeftX.reset();
			axisLeftY.reset();
			axisRightX.reset();
			axisRightY.reset();
			axisLeftTrigger.reset();
			axisRightTrigger.reset();
		}
		void Gamepad::resetTransientState() {
			buttonA.resetTransientState();
			buttonB.resetTransientState();
			buttonX.resetTransientState();
			buttonY.resetTransientState();
	
			buttonLeftBumper.resetTransientState();
			buttonRightBumper.resetTransientState();
	
			buttonBack.resetTransientState();
			buttonStart.resetTransientState();
	
			buttonLeftThumb.resetTransientState();
			buttonRightThumb.resetTransientState();
	
			buttonDpadUp.resetTransientState();
			buttonDpadRight.resetTransientState();
			buttonDpadLeft.resetTransientState();
			buttonDpadDown.resetTransientState();
		}
	}
}
