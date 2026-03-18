#include <Platform.h>

// Dependencies | std
#include <cassert>
#include <iostream>

// Dependencies | glfw
#include <GLFW/glfw3.h>

namespace it {
	namespace platform {
		// Functions | callbacks
		static void s_gamepadConnectionCallback(int gamepadID, int connected) {
			Platform* platform = Platform::s_getSingleton();
			assert(platform != nullptr && "platform == nullptr");

			Joystick& gamepad = platform->gamepadInput.getGamepad(static_cast<JoystickCode>(gamepadID));
			gamepad.feedConnected(connected);

			if (glfwJoystickIsGamepad(gamepadID) == GLFW_TRUE)
				gamepad.name = glfwGetGamepadName(gamepadID);
			else
				gamepad.name = glfwGetJoystickName(gamepadID);

			if (static_cast<bool>(gamepad.onConnection))
				gamepad.onConnection(connected);
		}

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
			assert(isInit && "Failed to init GLFW");

			#if defined(GAMEPAD) && defined(GLFW_GAMEPAD)
			glfwSetJoystickCallback(s_gamepadConnectionCallback);
			for (Joystick& gamepad : gamepadInput.gamepads) {
				int gamepadCode = static_cast<int>(gamepad.code);
				gamepad.connected = glfwJoystickPresent(gamepadCode) == GLFW_TRUE;
				if (gamepad.connected) {
					bool isGamepad = glfwJoystickIsGamepad(gamepadCode) == GLFW_TRUE;
					gamepad.name = isGamepad ? glfwGetGamepadName(gamepadCode) : glfwGetJoystickName(gamepadCode);
				}
			}
			#endif

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
			// Update JoystickInput system
			std::array<Joystick, static_cast<size_t>(16)>& gamepads = gamepadInput.gamepads;

			for (Joystick& gamepad : gamepads) {
				// Controller connectivity
				bool controllerConnected = glfwJoystickPresent(static_cast<int>(gamepad.code));
				gamepad.feedConnected(controllerConnected);
				if (!controllerConnected)
					continue;

				if (glfwJoystickIsGamepad(static_cast<int>(gamepad.code))) {
					// Joystick button value forwading
					GLFWgamepadstate gamepadState{};
					glfwGetGamepadState(static_cast<int>(gamepad.code), &gamepadState);

					gamepad.buttonA.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_A] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
					gamepad.buttonB.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_B] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
					gamepad.buttonX.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_X] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
					gamepad.buttonY.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_Y] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);

					gamepad.buttonLeftBumper.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_LEFT_BUMPER] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
					gamepad.buttonRightBumper.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_RIGHT_BUMPER] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);

					gamepad.buttonBack.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_BACK] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
					gamepad.buttonStart.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_START] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
					gamepad.buttonGuide.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_GUIDE] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);

					gamepad.buttonLeftThumb.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_LEFT_THUMB] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
					gamepad.buttonRightThumb.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_RIGHT_THUMB] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);

					gamepad.buttonDpadUp.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_DPAD_UP] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
					gamepad.buttonDpadRight.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_DPAD_RIGHT] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
					gamepad.buttonDpadDown.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_DPAD_DOWN] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
					gamepad.buttonDpadLeft.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_DPAD_LEFT] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);

					// Joystick axis value forwarding
					gamepad.axisLeftX.value = gamepadState.axes[GLFW_GAMEPAD_AXIS_LEFT_X];
					gamepad.axisLeftY.value = gamepadState.axes[GLFW_GAMEPAD_AXIS_LEFT_Y];

					gamepad.axisRightX.value = gamepadState.axes[GLFW_GAMEPAD_AXIS_RIGHT_X];
					gamepad.axisRightY.value = gamepadState.axes[GLFW_GAMEPAD_AXIS_RIGHT_Y];

					gamepad.axisLeftTrigger.value = gamepadState.axes[GLFW_GAMEPAD_AXIS_LEFT_TRIGGER];
					gamepad.axisRightTrigger.value = gamepadState.axes[GLFW_GAMEPAD_AXIS_RIGHT_TRIGGER];
				}
				else {
					// Joystick button values forwarding
					int buttonCount = 0;
    				const unsigned char* buttons = glfwGetJoystickButtons(static_cast<int>(gamepad.code), &buttonCount);

					if (buttonCount >= GLFW_GAMEPAD_BUTTON_DPAD_LEFT) {
					// Joystick axis values forwarding
					gamepad.buttonA.feedAction(buttons[GLFW_GAMEPAD_BUTTON_A] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
					gamepad.buttonB.feedAction(buttons[GLFW_GAMEPAD_BUTTON_B] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
					gamepad.buttonX.feedAction(buttons[GLFW_GAMEPAD_BUTTON_X] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
					gamepad.buttonY.feedAction(buttons[GLFW_GAMEPAD_BUTTON_Y] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);

					gamepad.buttonLeftBumper.feedAction(buttons[GLFW_GAMEPAD_BUTTON_LEFT_BUMPER] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
					gamepad.buttonRightBumper.feedAction(buttons[GLFW_GAMEPAD_BUTTON_RIGHT_BUMPER] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);

					gamepad.buttonBack.feedAction(buttons[GLFW_GAMEPAD_BUTTON_BACK] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
					gamepad.buttonStart.feedAction(buttons[GLFW_GAMEPAD_BUTTON_START] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
					gamepad.buttonGuide.feedAction(buttons[GLFW_GAMEPAD_BUTTON_GUIDE] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);

					gamepad.buttonLeftThumb.feedAction(buttons[GLFW_GAMEPAD_BUTTON_LEFT_THUMB] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
					gamepad.buttonRightThumb.feedAction(buttons[GLFW_GAMEPAD_BUTTON_RIGHT_THUMB] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);

					gamepad.buttonDpadUp.feedAction(buttons[GLFW_GAMEPAD_BUTTON_DPAD_UP] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
					gamepad.buttonDpadRight.feedAction(buttons[GLFW_GAMEPAD_BUTTON_DPAD_RIGHT] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
					gamepad.buttonDpadDown.feedAction(buttons[GLFW_GAMEPAD_BUTTON_DPAD_DOWN] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
					gamepad.buttonDpadLeft.feedAction(buttons[GLFW_GAMEPAD_BUTTON_DPAD_LEFT] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
					}

					// Joystick axis forwarding
					int axisCount = 0;
    				const float* axes = glfwGetJoystickAxes(static_cast<int>(gamepad.code), &axisCount);
	
					if (axisCount >= GLFW_GAMEPAD_AXIS_RIGHT_TRIGGER) {
					gamepad.axisLeftX.value = axes[GLFW_GAMEPAD_AXIS_LEFT_X];
					gamepad.axisLeftY.value = axes[GLFW_GAMEPAD_AXIS_LEFT_Y];

					gamepad.axisRightX.value = axes[GLFW_GAMEPAD_AXIS_RIGHT_X];
					gamepad.axisRightY.value = axes[GLFW_GAMEPAD_AXIS_RIGHT_Y];

					gamepad.axisLeftTrigger.value = axes[GLFW_GAMEPAD_AXIS_LEFT_TRIGGER];
					gamepad.axisRightTrigger.value = axes[GLFW_GAMEPAD_AXIS_RIGHT_TRIGGER];
					}
				}
			}
			#endif
		}
	}
}
