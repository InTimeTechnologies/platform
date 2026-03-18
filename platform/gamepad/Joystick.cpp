#include "Joystick.h"

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
		const JoystickButton& Joystick::getButtonA() const {
			return buttonA;
		}
		const JoystickButton& Joystick::getButtonB() const {
			return buttonB;
		}
		const JoystickButton& Joystick::getButtonX() const {
			return buttonX;
		}
		const JoystickButton& Joystick::getButtonY() const {
			return buttonY;
		}
		const JoystickButton& Joystick::getButtonLeftBumper() const {
			return buttonLeftBumper;
		}
		const JoystickButton& Joystick::getButtonRightBumper() const {
			return buttonRightBumper;
		}
		const JoystickButton& Joystick::getButtonBack() const {
			return buttonBack;
		}
		const JoystickButton& Joystick::getButtonStart() const {
			return buttonStart;
		}
		const JoystickButton& Joystick::getButtonGuide() const {
			return buttonGuide;
		}
		const JoystickButton& Joystick::getButtonLeftThumb() const {
			return buttonLeftThumb;
		}
		const JoystickButton& Joystick::getButtonRightThumb() const {
			return buttonRightThumb;
		}
		const JoystickButton& Joystick::getButtonDpadUp() const {
			return buttonDpadUp;
		}
		const JoystickButton& Joystick::getButtonDpadRight() const {
			return buttonDpadRight;
		}
		const JoystickButton& Joystick::getButtonDpadDown() const {
			return buttonDpadDown;
		}
		const JoystickButton& Joystick::getButtonDpadLeft() const {
			return buttonDpadLeft;
		}
		
		const JoystickAxis& Joystick::getAxisLeftX() const {
			return axisLeftX;
		}
		const JoystickAxis& Joystick::getAxisLeftY() const {
			return axisLeftY;
		}
		const JoystickAxis& Joystick::getAxisRightX() const {
			return axisRightX;
		}
		const JoystickAxis& Joystick::getAxisRightY() const {
			return axisRightY;
		}
		const JoystickAxis& Joystick::getAxisLeftTrigger() const {
			return axisLeftTrigger;
		}
		const JoystickAxis& Joystick::getAxisRightTrigger() const {
			return axisRightTrigger;
		}

		std::string Joystick::getName() const {
			return name;
		}


		// Functions
		void Joystick::feedConnected(bool connected) {
			this->connected = connected;
		}
		void Joystick::feedEvent(JoystickButtonCode buttonCode, JoystickButtonAction action) {
			switch (buttonCode) {
				case JoystickButtonCode::A:
					buttonA.feedAction(action);
					break;
				case JoystickButtonCode::B:
					buttonB.feedAction(action);
					break;
				case JoystickButtonCode::X:
					buttonX.feedAction(action);
					break;
				case JoystickButtonCode::Y:
					buttonY.feedAction(action);
					break;
				case JoystickButtonCode::LEFT_BUMPER:
					buttonLeftBumper.feedAction(action);
					break;
				case JoystickButtonCode::RIGHT_BUMPER:
					buttonRightBumper.feedAction(action);
					break;
				case JoystickButtonCode::BACK:
					buttonBack.feedAction(action);
					break;
				case JoystickButtonCode::START:
					buttonStart.feedAction(action);
					break;
				case JoystickButtonCode::LEFT_THUMB:
					buttonLeftThumb.feedAction(action);
					break;
				case JoystickButtonCode::RIGHT_THUMB:
					buttonRightThumb.feedAction(action);
					break;
				case JoystickButtonCode::DPAD_UP:
					buttonDpadUp.feedAction(action);
					break;
				case JoystickButtonCode::DPAD_RIGHT:
					buttonDpadRight.feedAction(action);
					break;
				case JoystickButtonCode::DPAD_DOWN:
					buttonDpadDown.feedAction(action);
					break;
				case JoystickButtonCode::DPAD_LEFT:
					buttonDpadLeft.feedAction(action);
					break;
				case JoystickButtonCode::UNKNOWN:
				default:
					break;
			}

			if (static_cast<bool>(onGamepadButton))
				onGamepadButton(buttonCode, action);
		}
		void Joystick::feedEvent(JoystickAxisCode axisCode, float value) {
			switch (axisCode) {
				case JoystickAxisCode::LEFT_X:
					axisLeftX.value = value;
					break;
				case JoystickAxisCode::LEFT_Y:
					axisLeftY.value = value;
					break;
				case JoystickAxisCode::RIGHT_X:
					axisRightX.value = value;
					break;
				case JoystickAxisCode::RIGHT_Y:
					axisRightY.value = value;
					break;
					case JoystickAxisCode::LEFT_TRIGGER:
					axisLeftTrigger.value = value;
					break;
				case JoystickAxisCode::RIGHT_TRIGGER:
					axisRightTrigger.value = value;
					break;
				default:
					break;
			}
		}
		void Joystick::reset() {
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
		void Joystick::resetTransientState() {
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
