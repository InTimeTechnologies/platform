#include "PlatformImplementation.h"

// Dependencies | std
#include <cassert>
#include <iostream>

namespace it {
    namespace platform {
		// class Implementation

		// Static | public

		#if defined(WINDOW)
        // Callbacks (window)
		void PlatformImplementation::s_windowSizeCallback(GLFWwindow* glfwWindow, int glfwWidth, int glfwHeight) {
			// Feed size to Window object
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glfwWindow));
			window->feedSize(glfwWidth, glfwHeight);

			// Register WindowSizeEvent
			WindowSizeEvent* windowSizeEvent = new WindowSizeEvent(glfwWidth, glfwHeight);
			s_singleton->windowEventList.push_back({ window, windowSizeEvent });
		}
		void PlatformImplementation::s_windowPositionCallback(GLFWwindow* glfwWindow, int glfwX, int glfwY) {
			// Feed position to Window object
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glfwWindow));
			window->feedSize(glfwX, glfwY);

			// Register WindowPositionEvent
			WindowPositionEvent* windowPositionEvent = new WindowPositionEvent(glfwX, glfwY);
			s_singleton->windowEventList.push_back({ window, windowPositionEvent });
		}
		void PlatformImplementation::s_windowCloseCallback(GLFWwindow* glfwWindow) {
			// Register WindowCloseEvent
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glfwWindow));			
			WindowCloseEvent* windowCloseEvent = new WindowCloseEvent();
			s_singleton->windowEventList.push_back({ window, windowCloseEvent });
		}
		void PlatformImplementation::s_windowFocusCallback(GLFWwindow* glfwWindow, int glfwFocused) {
			// Feed focused to Window object
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glfwWindow));
			WindowFocusEvent* windowFocusEvent = new WindowFocusEvent(glfwFocused);
			s_singleton->windowEventList.push_back({ window, windowFocusEvent });
		}
		void PlatformImplementation::s_windowIconifyCallback(GLFWwindow* glfwWindow, int glfwIconified) {
			// Register WindowIconifyEvent
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glfwWindow));
			WindowIconifyEvent* windowIconifyEvent = new WindowIconifyEvent(glfwIconified);
			s_singleton->windowEventList.push_back({ window, windowIconifyEvent });
		}
		void PlatformImplementation::s_windowRefreshCallback(GLFWwindow* glfwWindow) {
			// Register WindowRefreshEvent
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glfwWindow));
			WindowRefreshEvent* windowRefreshEvent = new WindowRefreshEvent();
			s_singleton->windowEventList.push_back({ window, windowRefreshEvent });
		}
		void PlatformImplementation::s_windowMaximizeCallback(GLFWwindow* glfwWindow, int glfwMaximized) {
			// Register WindowMaximizeEvent
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glfwWindow));			
			WindowMaximizeEvent* windowMaximizeEvent = new WindowMaximizeEvent(glfwMaximized);
			s_singleton->windowEventList.push_back({ window, windowMaximizeEvent });
		}
		void PlatformImplementation::s_windowContentScaleCallback(GLFWwindow* glfwWindow, float glfwXScale, float glfwYScale) {
			// Register WindowContentScaleEvent
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glfwWindow));
			WindowContentScaleEvent* windowContentScaleEvent = new WindowContentScaleEvent(glfwXScale, glfwYScale);
			s_singleton->windowEventList.push_back({ window, windowContentScaleEvent });
		}
		void PlatformImplementation::s_windowFrameBufferSizeCallback(GLFWwindow* glfwWindow, int glfwWidth, int glfwHeight) {
			// Register WindowFrameBufferSizeEvent
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glfwWindow));
			WindowFrameBufferSizeEvent* frameBufferSizeEvent = new WindowFrameBufferSizeEvent(glfwWidth, glfwHeight);
			s_singleton->windowEventList.push_back({ window, frameBufferSizeEvent });
		}
		void PlatformImplementation::s_windowPathDropCallback(GLFWwindow* glfwWindow, int glfwPathCount, const char* glfwPaths[]) {
			// Register WindowPathEvent
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glfwWindow));
			std::vector<std::string> paths = std::vector<std::string>(glfwPathCount, "");
			for (size_t i = 0; i < static_cast<size_t>(glfwPathCount); i++)
				paths[i] = glfwPaths[i];
			WindowPathDropEvent* windowPathDropEvent = new WindowPathDropEvent(paths);
			s_singleton->windowEventList.push_back({ window, windowPathDropEvent });
		}

		// Callbacks (mouse)
		void PlatformImplementation::s_mouseButtonCallback(GLFWwindow* glfwWindow, int glfwMouseButton, int glfwMouseButtonAction, int glfwModifiers) {
			// Convert GLFW_MOUSE_BUTTON_# enum to MouseButtonCode
			MouseButtonCode code{};
			switch (glfwMouseButton) {
				case GLFW_MOUSE_BUTTON_1: code = MouseButtonCode::BUTTON_CODE_1; break;
				case GLFW_MOUSE_BUTTON_2: code = MouseButtonCode::BUTTON_CODE_2; break;
				case GLFW_MOUSE_BUTTON_3: code = MouseButtonCode::BUTTON_CODE_3; break;
				case GLFW_MOUSE_BUTTON_4: code = MouseButtonCode::BUTTON_CODE_4; break;
				case GLFW_MOUSE_BUTTON_5: code = MouseButtonCode::BUTTON_CODE_5; break;
				case GLFW_MOUSE_BUTTON_6: code = MouseButtonCode::BUTTON_CODE_6; break;
				case GLFW_MOUSE_BUTTON_7: code = MouseButtonCode::BUTTON_CODE_7; break;
				case GLFW_MOUSE_BUTTON_8: code = MouseButtonCode::BUTTON_CODE_8; break;
				default:                  code = MouseButtonCode::UNKNOWN;       break;
			}
			
			// Convert GLFW_action enum to MOUSE_BUTTON_ACTION
			MouseButtonAction action{};
			switch (glfwMouseButtonAction) {
				case GLFW_PRESS:          action = MouseButtonAction::PRESS;     break;
				case GLFW_RELEASE:        action = MouseButtonAction::RELEASE;   break;
				default:                  action = MouseButtonAction::UNKNOWN;   break;
			}

			#if defined(KEYBOARD)
			// Forward mouse button code action to mouseInput
			s_singleton->mouseInput.feedEvent(code, action);
			#endif

			// Register MouseButtonEvent
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glfwWindow));
			MouseButtonEvent* mouseButtonEvent = new MouseButtonEvent(code, action, glfwModifiers);
			s_singleton->windowEventList.push_back({ window, mouseButtonEvent });
		}
		void PlatformImplementation::s_mousePositionCallback(GLFWwindow* glfwWindow, double glfwX, double glfwY) {
			#if defined(KEYBOARD)
			// Forward mouse position to mouseInput
			s_singleton->mouseInput.x = glfwX;
			s_singleton->mouseInput.y = glfwY;
			#endif

			// Register MousePositionEvent
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glfwWindow));
			MousePositionEvent* mousePositionEvent = new MousePositionEvent(glfwX, glfwY);
			s_singleton->windowEventList.push_back({ window, mousePositionEvent});
		}
		void PlatformImplementation::s_mouseEnteredCallback(GLFWwindow* glfwWindow, int glfwEntered) {
			// Register MouseEnterEvent
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glfwWindow));
			MouseEnterEvent* mouseEnterEvent = new MouseEnterEvent(static_cast<bool>(glfwEntered));
			s_singleton->windowEventList.push_back({ window, mouseEnterEvent });
		}
		void PlatformImplementation::s_mouseScrollCallback(GLFWwindow* glfwWindow, double glfwXScroll, double glfwYScroll) {
			#if defined(KEYBOARD)
			// Forward mouse scroll to mouseInput
			s_singleton->mouseInput.xScroll = glfwXScroll;
			s_singleton->mouseInput.yScroll = glfwYScroll;
			#endif

			// Register MouseScrollEvent
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glfwWindow));
			MouseScrollEvent* mouseScrollEvent = new MouseScrollEvent(glfwXScroll, glfwYScroll);
			s_singleton->windowEventList.push_back({ window, mouseScrollEvent });
		}

		// Callbacks (keyboard)
		void PlatformImplementation::s_keyCallback(GLFWwindow* glfwWindow, int glfwKey, int glfwScancode, int glfwAction, int glfwModifiers) {
			// Convert GLFW_KEY_character to KeyCode
			KeyCode code{};
			switch (glfwKey) {
				case GLFW_KEY_SPACE:         code = KeyCode::SPACE;           break;
				case GLFW_KEY_APOSTROPHE:    code = KeyCode::APOSTROPHE;      break;
				case GLFW_KEY_COMMA:         code = KeyCode::COMMA;           break;
				case GLFW_KEY_MINUS:         code = KeyCode::MINUS;           break;
				case GLFW_KEY_PERIOD:        code = KeyCode::PERIOD;          break;
				case GLFW_KEY_SLASH:         code = KeyCode::SLASH;           break;
				case GLFW_KEY_0:             code = KeyCode::ALPHA_0;         break;
				case GLFW_KEY_1:             code = KeyCode::ALPHA_1;         break;
				case GLFW_KEY_2:             code = KeyCode::ALPHA_2;         break;
				case GLFW_KEY_3:             code = KeyCode::ALPHA_3;         break;
				case GLFW_KEY_4:             code = KeyCode::ALPHA_4;         break;
				case GLFW_KEY_5:             code = KeyCode::ALPHA_5;         break;
				case GLFW_KEY_6:             code = KeyCode::ALPHA_6;         break;
				case GLFW_KEY_7:             code = KeyCode::ALPHA_7;         break;
				case GLFW_KEY_8:             code = KeyCode::ALPHA_8;         break;
				case GLFW_KEY_9:             code = KeyCode::ALPHA_9;         break;
				case GLFW_KEY_SEMICOLON:     code = KeyCode::SEMICOLON;       break;
				case GLFW_KEY_EQUAL:         code = KeyCode::EQUAL;           break;
				case GLFW_KEY_A:             code = KeyCode::A;               break;
				case GLFW_KEY_B:             code = KeyCode::B;               break;
				case GLFW_KEY_C:             code = KeyCode::C;               break;
				case GLFW_KEY_D:             code = KeyCode::D;               break;
				case GLFW_KEY_E:             code = KeyCode::E;               break;
				case GLFW_KEY_F:             code = KeyCode::F;               break;
				case GLFW_KEY_G:             code = KeyCode::G;               break;
				case GLFW_KEY_H:             code = KeyCode::H;               break;
				case GLFW_KEY_I:             code = KeyCode::I;               break;
				case GLFW_KEY_J:             code = KeyCode::J;               break;
				case GLFW_KEY_K:             code = KeyCode::K;               break;
				case GLFW_KEY_L:             code = KeyCode::L;               break;
				case GLFW_KEY_M:             code = KeyCode::M;               break;
				case GLFW_KEY_N:             code = KeyCode::N;               break;
				case GLFW_KEY_O:             code = KeyCode::O;               break;
				case GLFW_KEY_P:             code = KeyCode::P;               break;
				case GLFW_KEY_Q:             code = KeyCode::Q;               break;
				case GLFW_KEY_R:             code = KeyCode::R;               break;
				case GLFW_KEY_S:             code = KeyCode::S;               break;
				case GLFW_KEY_T:             code = KeyCode::T;               break;
				case GLFW_KEY_U:             code = KeyCode::U;               break;
				case GLFW_KEY_V:             code = KeyCode::V;               break;
				case GLFW_KEY_W:             code = KeyCode::W;               break;
				case GLFW_KEY_X:             code = KeyCode::X;               break;
				case GLFW_KEY_Y:             code = KeyCode::Y;               break;
				case GLFW_KEY_Z:             code = KeyCode::Z;               break;
				case GLFW_KEY_LEFT_BRACKET:  code = KeyCode::BRACKET_LEFT;    break;
				case GLFW_KEY_BACKSLASH:     code = KeyCode::BACKSLASH;       break;
				case GLFW_KEY_RIGHT_BRACKET: code = KeyCode::BRACKET_RIGHT;   break;
				case GLFW_KEY_GRAVE_ACCENT:  code = KeyCode::GRAVE_ACCENT;    break;
				case GLFW_KEY_WORLD_1:       code = KeyCode::WORLD_1;         break;
				case GLFW_KEY_WORLD_2:       code = KeyCode::WORLD_2;         break;
				case GLFW_KEY_ESCAPE:        code = KeyCode::ESCAPE;          break;
				case GLFW_KEY_ENTER:         code = KeyCode::ENTER;           break;
				case GLFW_KEY_TAB:           code = KeyCode::TAB;             break;
				case GLFW_KEY_BACKSPACE:     code = KeyCode::BACKSPACE;       break;
				case GLFW_KEY_INSERT:        code = KeyCode::INSERT;          break;
				case GLFW_KEY_DELETE:        code = KeyCode::DELETE;          break;
				case GLFW_KEY_RIGHT:         code = KeyCode::ARROW_RIGHT;     break;
				case GLFW_KEY_LEFT:          code = KeyCode::ARROW_LEFT;      break;
				case GLFW_KEY_DOWN:          code = KeyCode::ARROW_DOWN;      break;
				case GLFW_KEY_UP:            code = KeyCode::ARROW_UP;        break;
				case GLFW_KEY_PAGE_UP:       code = KeyCode::PAGE_UP;         break;
				case GLFW_KEY_PAGE_DOWN:     code = KeyCode::PAGE_DOWN;       break;
				case GLFW_KEY_HOME:          code = KeyCode::HOME;            break;
				case GLFW_KEY_END:           code = KeyCode::END;             break;
				case GLFW_KEY_CAPS_LOCK:     code = KeyCode::CAPS_LOCK;       break;
				case GLFW_KEY_SCROLL_LOCK:   code = KeyCode::SCROLL_LOCK;     break;
				case GLFW_KEY_NUM_LOCK:      code = KeyCode::NUM_LOCK;        break;
				case GLFW_KEY_PRINT_SCREEN:  code = KeyCode::PRINT_SCREEN;    break;
				case GLFW_KEY_PAUSE:         code = KeyCode::PAUSE;           break;
				case GLFW_KEY_F1:            code = KeyCode::F1;              break;
				case GLFW_KEY_F2:            code = KeyCode::F2;              break;
				case GLFW_KEY_F3:            code = KeyCode::F3;              break;
				case GLFW_KEY_F4:            code = KeyCode::F4;              break;
				case GLFW_KEY_F5:            code = KeyCode::F5;              break;
				case GLFW_KEY_F6:            code = KeyCode::F6;              break;
				case GLFW_KEY_F7:            code = KeyCode::F7;              break;
				case GLFW_KEY_F8:            code = KeyCode::F8;              break;
				case GLFW_KEY_F9:            code = KeyCode::F9;              break;
				case GLFW_KEY_F10:           code = KeyCode::F10;             break;
				case GLFW_KEY_F11:           code = KeyCode::F11;             break;
				case GLFW_KEY_F12:           code = KeyCode::F12;             break;
				case GLFW_KEY_F13:           code = KeyCode::F13;             break;
				case GLFW_KEY_F14:           code = KeyCode::F14;             break;
				case GLFW_KEY_F15:           code = KeyCode::F15;             break;
				case GLFW_KEY_F16:           code = KeyCode::F16;             break;
				case GLFW_KEY_F17:           code = KeyCode::F17;             break;
				case GLFW_KEY_F18:           code = KeyCode::F18;             break;
				case GLFW_KEY_F19:           code = KeyCode::F19;             break;
				case GLFW_KEY_F20:           code = KeyCode::F20;             break;
				case GLFW_KEY_F21:           code = KeyCode::F21;             break;
				case GLFW_KEY_F22:           code = KeyCode::F22;             break;
				case GLFW_KEY_F23:           code = KeyCode::F23;             break;
				case GLFW_KEY_F24:           code = KeyCode::F24;             break;
				case GLFW_KEY_F25:           code = KeyCode::F25;             break;
				case GLFW_KEY_KP_0:          code = KeyCode::NUMPAD_0;        break;
				case GLFW_KEY_KP_1:          code = KeyCode::NUMPAD_1;        break;
				case GLFW_KEY_KP_2:          code = KeyCode::NUMPAD_2;        break;
				case GLFW_KEY_KP_3:          code = KeyCode::NUMPAD_3;        break;
				case GLFW_KEY_KP_4:          code = KeyCode::NUMPAD_4;        break;
				case GLFW_KEY_KP_5:          code = KeyCode::NUMPAD_5;        break;
				case GLFW_KEY_KP_6:          code = KeyCode::NUMPAD_6;        break;
				case GLFW_KEY_KP_7:          code = KeyCode::NUMPAD_7;        break;
				case GLFW_KEY_KP_8:          code = KeyCode::NUMPAD_8;        break;
				case GLFW_KEY_KP_9:          code = KeyCode::NUMPAD_9;        break;
				case GLFW_KEY_KP_DECIMAL:    code = KeyCode::NUMPAD_DECIMAL;  break;
				case GLFW_KEY_KP_DIVIDE:     code = KeyCode::NUMPAD_DIVIDE;   break;
				case GLFW_KEY_KP_MULTIPLY:   code = KeyCode::NUMPAD_MULTIPLY; break;
				case GLFW_KEY_KP_SUBTRACT:   code = KeyCode::NUMPAD_SUBTRACT; break;
				case GLFW_KEY_KP_ADD:        code = KeyCode::NUMPAD_ADD;      break;
				case GLFW_KEY_KP_ENTER:      code = KeyCode::NUMPAD_ENTER;    break;
				case GLFW_KEY_KP_EQUAL:      code = KeyCode::NUMPAD_EQUAL;    break;
				case GLFW_KEY_LEFT_SHIFT:    code = KeyCode::LEFT_SHIFT;      break;
				case GLFW_KEY_LEFT_CONTROL:  code = KeyCode::LEFT_CONTROL;    break;
				case GLFW_KEY_LEFT_ALT:      code = KeyCode::LEFT_ALT;        break;
				case GLFW_KEY_LEFT_SUPER:    code = KeyCode::LEFT_SUPER;      break;
				case GLFW_KEY_RIGHT_SHIFT:   code = KeyCode::RIGHT_SHIFT;     break;
				case GLFW_KEY_RIGHT_CONTROL: code = KeyCode::RIGHT_CONTROL;   break;
				case GLFW_KEY_RIGHT_ALT:     code = KeyCode::RIGHT_ALT;       break;
				case GLFW_KEY_RIGHT_SUPER:   code = KeyCode::RIGHT_SUPER;     break;
				case GLFW_KEY_MENU:          code = KeyCode::MENU;            break;
				default:                     code = KeyCode::UNKNOWN;         break;
			}
			
			// Convert GLFW_action to KeyAction
			KeyAction action{};
			switch (glfwAction) {
				case GLFW_PRESS:   action = KeyAction::PRESS;   break;
				case GLFW_REPEAT:  action = KeyAction::REPEAT;  break;
				case GLFW_RELEASE: action = KeyAction::RELEASE; break;
				default:           action = KeyAction::UNKNOWN; break;
			}

			#if defined(KEYBOARD)
			// Forward KeyCode and KeyAction to KeboardInput
			s_singleton->keyboardInput.feedEvent(code, action);
			#endif

			// Register KeyEvent
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glfwWindow));
			KeyEvent* keyEvent = new KeyEvent(code, glfwScancode, action, glfwModifiers);
			s_singleton->windowEventList.push_back({ window, keyEvent });
		}
		void PlatformImplementation::s_keyCharCallback(GLFWwindow* glfwWindow, unsigned int glfwCodePoint) {
			// Register KeyCharEvent
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glfwWindow));
			KeyCharEvent* charEvent = new KeyCharEvent(glfwCodePoint);
			s_singleton->windowEventList.push_back({ window, charEvent });
		}
		void PlatformImplementation::s_keyCharWithModifiersCallback(GLFWwindow* glfwWindow, unsigned int glfwCodePoint, int glfwModifiers) {
			// Register KeyCharWithModifiersEvent
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glfwWindow));
			KeyCharWithModifiersEvent* charWithModifiersEvent = new KeyCharWithModifiersEvent(glfwCodePoint, glfwModifiers);
			s_singleton->windowEventList.push_back({ window, charWithModifiersEvent });
		}
		
		// Callbacks (monitor)
		void PlatformImplementation::s_monitorConnectionCallback(GLFWmonitor* glfwMonitor, int glfwConnected) {
			Monitor* monitor = nullptr;

			if (glfwConnected == GLFW_CONNECTED) {
				// Create Monitor object
				monitor = &s_singleton->monitorList.emplace_back();
				monitor->backendHandle = glfwMonitor;
				const char* monitorName = glfwGetMonitorName(glfwMonitor);
				monitor->name = monitorName == nullptr ? "" : monitorName;
				const GLFWvidmode* glfwVideoMode = glfwGetVideoMode(glfwMonitor);
				monitor->width = glfwVideoMode == nullptr ? 0 : glfwVideoMode->width;
				monitor->height = glfwVideoMode == nullptr ? 0 : glfwVideoMode->height;

				// Register MonitorConnectionEvent
				MonitorConnectionEvent monitorConnectionEvent = MonitorConnectionEvent(static_cast<bool>(glfwConnected));
				s_singleton->monitorConnectionEventList.emplace_back(&monitor, monitorConnectionEvent);
			}
			else if (glfwConnected == GLFW_DISCONNECTED) {
				// Update list of connected monitors
				s_singleton->updateMonitorList();

				// Reposition windows in disconnected monitor to primary monitor
				for (Window& window : s_singleton->windowList) {
					GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(window.backendHandle);
					GLFWmonitor* glfwPreviousWindowMonitor = glfwGetWindowMonitor(glfwWindow);

					// If window was in disconnected monitor
					if (glfwPreviousWindowMonitor != glfwMonitor) {
						// Fallback to primaryMonitor monitor
						GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
						monitor = reinterpret_cast<Monitor*>(primaryMonitor);
						
						// Validate previous size with primary monitor's size
						int newWindowWidth = window.width;
						int newWindowHeight = window.height;
						if (window.width > monitor->width)
							newWindowWidth = monitor->width;
						if (window.height > monitor->height)
							newWindowHeight = monitor->height;

						// Move the window to the primary monitor
						glfwSetWindowMonitor(glfwWindow, nullptr, 50, 50, newWindowWidth, newWindowHeight, 0);
						window.width = newWindowWidth;
						window.height = newWindowHeight;
					}
				}
			}

			// Register MonitorConnectionEvent callback
			MonitorConnectionEvent monitorConnectionEvent = MonitorConnectionEvent(static_cast<bool>(glfwConnected));
			s_singleton->monitorConnectionEventList.push_back({ *monitor, monitorConnectionEvent });
		}
		#endif
		
		#if defined(JOYSTICK)
		// Callbacks (joystick)
		void PlatformImplementation::s_joystickConnectionCallback(int glfwJoystickID, int glfwConnected) {
			// Register JoystickEConnectionEvent
			JoystickCode code = static_cast<JoystickCode>(glfwJoystickID);
			s_singleton->joystickConnectionEventList.push_back(JoystickConnectionEvent{ code, static_cast<bool>(glfwConnected) });
		}
		#endif

		// Callbacks (error)
		void PlatformImplementation::s_errorCallback(int glfwErrorCode, const char* glfwDescription) {
			// Register PlatformBackendErrorEvent
			if (glfwErrorCode != GLFW_NO_ERROR) {
				s_singleton->platformBackendErrorList.push_back({ glfwErrorCode, glfwDescription });
				while (s_singleton->platformBackendErrorList.size() > s_singleton->platformBackendErrorLimit)
					s_singleton->platformBackendErrorList.pop_front();
			}
		}

		// Callbacks (error)

		// Object | public

		// Constructor / Destructor
		PlatformImplementation::PlatformImplementation() : Platform() {

		}
		PlatformImplementation::~PlatformImplementation() {
			deinit();
		}

		// Functions (Platform)
		bool PlatformImplementation::init() {
			isInit = static_cast<bool>(glfwInit());
			assert(isInit && "Failed to init GLFW");

			#if defined(WINDOW)
			// Get all the monitors available and track them through monitorList
			updateMonitorList();
			#endif

			#if defined(KEYBOARD)
			// KeyboardInput: set keyModifier parser so it can map GLFW's modifiers to Platform's modifiers.
			keyboardInput.keyModifierParser.shift = GLFW_MOD_SHIFT;
			keyboardInput.keyModifierParser.control = GLFW_MOD_CONTROL;
			keyboardInput.keyModifierParser.alt = GLFW_MOD_ALT;
			keyboardInput.keyModifierParser.super = GLFW_MOD_SUPER;
			keyboardInput.keyModifierParser.capsLock = GLFW_MOD_CAPS_LOCK;
			keyboardInput.keyModifierParser.numLock = GLFW_MOD_NUM_LOCK;
			#endif

			#if defined(JOYSTICK)
			// Callback (joystick): set joystick connection callback
			glfwSetJoystickCallback(s_joystickConnectionCallback);
			for (Joystick& joystick : joystickInput.joysticks) {
				int joystickCode = static_cast<int>(joystick.code);
				joystick.connected = glfwJoystickPresent(joystickCode) == GLFW_TRUE;
				if (joystick.connected) {
					bool isGamepad = glfwJoystickIsGamepad(joystickCode) == GLFW_TRUE;
					joystick.name = isGamepad ? glfwGetGamepadName(joystickCode) : glfwGetJoystickName(joystickCode);
				}
			}
			#endif

			// Callback (monitor): set monitor connection callback
			glfwSetMonitorCallback(s_monitorConnectionCallback);

			// Callback (error): set GLFW error callback
			glfwSetErrorCallback(s_errorCallback);

			return isInit;
		}
		void PlatformImplementation::deinit() {
			#if defined(WINDOW)
			windowList.clear();
			#endif
			glfwTerminate();
			isInit = false;
		}
		void PlatformImplementation::update() {
			// Reset transient state for each system
			#if defined(WINDOW)
			clearWindowEvents();
			#endif
			#if defined(MOUSE)
			mouseInput.resetTransientStates();
			#endif
			#if defined(KEYBOARD)
			keyboardInput.resetTransientStates();
			#endif
			#if defined(JOYSTICK)
			joystickInput.resetTransientStates();
			#endif

			// Update GLFW
			glfwPollEvents();

			#if defined(JOYSTICK)
			// Update joystick connection
			for (const JoystickConnectionEvent& joystickConnectionEvent : joystickConnectionEventList) {
				Joystick& joystick = joystickInput.joysticks[static_cast<size_t>(joystickConnectionEvent.code)];
				joystick.feedConnected(joystickConnectionEvent.connected);
			}
			joystickConnectionEventList.clear();

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
				for (size_t i = 0; i < joystick.buttons.size() && i < static_cast<size_t>(buttonCount); i++)
					joystick.buttons[i].feedAction(buttons[i] == GLFW_PRESS ? JoystickButtonAction::PRESSED : JoystickButtonAction::RELEASED);
					
				// Joystick axis value forwarding
				int axisCount = 0;
				const float* axes = glfwGetJoystickAxes(static_cast<int>(joystick.code), &axisCount);
				for (size_t i = 0; i < joystick.axes.size() && i < static_cast<size_t>(axisCount); i++)
					joystick.axes[i].value = axes[i];
			}
			#endif
		}

		#if defined(WINDOW)
		Window& PlatformImplementation::createWindow() {
			Window& window = windowList.emplace_back();
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(window.backendHandle);

			// Set callbacks (window)
			glfwSetWindowSizeCallback(glfwWindow, s_windowSizeCallback);
			glfwSetWindowPosCallback(glfwWindow, s_windowPositionCallback);
			glfwSetWindowCloseCallback(glfwWindow, s_windowCloseCallback);
			glfwSetWindowFocusCallback(glfwWindow, s_windowFocusCallback);
			glfwSetWindowIconifyCallback(glfwWindow, s_windowIconifyCallback);
			glfwSetWindowRefreshCallback(glfwWindow, s_windowRefreshCallback);
			glfwSetWindowMaximizeCallback(glfwWindow, s_windowMaximizeCallback);
			glfwSetWindowContentScaleCallback(glfwWindow, s_windowContentScaleCallback);
			glfwSetFramebufferSizeCallback(glfwWindow, s_windowFrameBufferSizeCallback);
			glfwSetDropCallback(glfwWindow, s_windowPathDropCallback);

			// Set callbacks (mouse)
			glfwSetMouseButtonCallback(glfwWindow, s_mouseButtonCallback);
			glfwSetCursorPosCallback(glfwWindow, s_mousePositionCallback);
			glfwSetCursorEnterCallback(glfwWindow, s_mouseEnteredCallback);
			glfwSetScrollCallback(glfwWindow, s_mouseScrollCallback);

			// Set callbacks (keyboard)
			glfwSetKeyCallback(glfwWindow, s_keyCallback);
			glfwSetCharCallback(glfwWindow, s_keyCharCallback);
			glfwSetCharModsCallback(glfwWindow, s_keyCharWithModifiersCallback);

			return window;
		}
		void PlatformImplementation::destroyWindow(Window& window) {
			std::list<Window>::iterator node = windowList.begin();
			while (node != windowList.end())
				if (*node == window) {
					windowList.erase(node);
					break;
				}
		}
		void PlatformImplementation::updateMonitorList() {
			monitorList.clear();

			int count;
			GLFWmonitor** glfwMonitors = glfwGetMonitors(&count);
			for (int i = 0; i < count; i++) {
				Monitor& monitor = monitorList.emplace_back();
				GLFWmonitor* glfwMonitor = glfwMonitors[i];
				monitor.backendHandle = glfwMonitor;
				const char* monitorName = glfwGetMonitorName(glfwMonitor);
				monitor.name = monitorName == nullptr ? "" : monitorName;
				const GLFWvidmode* glfwVideoMode = glfwGetVideoMode(glfwMonitor);
				monitor.width = glfwVideoMode == nullptr ? 0 : glfwVideoMode->width;
				monitor.height = glfwVideoMode == nullptr ? 0 : glfwVideoMode->height;
				
				glfwSetMonitorUserPointer(glfwMonitors[i], &monitor);
			}
		}
		#endif
    }
}
