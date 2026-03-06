#include "WindowBackendGLFW.h"

// Dependencies | std
#include <cassert>
#include <iostream>

// Dependencies | glfw
#include <GLFW/glfw3.h>

// Dependencies | it
#include "PlatformBackendGLFW.h"
#include "../../window/Window.h"
#include "../../keyboard/Key.h"
#include "../../keyboard/KeyboardInput.h"

namespace it {
	// class WindowBackendGLFW

	// Static | public

	// Functions
	void WindowBackendGLFW::s_windowPositionCallback(GLFWwindow* glfwWindow, int x, int y) {
		WindowBackendGLFW* windowBackendGLFW = static_cast<WindowBackendGLFW*>(glfwGetWindowUserPointer(glfwWindow));
		Window* window = windowBackendGLFW->owner;
		if (window->onMove)
			window->onMove(x, y);
		window->feedPosition(x, y);
	}
	void WindowBackendGLFW::s_windowSizeCallback(GLFWwindow* glfwWindow, int width, int height) {
		WindowBackendGLFW* windowBackendGLFW = static_cast<WindowBackendGLFW*>(glfwGetWindowUserPointer(glfwWindow));
		Window* window = windowBackendGLFW->owner;
		if (window->onResize)
			window->onResize(width, height);
		window->feedSize(width, height);
	}
	void WindowBackendGLFW::s_windowCloseCallback(GLFWwindow* glfwWindow) {
		WindowBackendGLFW* windowBackendGLFW = static_cast<WindowBackendGLFW*>(glfwGetWindowUserPointer(glfwWindow));
		Window* window = windowBackendGLFW->owner;
		if (window->onClose)
			window->onClose();
	}
	void WindowBackendGLFW::s_windowFocusCallback(GLFWwindow* glfwWindow, int focused) {
		WindowBackendGLFW* windowBackendGLFW = static_cast<WindowBackendGLFW*>(glfwGetWindowUserPointer(glfwWindow));
		Window* window = windowBackendGLFW->owner;
		if (window->onFocus)
			window->onFocus(static_cast<bool>(focused));
		window->feedFocused(static_cast<bool>(focused));
	}
	void WindowBackendGLFW::s_windowIconifyCallback(GLFWwindow* glfwWindow, int iconify) {
		WindowBackendGLFW* windowBackendGLFW = static_cast<WindowBackendGLFW*>(glfwGetWindowUserPointer(glfwWindow));
		Window* window = windowBackendGLFW->owner;
		if (window->onIconify)
			window->onIconify(static_cast<bool>(iconify));
		window->feedVisible(!static_cast<bool>(!iconify));
	}
	void WindowBackendGLFW::s_windowRefreshCallback(GLFWwindow* glfwWindow) {
		WindowBackendGLFW* windowBackendGLFW = static_cast<WindowBackendGLFW*>(glfwGetWindowUserPointer(glfwWindow));
		Window* window = windowBackendGLFW->owner;
		if (window->onRefresh)
			window->onRefresh();
	}
	void WindowBackendGLFW::s_windowMaximizeCallback(GLFWwindow* glfwWindow, int maximized) {
		WindowBackendGLFW* windowBackendGLFW = static_cast<WindowBackendGLFW*>(glfwGetWindowUserPointer(glfwWindow));
		Window* window = windowBackendGLFW->owner;
		if (window->onMaximize)
			window->onMaximize(static_cast<bool>(maximized));
	}
	void WindowBackendGLFW::s_contentScaleCallback(GLFWwindow* glfwWindow, float xScale, float yScale) {
		WindowBackendGLFW* windowBackendGLFW = static_cast<WindowBackendGLFW*>(glfwGetWindowUserPointer(glfwWindow));
		Window* window = windowBackendGLFW->owner;
		if (window->onScale)
			window->onScale(xScale, yScale);
	}

	void WindowBackendGLFW::s_keyCallback(GLFWwindow* glfwWindow, int glfwKey, int glfwScancode, int glfwAction, int glfwMods) {
		WindowBackendGLFW* windowBackendGLFW = static_cast<WindowBackendGLFW*>(glfwGetWindowUserPointer(glfwWindow));
		Window* window = windowBackendGLFW->owner;

		KeyCode keyCode = KeyCode::UNKNOWN;
		switch (glfwKey) {
			case GLFW_KEY_SPACE:         keyCode = KeyCode::SPACE;           break;
			case GLFW_KEY_APOSTROPHE:    keyCode = KeyCode::APOSTROPHE;      break;
			case GLFW_KEY_COMMA:         keyCode = KeyCode::COMMA;           break;
			case GLFW_KEY_MINUS:         keyCode = KeyCode::MINUS;           break;
			case GLFW_KEY_PERIOD:        keyCode = KeyCode::PERIOD;          break;
			case GLFW_KEY_SLASH:         keyCode = KeyCode::SLASH;           break;
			case GLFW_KEY_0:             keyCode = KeyCode::ALPHA_0;         break;
			case GLFW_KEY_1:             keyCode = KeyCode::ALPHA_1;         break;
			case GLFW_KEY_2:             keyCode = KeyCode::ALPHA_2;         break;
			case GLFW_KEY_3:             keyCode = KeyCode::ALPHA_3;         break;
			case GLFW_KEY_4:             keyCode = KeyCode::ALPHA_4;         break;
			case GLFW_KEY_5:             keyCode = KeyCode::ALPHA_5;         break;
			case GLFW_KEY_6:             keyCode = KeyCode::ALPHA_6;         break;
			case GLFW_KEY_7:             keyCode = KeyCode::ALPHA_7;         break;
			case GLFW_KEY_8:             keyCode = KeyCode::ALPHA_8;         break;
			case GLFW_KEY_9:             keyCode = KeyCode::ALPHA_9;         break;
			case GLFW_KEY_SEMICOLON:     keyCode = KeyCode::SEMICOLON;       break;
			case GLFW_KEY_EQUAL:         keyCode = KeyCode::EQUAL;           break;
			case GLFW_KEY_A:             keyCode = KeyCode::A;               break;
			case GLFW_KEY_B:             keyCode = KeyCode::B;               break;
			case GLFW_KEY_C:             keyCode = KeyCode::C;               break;
			case GLFW_KEY_D:             keyCode = KeyCode::D;               break;
			case GLFW_KEY_E:             keyCode = KeyCode::E;               break;
			case GLFW_KEY_F:             keyCode = KeyCode::F;               break;
			case GLFW_KEY_G:             keyCode = KeyCode::G;               break;
			case GLFW_KEY_H:             keyCode = KeyCode::H;               break;
			case GLFW_KEY_I:             keyCode = KeyCode::I;               break;
			case GLFW_KEY_J:             keyCode = KeyCode::J;               break;
			case GLFW_KEY_K:             keyCode = KeyCode::K;               break;
			case GLFW_KEY_L:             keyCode = KeyCode::L;               break;
			case GLFW_KEY_M:             keyCode = KeyCode::M;               break;
			case GLFW_KEY_N:             keyCode = KeyCode::N;               break;
			case GLFW_KEY_O:             keyCode = KeyCode::O;               break;
			case GLFW_KEY_P:             keyCode = KeyCode::P;               break;
			case GLFW_KEY_Q:             keyCode = KeyCode::Q;               break;
			case GLFW_KEY_R:             keyCode = KeyCode::R;               break;
			case GLFW_KEY_S:             keyCode = KeyCode::S;               break;
			case GLFW_KEY_T:             keyCode = KeyCode::T;               break;
			case GLFW_KEY_U:             keyCode = KeyCode::U;               break;
			case GLFW_KEY_V:             keyCode = KeyCode::V;               break;
			case GLFW_KEY_W:             keyCode = KeyCode::W;               break;
			case GLFW_KEY_X:             keyCode = KeyCode::X;               break;
			case GLFW_KEY_Y:             keyCode = KeyCode::Y;               break;
			case GLFW_KEY_Z:             keyCode = KeyCode::Z;               break;
			case GLFW_KEY_LEFT_BRACKET:  keyCode = KeyCode::LEFT_BRACKET;    break;
			case GLFW_KEY_BACKSLASH:     keyCode = KeyCode::BACKSLASH;       break;
			case GLFW_KEY_RIGHT_BRACKET: keyCode = KeyCode::RIGHT_BRACKET;   break;
			case GLFW_KEY_GRAVE_ACCENT:  keyCode = KeyCode::GRAVE_ACCENT;    break;
			case GLFW_KEY_WORLD_1:       keyCode = KeyCode::WORLD_1;         break;
			case GLFW_KEY_WORLD_2:       keyCode = KeyCode::WORLD_2;         break;
			case GLFW_KEY_ESCAPE:        keyCode = KeyCode::ESCAPE;          break;
			case GLFW_KEY_ENTER:         keyCode = KeyCode::ENTER;           break;
			case GLFW_KEY_TAB:           keyCode = KeyCode::TAB;             break;
			case GLFW_KEY_BACKSPACE:     keyCode = KeyCode::BACKSPACE;       break;
			case GLFW_KEY_INSERT:        keyCode = KeyCode::INSERT;          break;
			case GLFW_KEY_DELETE:        keyCode = KeyCode::DELETE;          break;
			case GLFW_KEY_RIGHT:         keyCode = KeyCode::RIGHT_ARROW;     break;
			case GLFW_KEY_LEFT:          keyCode = KeyCode::LEFT_ARROW;      break;
			case GLFW_KEY_DOWN:          keyCode = KeyCode::DOWN_ARROW;      break;
			case GLFW_KEY_UP:            keyCode = KeyCode::UP_ARROW;        break;
			case GLFW_KEY_PAGE_UP:       keyCode = KeyCode::PAGE_UP;         break;
			case GLFW_KEY_PAGE_DOWN:     keyCode = KeyCode::PAGE_DOWN;       break;
			case GLFW_KEY_HOME:          keyCode = KeyCode::HOME;            break;
			case GLFW_KEY_END:           keyCode = KeyCode::END;             break;
			case GLFW_KEY_CAPS_LOCK:     keyCode = KeyCode::CAPS_LOCK;       break;
			case GLFW_KEY_SCROLL_LOCK:   keyCode = KeyCode::SCROLL_LOCK;     break;
			case GLFW_KEY_NUM_LOCK:      keyCode = KeyCode::NUM_LOCK;        break;
			case GLFW_KEY_PRINT_SCREEN:  keyCode = KeyCode::PRINT_SCREEN;    break;
			case GLFW_KEY_PAUSE:         keyCode = KeyCode::PAUSE;           break;
			case GLFW_KEY_F1:            keyCode = KeyCode::F1;              break;
			case GLFW_KEY_F2:            keyCode = KeyCode::F2;              break;
			case GLFW_KEY_F3:            keyCode = KeyCode::F3;              break;
			case GLFW_KEY_F4:            keyCode = KeyCode::F4;              break;
			case GLFW_KEY_F5:            keyCode = KeyCode::F5;              break;
			case GLFW_KEY_F6:            keyCode = KeyCode::F6;              break;
			case GLFW_KEY_F7:            keyCode = KeyCode::F7;              break;
			case GLFW_KEY_F8:            keyCode = KeyCode::F8;              break;
			case GLFW_KEY_F9:            keyCode = KeyCode::F9;              break;
			case GLFW_KEY_F10:           keyCode = KeyCode::F10;             break;
			case GLFW_KEY_F11:           keyCode = KeyCode::F11;             break;
			case GLFW_KEY_F12:           keyCode = KeyCode::F12;             break;
			case GLFW_KEY_F13:           keyCode = KeyCode::F13;             break;
			case GLFW_KEY_F14:           keyCode = KeyCode::F14;             break;
			case GLFW_KEY_F15:           keyCode = KeyCode::F15;             break;
			case GLFW_KEY_F16:           keyCode = KeyCode::F16;             break;
			case GLFW_KEY_F17:           keyCode = KeyCode::F17;             break;
			case GLFW_KEY_F18:           keyCode = KeyCode::F18;             break;
			case GLFW_KEY_F19:           keyCode = KeyCode::F19;             break;
			case GLFW_KEY_F20:           keyCode = KeyCode::F20;             break;
			case GLFW_KEY_F21:           keyCode = KeyCode::F21;             break;
			case GLFW_KEY_F22:           keyCode = KeyCode::F22;             break;
			case GLFW_KEY_F23:           keyCode = KeyCode::F23;             break;
			case GLFW_KEY_F24:           keyCode = KeyCode::F24;             break;
			case GLFW_KEY_F25:           keyCode = KeyCode::F25;             break;
			case GLFW_KEY_KP_0:          keyCode = KeyCode::NUMPAD_0;        break;
			case GLFW_KEY_KP_1:          keyCode = KeyCode::NUMPAD_1;        break;
			case GLFW_KEY_KP_2:          keyCode = KeyCode::NUMPAD_2;        break;
			case GLFW_KEY_KP_3:          keyCode = KeyCode::NUMPAD_3;        break;
			case GLFW_KEY_KP_4:          keyCode = KeyCode::NUMPAD_4;        break;
			case GLFW_KEY_KP_5:          keyCode = KeyCode::NUMPAD_5;        break;
			case GLFW_KEY_KP_6:          keyCode = KeyCode::NUMPAD_6;        break;
			case GLFW_KEY_KP_7:          keyCode = KeyCode::NUMPAD_7;        break;
			case GLFW_KEY_KP_8:          keyCode = KeyCode::NUMPAD_8;        break;
			case GLFW_KEY_KP_9:          keyCode = KeyCode::NUMPAD_9;        break;
			case GLFW_KEY_KP_DECIMAL:    keyCode = KeyCode::NUMPAD_DECIMAL;  break;
			case GLFW_KEY_KP_DIVIDE:     keyCode = KeyCode::NUMPAD_DIVIDE;   break;
			case GLFW_KEY_KP_MULTIPLY:   keyCode = KeyCode::NUMPAD_MULTIPLY; break;
			case GLFW_KEY_KP_SUBTRACT:   keyCode = KeyCode::NUMPAD_SUBTRACT; break;
			case GLFW_KEY_KP_ADD:        keyCode = KeyCode::NUMPAD_ADD;      break;
			case GLFW_KEY_KP_ENTER:      keyCode = KeyCode::NUMPAD_ENTER;    break;
			case GLFW_KEY_KP_EQUAL:      keyCode = KeyCode::NUMPAD_EQUAL;    break;
			case GLFW_KEY_LEFT_SHIFT:    keyCode = KeyCode::LEFT_SHIFT;      break;
			case GLFW_KEY_LEFT_CONTROL:  keyCode = KeyCode::LEFT_CONTROL;    break;
			case GLFW_KEY_LEFT_ALT:      keyCode = KeyCode::LEFT_ALT;        break;
			case GLFW_KEY_LEFT_SUPER:    keyCode = KeyCode::LEFT_SUPER;      break;
			case GLFW_KEY_RIGHT_SHIFT:   keyCode = KeyCode::RIGHT_SHIFT;     break;
			case GLFW_KEY_RIGHT_CONTROL: keyCode = KeyCode::RIGHT_CONTROL;   break;
			case GLFW_KEY_RIGHT_ALT:     keyCode = KeyCode::RIGHT_ALT;       break;
			case GLFW_KEY_RIGHT_SUPER:   keyCode = KeyCode::RIGHT_SUPER;     break;
			case GLFW_KEY_MENU:          keyCode = KeyCode::MENU;            break;
			default:                     keyCode = KeyCode::UNKNOWN;         break;
		}

		Key::Action keyAction = Key::Action::UNKNOWN;
		switch (glfwAction) {
			case GLFW_PRESS:   keyAction = Key::Action::PRESS;   break;
			case GLFW_REPEAT:  keyAction = Key::Action::REPEAT;  break;
			case GLFW_RELEASE: keyAction = Key::Action::RELEASE; break;
			default:           keyAction = Key::Action::UNKNOWN; break;
		}

		PlatformBackendGLFW* platformBackendGLFW = PlatformBackendGLFW::s_getSingleton();
		assert(platformBackendGLFW != nullptr && "platformBackendGLFW == nullptr");
		platformBackendGLFW->addKeyEvent(keyCode, keyAction);
	}

	void WindowBackendGLFW::s_mouseButtonCallback(GLFWwindow* glfwWindow, int glfwMouseButton, int glfwMouseButtonAction, int glfwModifiers) {
		WindowBackendGLFW* windowBackendGLFW = static_cast<WindowBackendGLFW*>(glfwGetWindowUserPointer(glfwWindow));
		Window* window = windowBackendGLFW->owner;

		MouseButtonCode mouseButtonCode = MouseButtonCode::UNKNOWN;
		switch (glfwMouseButton) {
			case GLFW_MOUSE_BUTTON_1: mouseButtonCode = MouseButtonCode::BUTTON_CODE_1; break;
			case GLFW_MOUSE_BUTTON_2: mouseButtonCode = MouseButtonCode::BUTTON_CODE_2; break;
			case GLFW_MOUSE_BUTTON_3: mouseButtonCode = MouseButtonCode::BUTTON_CODE_3; break;
			case GLFW_MOUSE_BUTTON_4: mouseButtonCode = MouseButtonCode::BUTTON_CODE_4; break;
			case GLFW_MOUSE_BUTTON_5: mouseButtonCode = MouseButtonCode::BUTTON_CODE_5; break;
			case GLFW_MOUSE_BUTTON_6: mouseButtonCode = MouseButtonCode::BUTTON_CODE_6; break;
			case GLFW_MOUSE_BUTTON_7: mouseButtonCode = MouseButtonCode::BUTTON_CODE_7; break;
			case GLFW_MOUSE_BUTTON_8: mouseButtonCode = MouseButtonCode::BUTTON_CODE_8; break;
			default:                  mouseButtonCode = MouseButtonCode::UNKNOWN; break;
		}

		MouseButton::Action mouseButtonAction = MouseButton::Action::UNKNOWN;
		switch (glfwMouseButtonAction) {
			case GLFW_PRESS:   mouseButtonAction = MouseButton::Action::PRESS;   break;
			case GLFW_RELEASE: mouseButtonAction = MouseButton::Action::RELEASE; break;
			default:           mouseButtonAction = MouseButton::Action::UNKNOWN; break;
		}

		PlatformBackendGLFW* platformBackendGLFW = PlatformBackendGLFW::s_getSingleton();
		assert(platformBackendGLFW != nullptr && "platformBackendGLFW == nullptr");
		platformBackendGLFW->addMouseEvent(mouseButtonCode, mouseButtonAction);
	}

	// Object | public

	// Operators | equality
	bool WindowBackendGLFW::operator==(const WindowBackendGLFW& other) const {
		return this == &other;
	}

	// Getters | Window
	std::string WindowBackendGLFW::getTitle() const {
		return std::string(glfwGetWindowTitle(glfwWindow));
	}
	void WindowBackendGLFW::getPosition(int* x, int* y) const {
		glfwGetWindowPos(glfwWindow, x, y);
	}
	void WindowBackendGLFW::getSize(int* width, int* height) const {
		glfwGetWindowSize(glfwWindow, width, height);
	}

	// Getters | Window (window state)
	bool WindowBackendGLFW::getFocused() const {
		return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_FOCUSED));
	}
	bool WindowBackendGLFW::getIconified() const {
		return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_ICONIFIED));
	}
	bool WindowBackendGLFW::getMaximized() const {
		return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_ICONIFIED));
	}
	bool WindowBackendGLFW::getVisible() const {
		return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_VISIBLE));
	}
	bool WindowBackendGLFW::getHovered() const {
		return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_HOVERED));
	}

	// Getters (window property attributes)
	bool WindowBackendGLFW::getResizable() const {
		return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_RESIZABLE));
	}
	bool WindowBackendGLFW::getDecorated() const {
		return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_DECORATED));
	}
	bool WindowBackendGLFW::getFloating() const {
		return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_FLOATING));
	}
	bool WindowBackendGLFW::getAutoiconify() const {
		return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_AUTO_ICONIFY));
	}
	bool WindowBackendGLFW::getFocusOnShow() const {
		return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_FOCUS_ON_SHOW));
	}
	bool WindowBackendGLFW::getMousePassthrough() const {
		return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_MOUSE_PASSTHROUGH));
	}
	bool WindowBackendGLFW::getTransparentFrameBuffer() const {
		return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_TRANSPARENT_FRAMEBUFFER));
	}

	// Getters (constext attribut::es OpenGL / OpenGL ES)
	std::string WindowBackendGLFW::getClientAPI() const {
		int clientApi = glfwGetWindowAttrib(glfwWindow, GLFW_CLIENT_API);
		switch (clientApi) {
			case GLFW_OPENGL_API:    return std::string("OpenGL");
			case GLFW_OPENGL_ES_API: return std::string("OpenGL ES");
			case GLFW_NO_API:        return std::string("no api");
			default:                 return std::string("unknown");
		}
	}
	std::string WindowBackendGLFW::getContextCreationAPI() const {
		int contextCreationApi = glfwGetWindowAttrib(glfwWindow, GLFW_CONTEXT_CREATION_API);
		switch (contextCreationApi) {
			case GLFW_NATIVE_CONTEXT_API: return std::string("native context");
			case GLFW_EGL_CONTEXT_API:    return std::string("egl");
			case GLFW_OSMESA_CONTEXT_API: return std::string("osmesa");
			default:                      return std::string ("unknown");
		}
	}
	int WindowBackendGLFW::getContextMajorVersion() const {
		return glfwGetWindowAttrib(glfwWindow, GLFW_CONTEXT_VERSION_MAJOR);
	}
	int WindowBackendGLFW::getContextMinorVersion() const {
		return glfwGetWindowAttrib(glfwWindow, GLFW_CONTEXT_VERSION_MINOR);
	}
	int WindowBackendGLFW::getContextRevision() const {
		return glfwGetWindowAttrib(glfwWindow, GLFW_CONTEXT_REVISION);
	}

	// Setters | Window
	void WindowBackendGLFW::setTitle(const std::string& title) {
		glfwSetWindowTitle(glfwWindow, title.c_str());
	}
	void WindowBackendGLFW::setPosition(int x, int y) {
		glfwSetWindowPos(glfwWindow, x, y);
	}
	void WindowBackendGLFW::setSize(int width, int height) {
		glfwSetWindowSize(glfwWindow, width, height);
	}

	// Setters | Window State
	void WindowBackendGLFW::setFocus() {
		glfwFocusWindow(glfwWindow);
	}
	void WindowBackendGLFW::setIconified(bool iconified) {
		if (iconified)
			glfwIconifyWindow(glfwWindow);
		else
			glfwRestoreWindow(glfwWindow);
	}
	void WindowBackendGLFW::setMaximized(bool maximized) {
		if (maximized)
			glfwMaximizeWindow(glfwWindow);
		else
			glfwRestoreWindow(glfwWindow);
	}
	void WindowBackendGLFW::setVisible(bool visible) {
		if (visible)
			glfwShowWindow(glfwWindow);
		else
			glfwHideWindow(glfwWindow);
	}

	// Setters | Window Property Attributes
	void WindowBackendGLFW::setResizable(bool resizable) {
		// Not guaranteed to work on some platforms
		glfwSetWindowAttrib(glfwWindow, GLFW_RESIZABLE, resizable ? GLFW_TRUE : GLFW_FALSE);
	}
	void WindowBackendGLFW::setDecorated(bool decorated) {
		// Not guaranteed to work on some platforms
		glfwSetWindowAttrib(glfwWindow, GLFW_DECORATED, decorated ? GLFW_TRUE : GLFW_FALSE);
	}
	void WindowBackendGLFW::setFloating(bool floating) {
		// Always-on-top
		glfwSetWindowAttrib(glfwWindow, GLFW_FLOATING, floating ? GLFW_TRUE : GLFW_FALSE);
	}
	void WindowBackendGLFW::setAutoiconify(bool autoiconify) {
		// Only relevant for fullscreen windows
		glfwSetWindowAttrib(glfwWindow, GLFW_AUTO_ICONIFY, autoiconify ? GLFW_TRUE : GLFW_FALSE);
	}
	void WindowBackendGLFW::setFocusOnShow(bool focusOnShow) {
		glfwSetWindowAttrib(glfwWindow, GLFW_FOCUS_ON_SHOW, focusOnShow ? GLFW_TRUE : GLFW_FALSE);
	}
	void WindowBackendGLFW::setMousePassthrough(bool mousePassthrough) {
		// Mouse clicks go through window
		glfwSetWindowAttrib(glfwWindow, GLFW_MOUSE_PASSTHROUGH, mousePassthrough ? GLFW_TRUE : GLFW_FALSE);
	}
	void WindowBackendGLFW::setTransparentFrameBuffer(bool transparentFrameBuffer) {
		glfwSetWindowAttrib(glfwWindow, GLFW_TRANSPARENT_FRAMEBUFFER, transparentFrameBuffer ? GLFW_TRUE : GLFW_FALSE);
	}

	// Functions | Window
	bool WindowBackendGLFW::create() {
		// Create window
		glfwWindow = glfwCreateWindow(Window::s_defaultWidth, Window::s_defaultHeight, Window::s_defaultTitle.c_str(), nullptr, nullptr);
		if (!glfwWindow)
			return false;

		// Set window attributes
		glfwSetWindowPos(glfwWindow, Window::s_defaultX, Window::s_defaultY);
		glfwSetWindowAttrib(glfwWindow, GLFW_RESIZABLE, static_cast<int>(Window::s_defaultResizable));
		glfwSetWindowUserPointer(glfwWindow, this);

		// Feed all OS values
		Window* window = owner;
		window->feedTitle(Window::s_defaultTitle);
		window->feedPosition(Window::s_defaultX, Window::s_defaultY);
		window->feedSize(Window::s_defaultWidth, Window::s_defaultHeight);
		window->feedVisible(Window::s_defaultVisible);
		window->feedResizable(Window::s_defaultResizable);

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
	void WindowBackendGLFW::close() {
		glfwDestroyWindow(glfwWindow);
		glfwWindow = nullptr;
	}
	bool WindowBackendGLFW::isCreated() const {
		return glfwWindow != nullptr;
	}
	void WindowBackendGLFW::swapBuffers() {
		glfwSwapBuffers(glfwWindow);
	}
	void WindowBackendGLFW::makeContextCurrent() {
		glfwMakeContextCurrent(glfwWindow);
	}
}
