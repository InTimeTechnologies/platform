#pragma once

// Dependencies | std
#include <list>
#include <utility>

// Dependencies | glfw
#include <GLFW/glfw3.h>

// Dependencies | it::platform
#include <Platform.h>
#include <window/Window.h>
#include <event/Event.h>

namespace it {
	namespace platform {
		class PlatformImplementation : public Platform {
			// Static
			private:
				#if defined(WINDOW)
				// Callbacks (window)
				static void s_windowSizeCallback(GLFWwindow* glfwWindow, int glfwWidth, int glfwHeight);
				static void s_windowPositionCallback(GLFWwindow* glfwWindow, int glfwX, int glfwY);
				static void s_windowCloseCallback(GLFWwindow* glfwWindow);
				static void s_windowFocusCallback(GLFWwindow* glfwWindow, int glfwFocused);
				static void s_windowIconifyCallback(GLFWwindow* glfwWindow, int glfwIconified);
				static void s_windowRefreshCallback(GLFWwindow* glfwWindow);
				static void s_windowMaximizeCallback(GLFWwindow* glfwWindow, int glfwMaximized);
				static void s_windowContentScaleCallback(GLFWwindow* glfwWindow, float glfwXScale, float glfwYScale);
				static void s_windowFrameBufferSizeCallback(GLFWwindow* glfwWindow, int glfwWidth, int glfwHeight);
				static void s_windowPathDropCallback(GLFWwindow* glfwWindow, int glfwPathCount, const char* glfwPaths[]);

				// Callbacks (mouse)
				static void s_mouseButtonCallback(GLFWwindow* glfwWindow, int glfwMouseButton, int glfwMouseButtonAction, int glfwModifiers);
				static void s_mousePositionCallback(GLFWwindow* glfwWindow, double glfwX, double glfwY);
				static void s_mouseEnteredCallback(GLFWwindow* glfwWindow, int glfwEntered);
				static void s_mouseScrollCallback(GLFWwindow* glfwWindow, double glfwXScroll, double glfwYScroll);

				// Callbacks (keyboard)
				static void s_keyCallback(GLFWwindow* glfwWindow, int glfwKey, int glfwScancode, int glfwAction, int glfwModifiers);
				static void s_keyCharCallback(GLFWwindow* glfwWindow, unsigned int glfwCodePoint);
				static void s_keyCharWithModifiersCallback(GLFWwindow* glfwWindow, unsigned int glfwCodePoint, int glfwModifiers);
				
				// Callbacks (monitor)
				static void s_monitorConnectionCallback(GLFWmonitor* glfwMonitor, int glfwEvent);
				#endif
				
				#if defined(JOYSTICK)
				// Callbacks (joystick)
				static void s_joystickConnectionCallback(int glfwJoystickID, int glfwConnected);
				#endif

				// Callbacks (error)
				static void s_errorCallback(int glfwErrorCode, const char* glfwDescription);

			// Object
			public:
				// Constructor / Destructor
				PlatformImplementation();
				PlatformImplementation(const PlatformImplementation& other) = delete;
				PlatformImplementation(PlatformImplementation&& other) noexcept = delete;
				virtual ~PlatformImplementation();

				// Operators | assignment
				PlatformImplementation& operator=(const PlatformImplementation& other) = delete;
				PlatformImplementation& operator=(PlatformImplementation&& other) = delete;

				// Functions (Platform)
				bool init() override;
				void deinit() override;
				void update() override;

				#if defined(WINDOW)
				Window& createWindow() override;
				void destroyWindow(Window& window) override;
				void updateMonitorList() override;
				#endif
		};
	}
}

