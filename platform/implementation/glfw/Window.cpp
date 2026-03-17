#include <window/Window.h>

// Dependencies | std
#include <cassert>

// Dependencies | glfw
#include <GLFW/glfw3.h>

// Dependencies | it
#include <Platform.h>
#include <window/Window.h>
#include <mouse/MouseInput.h>
#include <keyboard/KeyboardInput.h>

namespace it {
	namespace platform {
		// Callbacks
		void s_windowSizeCallback(GLFWwindow* glfwWindow, int width, int height) {
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glfwWindow));
			window->feedSize(width, height);

			if (static_cast<bool>(window->onResize))
				window->onResize(width, height);
		}
		void s_windowPositionCallback(GLFWwindow* glfwWindow, int x, int y) {
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glfwWindow));
			window->feedSize(x, y);

			if (static_cast<bool>(window->onMove))
				window->onMove(x, y);
		}
		void s_windowCloseCallback(GLFWwindow* glfwWindow) {
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glfwWindow));
			
			if (static_cast<bool>(window->onClose))
				window->onClose();
		}
		void s_windowFocusCallback(GLFWwindow* glfwWindow, int focused) {
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glfwWindow));
			window->feedFocused(focused);

			if (static_cast<bool>(window->onFocus))
				window->onFocus(focused);
		}
		void s_windowIconifyCallback(GLFWwindow* glfwWindow, int iconify) {
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glfwWindow));
			
			if (static_cast<bool>(window->onIconify))
				window->onIconify(iconify);
		}
		void s_windowRefreshCallback(GLFWwindow* glfwWindow) {
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glfwWindow));
			if (static_cast<bool>(window->onRefresh))
				window->onRefresh();
		}
		void s_windowMaximizeCallback(GLFWwindow* glfwWindow, int maximized) {
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glfwWindow));
			
			if (static_cast<bool>(window->onMaximize))
				window->onMaximize(maximized);
		}
		void s_contentScaleCallback(GLFWwindow* glfwWindow, float xScale, float yScale) {
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glfwWindow));

			if (static_cast<bool>(window->onScale))
				window->onScale(xScale, yScale);
		}

		void s_keyCallback(GLFWwindow* glfwWindow, int glfwKey, int glfwScancode, int glfwAction, int glfwMods) {
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glfwWindow));
			KeyEvent keyEvent{};

			switch (glfwKey) {
				case GLFW_KEY_SPACE:         keyEvent.keyCode = KeyCode::SPACE;           break;
				case GLFW_KEY_APOSTROPHE:    keyEvent.keyCode = KeyCode::APOSTROPHE;      break;
				case GLFW_KEY_COMMA:         keyEvent.keyCode = KeyCode::COMMA;           break;
				case GLFW_KEY_MINUS:         keyEvent.keyCode = KeyCode::MINUS;           break;
				case GLFW_KEY_PERIOD:        keyEvent.keyCode = KeyCode::PERIOD;          break;
				case GLFW_KEY_SLASH:         keyEvent.keyCode = KeyCode::SLASH;           break;
				case GLFW_KEY_0:             keyEvent.keyCode = KeyCode::ALPHA_0;         break;
				case GLFW_KEY_1:             keyEvent.keyCode = KeyCode::ALPHA_1;         break;
				case GLFW_KEY_2:             keyEvent.keyCode = KeyCode::ALPHA_2;         break;
				case GLFW_KEY_3:             keyEvent.keyCode = KeyCode::ALPHA_3;         break;
				case GLFW_KEY_4:             keyEvent.keyCode = KeyCode::ALPHA_4;         break;
				case GLFW_KEY_5:             keyEvent.keyCode = KeyCode::ALPHA_5;         break;
				case GLFW_KEY_6:             keyEvent.keyCode = KeyCode::ALPHA_6;         break;
				case GLFW_KEY_7:             keyEvent.keyCode = KeyCode::ALPHA_7;         break;
				case GLFW_KEY_8:             keyEvent.keyCode = KeyCode::ALPHA_8;         break;
				case GLFW_KEY_9:             keyEvent.keyCode = KeyCode::ALPHA_9;         break;
				case GLFW_KEY_SEMICOLON:     keyEvent.keyCode = KeyCode::SEMICOLON;       break;
				case GLFW_KEY_EQUAL:         keyEvent.keyCode = KeyCode::EQUAL;           break;
				case GLFW_KEY_A:             keyEvent.keyCode = KeyCode::A;               break;
				case GLFW_KEY_B:             keyEvent.keyCode = KeyCode::B;               break;
				case GLFW_KEY_C:             keyEvent.keyCode = KeyCode::C;               break;
				case GLFW_KEY_D:             keyEvent.keyCode = KeyCode::D;               break;
				case GLFW_KEY_E:             keyEvent.keyCode = KeyCode::E;               break;
				case GLFW_KEY_F:             keyEvent.keyCode = KeyCode::F;               break;
				case GLFW_KEY_G:             keyEvent.keyCode = KeyCode::G;               break;
				case GLFW_KEY_H:             keyEvent.keyCode = KeyCode::H;               break;
				case GLFW_KEY_I:             keyEvent.keyCode = KeyCode::I;               break;
				case GLFW_KEY_J:             keyEvent.keyCode = KeyCode::J;               break;
				case GLFW_KEY_K:             keyEvent.keyCode = KeyCode::K;               break;
				case GLFW_KEY_L:             keyEvent.keyCode = KeyCode::L;               break;
				case GLFW_KEY_M:             keyEvent.keyCode = KeyCode::M;               break;
				case GLFW_KEY_N:             keyEvent.keyCode = KeyCode::N;               break;
				case GLFW_KEY_O:             keyEvent.keyCode = KeyCode::O;               break;
				case GLFW_KEY_P:             keyEvent.keyCode = KeyCode::P;               break;
				case GLFW_KEY_Q:             keyEvent.keyCode = KeyCode::Q;               break;
				case GLFW_KEY_R:             keyEvent.keyCode = KeyCode::R;               break;
				case GLFW_KEY_S:             keyEvent.keyCode = KeyCode::S;               break;
				case GLFW_KEY_T:             keyEvent.keyCode = KeyCode::T;               break;
				case GLFW_KEY_U:             keyEvent.keyCode = KeyCode::U;               break;
				case GLFW_KEY_V:             keyEvent.keyCode = KeyCode::V;               break;
				case GLFW_KEY_W:             keyEvent.keyCode = KeyCode::W;               break;
				case GLFW_KEY_X:             keyEvent.keyCode = KeyCode::X;               break;
				case GLFW_KEY_Y:             keyEvent.keyCode = KeyCode::Y;               break;
				case GLFW_KEY_Z:             keyEvent.keyCode = KeyCode::Z;               break;
				case GLFW_KEY_LEFT_BRACKET:  keyEvent.keyCode = KeyCode::BRACKET_LEFT;    break;
				case GLFW_KEY_BACKSLASH:     keyEvent.keyCode = KeyCode::BACKSLASH;       break;
				case GLFW_KEY_RIGHT_BRACKET: keyEvent.keyCode = KeyCode::BRACKET_RIGHT;   break;
				case GLFW_KEY_GRAVE_ACCENT:  keyEvent.keyCode = KeyCode::GRAVE_ACCENT;    break;
				case GLFW_KEY_WORLD_1:       keyEvent.keyCode = KeyCode::WORLD_1;         break;
				case GLFW_KEY_WORLD_2:       keyEvent.keyCode = KeyCode::WORLD_2;         break;
				case GLFW_KEY_ESCAPE:        keyEvent.keyCode = KeyCode::ESCAPE;          break;
				case GLFW_KEY_ENTER:         keyEvent.keyCode = KeyCode::ENTER;           break;
				case GLFW_KEY_TAB:           keyEvent.keyCode = KeyCode::TAB;             break;
				case GLFW_KEY_BACKSPACE:     keyEvent.keyCode = KeyCode::BACKSPACE;       break;
				case GLFW_KEY_INSERT:        keyEvent.keyCode = KeyCode::INSERT;          break;
				case GLFW_KEY_DELETE:        keyEvent.keyCode = KeyCode::DELETE;          break;
				case GLFW_KEY_RIGHT:         keyEvent.keyCode = KeyCode::ARROW_RIGHT;     break;
				case GLFW_KEY_LEFT:          keyEvent.keyCode = KeyCode::ARROW_LEFT;      break;
				case GLFW_KEY_DOWN:          keyEvent.keyCode = KeyCode::ARROW_DOWN;      break;
				case GLFW_KEY_UP:            keyEvent.keyCode = KeyCode::ARROW_UP;        break;
				case GLFW_KEY_PAGE_UP:       keyEvent.keyCode = KeyCode::PAGE_UP;         break;
				case GLFW_KEY_PAGE_DOWN:     keyEvent.keyCode = KeyCode::PAGE_DOWN;       break;
				case GLFW_KEY_HOME:          keyEvent.keyCode = KeyCode::HOME;            break;
				case GLFW_KEY_END:           keyEvent.keyCode = KeyCode::END;             break;
				case GLFW_KEY_CAPS_LOCK:     keyEvent.keyCode = KeyCode::CAPS_LOCK;       break;
				case GLFW_KEY_SCROLL_LOCK:   keyEvent.keyCode = KeyCode::SCROLL_LOCK;     break;
				case GLFW_KEY_NUM_LOCK:      keyEvent.keyCode = KeyCode::NUM_LOCK;        break;
				case GLFW_KEY_PRINT_SCREEN:  keyEvent.keyCode = KeyCode::PRINT_SCREEN;    break;
				case GLFW_KEY_PAUSE:         keyEvent.keyCode = KeyCode::PAUSE;           break;
				case GLFW_KEY_F1:            keyEvent.keyCode = KeyCode::F1;              break;
				case GLFW_KEY_F2:            keyEvent.keyCode = KeyCode::F2;              break;
				case GLFW_KEY_F3:            keyEvent.keyCode = KeyCode::F3;              break;
				case GLFW_KEY_F4:            keyEvent.keyCode = KeyCode::F4;              break;
				case GLFW_KEY_F5:            keyEvent.keyCode = KeyCode::F5;              break;
				case GLFW_KEY_F6:            keyEvent.keyCode = KeyCode::F6;              break;
				case GLFW_KEY_F7:            keyEvent.keyCode = KeyCode::F7;              break;
				case GLFW_KEY_F8:            keyEvent.keyCode = KeyCode::F8;              break;
				case GLFW_KEY_F9:            keyEvent.keyCode = KeyCode::F9;              break;
				case GLFW_KEY_F10:           keyEvent.keyCode = KeyCode::F10;             break;
				case GLFW_KEY_F11:           keyEvent.keyCode = KeyCode::F11;             break;
				case GLFW_KEY_F12:           keyEvent.keyCode = KeyCode::F12;             break;
				case GLFW_KEY_F13:           keyEvent.keyCode = KeyCode::F13;             break;
				case GLFW_KEY_F14:           keyEvent.keyCode = KeyCode::F14;             break;
				case GLFW_KEY_F15:           keyEvent.keyCode = KeyCode::F15;             break;
				case GLFW_KEY_F16:           keyEvent.keyCode = KeyCode::F16;             break;
				case GLFW_KEY_F17:           keyEvent.keyCode = KeyCode::F17;             break;
				case GLFW_KEY_F18:           keyEvent.keyCode = KeyCode::F18;             break;
				case GLFW_KEY_F19:           keyEvent.keyCode = KeyCode::F19;             break;
				case GLFW_KEY_F20:           keyEvent.keyCode = KeyCode::F20;             break;
				case GLFW_KEY_F21:           keyEvent.keyCode = KeyCode::F21;             break;
				case GLFW_KEY_F22:           keyEvent.keyCode = KeyCode::F22;             break;
				case GLFW_KEY_F23:           keyEvent.keyCode = KeyCode::F23;             break;
				case GLFW_KEY_F24:           keyEvent.keyCode = KeyCode::F24;             break;
				case GLFW_KEY_F25:           keyEvent.keyCode = KeyCode::F25;             break;
				case GLFW_KEY_KP_0:          keyEvent.keyCode = KeyCode::NUMPAD_0;        break;
				case GLFW_KEY_KP_1:          keyEvent.keyCode = KeyCode::NUMPAD_1;        break;
				case GLFW_KEY_KP_2:          keyEvent.keyCode = KeyCode::NUMPAD_2;        break;
				case GLFW_KEY_KP_3:          keyEvent.keyCode = KeyCode::NUMPAD_3;        break;
				case GLFW_KEY_KP_4:          keyEvent.keyCode = KeyCode::NUMPAD_4;        break;
				case GLFW_KEY_KP_5:          keyEvent.keyCode = KeyCode::NUMPAD_5;        break;
				case GLFW_KEY_KP_6:          keyEvent.keyCode = KeyCode::NUMPAD_6;        break;
				case GLFW_KEY_KP_7:          keyEvent.keyCode = KeyCode::NUMPAD_7;        break;
				case GLFW_KEY_KP_8:          keyEvent.keyCode = KeyCode::NUMPAD_8;        break;
				case GLFW_KEY_KP_9:          keyEvent.keyCode = KeyCode::NUMPAD_9;        break;
				case GLFW_KEY_KP_DECIMAL:    keyEvent.keyCode = KeyCode::NUMPAD_DECIMAL;  break;
				case GLFW_KEY_KP_DIVIDE:     keyEvent.keyCode = KeyCode::NUMPAD_DIVIDE;   break;
				case GLFW_KEY_KP_MULTIPLY:   keyEvent.keyCode = KeyCode::NUMPAD_MULTIPLY; break;
				case GLFW_KEY_KP_SUBTRACT:   keyEvent.keyCode = KeyCode::NUMPAD_SUBTRACT; break;
				case GLFW_KEY_KP_ADD:        keyEvent.keyCode = KeyCode::NUMPAD_ADD;      break;
				case GLFW_KEY_KP_ENTER:      keyEvent.keyCode = KeyCode::NUMPAD_ENTER;    break;
				case GLFW_KEY_KP_EQUAL:      keyEvent.keyCode = KeyCode::NUMPAD_EQUAL;    break;
				case GLFW_KEY_LEFT_SHIFT:    keyEvent.keyCode = KeyCode::LEFT_SHIFT;      break;
				case GLFW_KEY_LEFT_CONTROL:  keyEvent.keyCode = KeyCode::LEFT_CONTROL;    break;
				case GLFW_KEY_LEFT_ALT:      keyEvent.keyCode = KeyCode::LEFT_ALT;        break;
				case GLFW_KEY_LEFT_SUPER:    keyEvent.keyCode = KeyCode::LEFT_SUPER;      break;
				case GLFW_KEY_RIGHT_SHIFT:   keyEvent.keyCode = KeyCode::RIGHT_SHIFT;     break;
				case GLFW_KEY_RIGHT_CONTROL: keyEvent.keyCode = KeyCode::RIGHT_CONTROL;   break;
				case GLFW_KEY_RIGHT_ALT:     keyEvent.keyCode = KeyCode::RIGHT_ALT;       break;
				case GLFW_KEY_RIGHT_SUPER:   keyEvent.keyCode = KeyCode::RIGHT_SUPER;     break;
				case GLFW_KEY_MENU:          keyEvent.keyCode = KeyCode::MENU;            break;
				default:                     keyEvent.keyCode = KeyCode::UNKNOWN;         break;
			}

			keyEvent.scanCode = glfwScancode;

			switch (glfwAction) {
				case GLFW_PRESS:   keyEvent.action = KeyAction::PRESS;   break;
				case GLFW_REPEAT:  keyEvent.action = KeyAction::REPEAT;  break;
				case GLFW_RELEASE: keyEvent.action = KeyAction::RELEASE; break;
				default:           keyEvent.action = KeyAction::UNKNOWN; break;
			}

			keyEvent.modifier = glfwMods;
			
			window->feedKeyEvent(keyEvent);
			
			if (static_cast<bool>(window->onKeyEvent))
				window->onKeyEvent(keyEvent);
		}
		
		void s_mouseButtonCallback(GLFWwindow* glfwWindow, int glfwMouseButton, int glfwMouseButtonAction, int glfwModifiers) {
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glfwWindow));
			MouseButtonEvent mouseButtonEvent{};

			switch (glfwMouseButton) {
				case GLFW_MOUSE_BUTTON_1: mouseButtonEvent.mouseButtonCode = MouseButtonCode::BUTTON_CODE_1; break;
				case GLFW_MOUSE_BUTTON_2: mouseButtonEvent.mouseButtonCode = MouseButtonCode::BUTTON_CODE_2; break;
				case GLFW_MOUSE_BUTTON_3: mouseButtonEvent.mouseButtonCode = MouseButtonCode::BUTTON_CODE_3; break;
				case GLFW_MOUSE_BUTTON_4: mouseButtonEvent.mouseButtonCode = MouseButtonCode::BUTTON_CODE_4; break;
				case GLFW_MOUSE_BUTTON_5: mouseButtonEvent.mouseButtonCode = MouseButtonCode::BUTTON_CODE_5; break;
				case GLFW_MOUSE_BUTTON_6: mouseButtonEvent.mouseButtonCode = MouseButtonCode::BUTTON_CODE_6; break;
				case GLFW_MOUSE_BUTTON_7: mouseButtonEvent.mouseButtonCode = MouseButtonCode::BUTTON_CODE_7; break;
				case GLFW_MOUSE_BUTTON_8: mouseButtonEvent.mouseButtonCode = MouseButtonCode::BUTTON_CODE_8; break;
				default:                  mouseButtonEvent.mouseButtonCode = MouseButtonCode::UNKNOWN;       break;
			}

			switch (glfwMouseButtonAction) {
				case GLFW_PRESS:   mouseButtonEvent.action = MouseButton::Action::PRESS;   break;
				case GLFW_RELEASE: mouseButtonEvent.action = MouseButton::Action::RELEASE; break;
				default:           mouseButtonEvent.action = MouseButton::Action::UNKNOWN; break;
			}

			if (static_cast<bool>(window->onMouseButtonEvent))
				window->onMouseButtonEvent(mouseButtonEvent);
		}

		// class Window

		// Static | public

		// Properties
		std::string Window::s_defaultTitle{"GLFW Window"};
		int Window::s_defaultX{ 0 };
		int Window::s_defaultY{ 0 };
		int Window::s_defaultWidth{ 800 };
		int Window::s_defaultHeight{ 500 };
		bool Window::s_defaultVisible{ true };
		bool Window::s_defaultResizable{ true };

		// Object | public

		// Operators | equality
		bool Window::operator==(const Window& other) const {
			return this == &other;
		}

		// Getters | Window
		std::string Window::getTitle() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			return std::string(glfwGetWindowTitle(glfwWindow));
		}
		int Window::getX() const {
			return x;
		}
		int Window::getY() const {
			return y;
		}
		int Window::getWidth() const {
			return width;
		}
		int Window::getHeight() const {
			return height;
		}

		// Getters | Window (window state)
		bool Window::getFocused() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_FOCUSED));
		}
		bool Window::getIconified() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_ICONIFIED));
		}
		bool Window::getMaximized() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_ICONIFIED));
		}
		bool Window::getVisible() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_VISIBLE));
		}
		bool Window::getHovered() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_HOVERED));
		}

		// Getters (window property attributes)
		bool Window::getResizable() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_RESIZABLE));
		}
		bool Window::getDecorated() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_DECORATED));
		}
		bool Window::getFloating() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_FLOATING));
		}
		bool Window::getAutoiconify() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_AUTO_ICONIFY));
		}
		bool Window::getFocusOnShow() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_FOCUS_ON_SHOW));
		}
		bool Window::getMousePassthrough() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_MOUSE_PASSTHROUGH));
		}
		bool Window::getTransparentFrameBuffer() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_TRANSPARENT_FRAMEBUFFER));
		}

		// Getters (constext attribut::es OpenGL / OpenGL ES)
		std::string Window::getClientAPI() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			int clientApi = glfwGetWindowAttrib(glfwWindow, GLFW_CLIENT_API);
			switch (clientApi) {
				case GLFW_OPENGL_API:    return std::string("OpenGL");
				case GLFW_OPENGL_ES_API: return std::string("OpenGL ES");
				case GLFW_NO_API:        return std::string("no api");
				default:                 return std::string("unknown");
			}
		}
		std::string Window::getContextCreationAPI() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			int contextCreationApi = glfwGetWindowAttrib(glfwWindow, GLFW_CONTEXT_CREATION_API);
			switch (contextCreationApi) {
				case GLFW_NATIVE_CONTEXT_API: return std::string("native context");
				case GLFW_EGL_CONTEXT_API:    return std::string("egl");
				case GLFW_OSMESA_CONTEXT_API: return std::string("osmesa");
				default:                      return std::string ("unknown");
			}
		}
		int Window::getContextMajorVersion() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			return glfwGetWindowAttrib(glfwWindow, GLFW_CONTEXT_VERSION_MAJOR);
		}
		int Window::getContextMinorVersion() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			return glfwGetWindowAttrib(glfwWindow, GLFW_CONTEXT_VERSION_MINOR);
		}
		int Window::getContextRevision() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			return glfwGetWindowAttrib(glfwWindow, GLFW_CONTEXT_REVISION);
		}

		// Getters (key event list)
		const std::list<KeyEvent>& Window::getKeyEventList() const {
			return keyEventList;
		}

		// Setters
		void Window::setTitle(const std::string& title) {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			glfwSetWindowTitle(glfwWindow, title.c_str());
		}
		void Window::setPosition(int x, int y) {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			glfwSetWindowPos(glfwWindow, x, y);
		}
		void Window::setSize(int width, int height) {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			glfwSetWindowSize(glfwWindow, width, height);
		}

		// Setters (window state)
		void Window::setFocus() {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			glfwFocusWindow(glfwWindow);
		}
		void Window::setIconified(bool iconified) {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			if (iconified)
				glfwIconifyWindow(glfwWindow);
			else
				glfwRestoreWindow(glfwWindow);
		}
		void Window::setMaximized(bool maximized) {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			if (maximized)
				glfwMaximizeWindow(glfwWindow);
			else
				glfwRestoreWindow(glfwWindow);
		}
		void Window::setVisible(bool visible) {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			if (visible)
				glfwShowWindow(glfwWindow);
			else
				glfwHideWindow(glfwWindow);
		}

		// Setters | Window Property Attributes
		void Window::setResizable(bool resizable) {
			// Not guaranteed to work on some platforms
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			glfwSetWindowAttrib(glfwWindow, GLFW_RESIZABLE, resizable ? GLFW_TRUE : GLFW_FALSE);
		}
		void Window::setDecorated(bool decorated) {
			// Not guaranteed to work on some platforms
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			glfwSetWindowAttrib(glfwWindow, GLFW_DECORATED, decorated ? GLFW_TRUE : GLFW_FALSE);
		}
		void Window::setFloating(bool floating) {
			// Always-on-top
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			glfwSetWindowAttrib(glfwWindow, GLFW_FLOATING, floating ? GLFW_TRUE : GLFW_FALSE);
		}
		void Window::setAutoiconify(bool autoiconify) {
			// Only relevant for fullscreen windows
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			glfwSetWindowAttrib(glfwWindow, GLFW_AUTO_ICONIFY, autoiconify ? GLFW_TRUE : GLFW_FALSE);
		}
		void Window::setFocusOnShow(bool focusOnShow) {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			glfwSetWindowAttrib(glfwWindow, GLFW_FOCUS_ON_SHOW, focusOnShow ? GLFW_TRUE : GLFW_FALSE);
		}
		void Window::setMousePassthrough(bool mousePassthrough) {
			// Mouse clicks go through window
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			glfwSetWindowAttrib(glfwWindow, GLFW_MOUSE_PASSTHROUGH, mousePassthrough ? GLFW_TRUE : GLFW_FALSE);
		}
		void Window::setTransparentFrameBuffer(bool transparentFrameBuffer) {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			glfwSetWindowAttrib(glfwWindow, GLFW_TRANSPARENT_FRAMEBUFFER, transparentFrameBuffer ? GLFW_TRUE : GLFW_FALSE);
		}

		// Functions | Window
		bool Window::create() {
			// Create window
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			glfwWindow = glfwCreateWindow(Window::s_defaultWidth, Window::s_defaultHeight, Window::s_defaultTitle.c_str(), nullptr, nullptr);
			if (!glfwWindow)
				return false;
			backendHandle = glfwWindow;

			// Set window attributes
			glfwSetWindowPos(glfwWindow, Window::s_defaultX, Window::s_defaultY);
			glfwSetWindowAttrib(glfwWindow, GLFW_RESIZABLE, static_cast<int>(Window::s_defaultResizable));
			glfwSetWindowUserPointer(glfwWindow, this);

			// Feed all OS values
			title = Window::s_defaultTitle;
			x = Window::s_defaultX;
			y = Window::s_defaultY;
			width = Window::s_defaultWidth;
			height = Window::s_defaultHeight;
			visible = Window::s_defaultVisible;
			resizable = Window::s_defaultResizable;

			// Set callbacks
			glfwSetWindowSizeCallback(glfwWindow, s_windowSizeCallback);
			glfwSetWindowPosCallback(glfwWindow, s_windowPositionCallback);
			glfwSetWindowCloseCallback(glfwWindow, s_windowCloseCallback);
			glfwSetWindowFocusCallback(glfwWindow, s_windowFocusCallback);
			glfwSetWindowIconifyCallback(glfwWindow, s_windowIconifyCallback);
			glfwSetWindowRefreshCallback(glfwWindow, s_windowRefreshCallback);
			glfwSetWindowMaximizeCallback(glfwWindow, s_windowMaximizeCallback);
			glfwSetWindowContentScaleCallback(glfwWindow, s_contentScaleCallback);

			glfwSetKeyCallback(glfwWindow, s_keyCallback);

			glfwSetMouseButtonCallback(glfwWindow, s_mouseButtonCallback);

			// Success
			return true;
		}
		void Window::close() {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			glfwDestroyWindow(glfwWindow);
			glfwWindow = nullptr;
		}
		bool Window::isCreated() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			return glfwWindow != nullptr;
		}
		void Window::makeContextCurrent() {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			glfwMakeContextCurrent(glfwWindow);
		}
		void Window::swapBuffers() {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			glfwSwapBuffers(glfwWindow);
		}

		// Functions | Feeders
		void Window::feedTitle(const std::string& title) {
			this->title = title;
		}
		void Window::feedPosition(int x, int y) {
			this->x = x;
			this->y = y;
		}
		void Window::feedSize(int width, int height) {
			this->width = width;
			this->height = height;
		}
		void Window::feedVisible(bool visible) {
			this->visible = visible;
		}
		void Window::feedResizable(bool resizable) {
			this->resizable = resizable;
		}
		void Window::feedFocused(bool focused) {
			this->focused = focused;
		}

		void Window::feedKeyEvent(const KeyEvent& keyEvent) {
			keyEventList.push_back(keyEvent);
		}
	}
}
