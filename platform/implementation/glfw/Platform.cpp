#include <Platform.h>

// Dependencies | std
#include <cassert>

// Dependencies | glfw
#include <GLFW/glfw3.h>

namespace it {
	namespace platform {
		// class Platform

		// Static | private

		// Properties
		Platform* Platform::s_singleton{ nullptr };

		// Static | public

		// Getters
		Platform* Platform::s_getSingleton() {
			return s_singleton;
		}
		
		// Object | public
		
		// Constructor / Destructor
		Platform::Platform() {
			assert(s_singleton == nullptr && "s_singleton != nullptr");
			s_singleton = this;
		}
		Platform::~Platform() {
			#if defined(WINDOW)
			windowManager.windowList.clear();
			#endif

			deinit();
			s_singleton = nullptr;
		}
	
		// Getters
		bool Platform::getIsInit() const {
			return isInit;
		}
	
		// Functions
		bool Platform::init() {
			isInit = static_cast<bool>(glfwInit());
			return isInit;
		}
		void Platform::deinit() {
			if (!isInit)
				glfwTerminate();
		}
		void Platform::update() {
			// Reset transient state for each system
			#if defined(WINDOW) && defined(GLFW_WINDOW)
			for (Window& window : windowManager.windowList)
				window.keyEventList.clear();
			#endif
			#if defined(MOUSE) && defined(GLFW_MOUSE)
			mouseInput.resetTransientStates();
			#endif
			#if defined(KEYBOARD) && defined(GLFW_KEYBOARD)
			keyboardInput.resetTransientStates();
			#endif
			#if defined(GAMEPAD) && defined(GLFW_GAMEPAD)
			gamepadInput.resetTransientStates();
			#endif

			glfwPollEvents(); // Window, mouse and keyboard systems updates through GLFW callbacks

			#if defined(GAMEPAD) && defined(GLFW_GAMEPAD)
			// Update GamepadInput system
			std::array<Gamepad, static_cast<size_t>(GamepadCode::COUNT)>& gamepads = gamepadInput.gamepads;

			for (Gamepad& gamepad : gamepads) {
				// Controller connectivity
				bool controllerConnected = glfwJoystickPresent(static_cast<int>(gamepad.code));
				gamepad.feedConnected(controllerConnected);
				if (!controllerConnected)
					continue;

				// Gamepad button value forwading
				GLFWgamepadstate gamepadState{};
				glfwGetGamepadState(static_cast<int>(gamepad.code), &gamepadState);

				gamepad.buttonA.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_A] == GLFW_PRESS ? GamepadButtonAction::PRESSED : GamepadButtonAction::RELEASED);
				gamepad.buttonB.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_B] == GLFW_PRESS ? GamepadButtonAction::PRESSED : GamepadButtonAction::RELEASED);
				gamepad.buttonX.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_X] == GLFW_PRESS ? GamepadButtonAction::PRESSED : GamepadButtonAction::RELEASED);
				gamepad.buttonY.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_Y] == GLFW_PRESS ? GamepadButtonAction::PRESSED : GamepadButtonAction::RELEASED);

				gamepad.buttonLeftBumper.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_LEFT_BUMPER] == GLFW_PRESS ? GamepadButtonAction::PRESSED : GamepadButtonAction::RELEASED);
				gamepad.buttonRightBumper.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_RIGHT_BUMPER] == GLFW_PRESS ? GamepadButtonAction::PRESSED : GamepadButtonAction::RELEASED);

				gamepad.buttonBack.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_BACK] == GLFW_PRESS ? GamepadButtonAction::PRESSED : GamepadButtonAction::RELEASED);
				gamepad.buttonStart.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_START] == GLFW_PRESS ? GamepadButtonAction::PRESSED : GamepadButtonAction::RELEASED);
				gamepad.buttonGuide.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_GUIDE] == GLFW_PRESS ? GamepadButtonAction::PRESSED : GamepadButtonAction::RELEASED);

				gamepad.buttonLeftThumb.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_LEFT_THUMB] == GLFW_PRESS ? GamepadButtonAction::PRESSED : GamepadButtonAction::RELEASED);
				gamepad.buttonRightThumb.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_RIGHT_THUMB] == GLFW_PRESS ? GamepadButtonAction::PRESSED : GamepadButtonAction::RELEASED);

				gamepad.buttonDpadUp.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_DPAD_UP] == GLFW_PRESS ? GamepadButtonAction::PRESSED : GamepadButtonAction::RELEASED);
				gamepad.buttonDpadRight.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_DPAD_RIGHT] == GLFW_PRESS ? GamepadButtonAction::PRESSED : GamepadButtonAction::RELEASED);
				gamepad.buttonDpadDown.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_DPAD_DOWN] == GLFW_PRESS ? GamepadButtonAction::PRESSED : GamepadButtonAction::RELEASED);
				gamepad.buttonDpadLeft.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_DPAD_LEFT] == GLFW_PRESS ? GamepadButtonAction::PRESSED : GamepadButtonAction::RELEASED);

				// Gamepad axis value forwarding
				gamepad.axisLeftX.value = gamepadState.axes[GLFW_GAMEPAD_AXIS_LEFT_X];
				gamepad.axisLeftY.value = gamepadState.axes[GLFW_GAMEPAD_AXIS_LEFT_Y];

				gamepad.axisRightX.value = gamepadState.axes[GLFW_GAMEPAD_AXIS_RIGHT_X];
				gamepad.axisRightY.value = gamepadState.axes[GLFW_GAMEPAD_AXIS_RIGHT_Y];

				gamepad.axisLeftTrigger.value = gamepadState.axes[GLFW_GAMEPAD_AXIS_LEFT_TRIGGER];
				gamepad.axisRightTrigger.value = gamepadState.axes[GLFW_GAMEPAD_AXIS_RIGHT_TRIGGER];
			}
			#endif
		}
	}
}
