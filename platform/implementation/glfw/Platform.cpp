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
			// Reset transient states
			#if defined(MOUSE) && defined(GLFW_MOUSE)
			mouseInput.resetTransientStates();
			#endif
			#if defined(KEYBOARD) && defined(GLFW_KEYBOARD)
			keyboardInput.resetTransientStates();
			#endif
			#if defined(JOYSTICk) && defined(GLFW_JOYSTICK)
			joystickInput.resetTransientStates();
			#endif

			glfwPollEvents(); // Window, mouse and keyboard systems updated through callbacks

			#if defined(JOYSTICk) && defined(GLFW_JOYSTICK)
			// Update joystick input
			#endif
		}
	}
}
