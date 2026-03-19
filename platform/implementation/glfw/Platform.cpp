#include <Platform.h>

// Dependencies | std
#include <cassert>
#include <list>
#include <utility>

// Dependencies | glfw
#include <GLFW/glfw3.h>

namespace it {
	namespace platform {
		// cpp | struct
		struct CPP_ConnectionEvent {
			JoystickCode joystickCode{ JoystickCode::UNKNOWN };
			bool connected{ false };
		};

		// cpp | variables
		static std::list<CPP_ConnectionEvent> cpp_joystickConnectionEventList{};

		// cpp | Functions | callbacks
		static void cpp_joystickConnectionCallback(int joystickID, int connected) {
			Platform* platform = Platform::s_getSingleton();
			assert(platform != nullptr && "platform == nullptr");
			
			cpp_joystickConnectionEventList.push_back({ static_cast<JoystickCode>(joystickID), connected == GLFW_TRUE});
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

			#if defined(JOYSTICK) && defined(GLFW_JOYSTICK)
			glfwSetJoystickCallback(cpp_joystickConnectionCallback);
			for (Joystick& joystick : joystickInput.joysticks) {
				int joystickCode = static_cast<int>(joystick.code);
				joystick.connected = glfwJoystickPresent(joystickCode) == GLFW_TRUE;
				if (joystick.connected) {
					bool isGamepad = glfwJoystickIsGamepad(joystickCode) == GLFW_TRUE;
					joystick.name = isGamepad ? glfwGetGamepadName(joystickCode) : glfwGetJoystickName(joystickCode);
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
			#if defined(JOYSTICK) && defined(GLFW_JOYSTICK)
			joystickInput.resetTransientStates();
			#endif

			glfwPollEvents(); // Window, mouse and keyboard systems updates through GLFW callbacks

			#if defined(JOYSTICK) && defined(GLFW_JOYSTICK)
			// Update joystick connection
			for (const CPP_ConnectionEvent& connectionEvent : cpp_joystickConnectionEventList) {
				Joystick& joystick = joystickInput.joysticks[static_cast<size_t>(connectionEvent.joystickCode)];
				joystick.feedConnected(connectionEvent.connected);
			}
			cpp_joystickConnectionEventList.clear();

			// Update JoystickInput system
			std::vector<Joystick>& joysticks = joystickInput.joysticks;

			for (Joystick& joystick : joysticks) {
				// Controller connectivity
				bool controllerConnected = glfwJoystickPresent(static_cast<int>(joystick.code));
				joystick.feedConnected(controllerConnected);
				if (!controllerConnected)
					continue;

				// Joystick button values forwarding
				int buttonCount = 0;
    			const unsigned char* buttons = glfwGetJoystickButtons(static_cast<int>(joystick.code), &buttonCount);
				for (size_t i = 0; i < joystick.buttons.size() && i < buttonCount; i++)
					joystick.buttons[i].feedAction(buttons[i] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
					
				// Joystick axis value forwarding
				int axisCount = 0;
				const float* axes = glfwGetJoystickAxes(static_cast<int>(joystick.code), &axisCount);
				for (size_t i = 0; i < joystick.axes.size() && i < axisCount; i++)
					joystick.axes[i].value = axes[i];
			}
			#endif
		}
	}
}
