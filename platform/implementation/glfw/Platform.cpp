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
			#if defined(JOYSTICK) && defined(GLFW_JOYSTICK)
			joystickInput.resetTransientStates();
			#endif

			glfwPollEvents(); // Window, mouse and keyboard systems updates through GLFW callbacks

			#if defined(JOYSTICK) && defined(GLFW_JOYSTICK)
			// Update GamepadInput system
			std::array<Joystick, static_cast<size_t>(JoystickCode::COUNT)>& joysticks = joystickInput.joysticks;

			for (Joystick& joystick : joysticks) {
				// Controller connectivity
				bool controllerConnected = glfwJoystickPresent(static_cast<int>(joystick.code));
				joystick.feedConnected(controllerConnected);
				if (!controllerConnected)
					continue;

				// Gamepad button value forwading
				GLFWgamepadstate gamepadState{};
				glfwGetGamepadState(static_cast<int>(joystick.code), &gamepadState);

				joystick.buttonA.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_A] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
				joystick.buttonB.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_B] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
				joystick.buttonX.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_X] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
				joystick.buttonY.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_Y] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);

				joystick.buttonLeftBumper.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_LEFT_BUMPER] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
				joystick.buttonRightBumper.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_RIGHT_BUMPER] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);

				joystick.buttonBack.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_BACK] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
				joystick.buttonStart.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_START] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
				joystick.buttonGuide.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_GUIDE] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);

				joystick.buttonLeftThumb.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_LEFT_THUMB] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
				joystick.buttonRightThumb.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_RIGHT_THUMB] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);

				joystick.buttonDpadUp.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_DPAD_UP] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
				joystick.buttonDpadRight.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_DPAD_RIGHT] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
				joystick.buttonDpadDown.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_DPAD_DOWN] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
				joystick.buttonDpadLeft.feedAction(gamepadState.buttons[GLFW_GAMEPAD_BUTTON_DPAD_LEFT] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);

				// Gamepad axis value forwarding
				joystick.axisLeftX.value = gamepadState.axes[GLFW_GAMEPAD_AXIS_LEFT_X];
				joystick.axisLeftY.value = gamepadState.axes[GLFW_GAMEPAD_AXIS_LEFT_Y];

				joystick.axisRightX.value = gamepadState.axes[GLFW_GAMEPAD_AXIS_RIGHT_X];
				joystick.axisRightY.value = gamepadState.axes[GLFW_GAMEPAD_AXIS_RIGHT_Y];

				joystick.axisLeftTrigger.value = gamepadState.axes[GLFW_GAMEPAD_AXIS_LEFT_TRIGGER];
				joystick.axisRightTrigger.value = gamepadState.axes[GLFW_GAMEPAD_AXIS_RIGHT_TRIGGER];
			}
			#endif
		}
	}
}
