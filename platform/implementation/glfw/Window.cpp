#include <window/Window.h>

// Dependencies | std
#include <cassert>

// Dependencies | glfw
#include <GLFW/glfw3.h>

// Dependencies | it::platform
#include <Platform.h>
#include <window/Window.h>

#include <mouse/MouseButtonCode.h>
#include <mouse/MouseButtonAction.h>

#include <keyboard/KeyCode.h>
#include <keyboard/KeyAction.h>

#include <event/Event.h>

namespace it {
	namespace platform {
		// class Window

		// Static | public

		// Properties
		std::string Window::s_defaultTitle{"Platform Implementation Window (GLFW)"};
		int Window::s_defaultX{ 0 };
		int Window::s_defaultY{ 0 };
		int Window::s_defaultWidth{ 800 };
		int Window::s_defaultHeight{ 500 };
		int Window::s_defaultMinimumWidth{ 1 };
		int Window::s_defaultMinimumHeight{ 1 };
		int Window::s_defaultMaximumWidth{ 1920 };
		int Window::s_defaultMaximumHeight{ 1080 };

		bool Window::s_defaultVisible{ true };
		bool Window::s_defaultResizable{ true };

		// Object | public

		// Constructor / Destructor
		Window::Window() {
			// Validate default window size
			int widthValidated = s_defaultWidth;
			int heightValidated = s_defaultHeight;
			if (s_defaultWidth < s_defaultMinimumWidth)
				widthValidated = s_defaultMinimumWidth;
			else if (s_defaultWidth > s_defaultMaximumWidth)
				widthValidated = s_defaultMaximumWidth;
			if (s_defaultHeight < s_defaultMinimumHeight)
				heightValidated = s_defaultMinimumHeight;
			else if (s_defaultHeight > s_defaultMaximumHeight)
				heightValidated = s_defaultMaximumHeight;

			// Create GLFW window
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			glfwWindow = glfwCreateWindow(widthValidated, heightValidated, s_defaultTitle.c_str(), nullptr, nullptr);
			assert(glfwWindow != nullptr && "glfwWindow == nullptr");
			backendHandle = glfwWindow;
			width = widthValidated;
			height = heightValidated;

			// Set minimum and maximum window size
			glfwSetWindowSizeLimits(glfwWindow, s_defaultMinimumWidth, s_defaultMinimumHeight, s_defaultMaximumWidth, s_defaultMaximumHeight);

			// Set window attributes
			glfwSetWindowPos(glfwWindow, s_defaultX, s_defaultY);
			glfwSetWindowAttrib(glfwWindow, GLFW_RESIZABLE, static_cast<int>(Window::s_defaultResizable));
			glfwSetWindowUserPointer(glfwWindow, this);

			// Synchronize OS window values with this Window object
			glfwGetWindowPos(glfwWindow, &this->x, &this->y);
			glfwGetWindowSize(glfwWindow, &this->width, &this->height);
		}
		Window::~Window() {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			glfwDestroyWindow(glfwWindow);
			glfwWindow = nullptr;
		}

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
		bool Window::queryFocused() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_FOCUSED));
		}
		bool Window::queryIconified() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_ICONIFIED));
		}
		bool Window::queryMaximized() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_ICONIFIED));
		}
		bool Window::queryVisible() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_VISIBLE));
		}
		bool Window::queryHovered() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_HOVERED));
		}

		// Getters (window property attributes)
		bool Window::queryResizable() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_RESIZABLE));
		}
		bool Window::queryDecorated() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_DECORATED));
		}
		bool Window::queryFloating() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_FLOATING));
		}
		bool Window::queryAutoiconify() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_AUTO_ICONIFY));
		}
		bool Window::queryFocusOnShow() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_FOCUS_ON_SHOW));
		}
		bool Window::queryMousePassthrough() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_MOUSE_PASSTHROUGH));
		}
		bool Window::queryTransparentFrameBuffer() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			return static_cast<bool>(glfwGetWindowAttrib(glfwWindow, GLFW_TRANSPARENT_FRAMEBUFFER));
		}

		// Getters (constext attribut::es OpenGL / OpenGL ES)
		std::string Window::queryClientAPI() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			int clientApi = glfwGetWindowAttrib(glfwWindow, GLFW_CLIENT_API);
			switch (clientApi) {
				case GLFW_OPENGL_API:    return std::string("OpenGL");
				case GLFW_OPENGL_ES_API: return std::string("OpenGL ES");
				case GLFW_NO_API:        return std::string("no api");
				default:                 return std::string("unknown");
			}
		}
		std::string Window::queryContextCreationAPI() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			int contextCreationApi = glfwGetWindowAttrib(glfwWindow, GLFW_CONTEXT_CREATION_API);
			switch (contextCreationApi) {
				case GLFW_NATIVE_CONTEXT_API: return std::string("native context");
				case GLFW_EGL_CONTEXT_API:    return std::string("egl");
				case GLFW_OSMESA_CONTEXT_API: return std::string("osmesa");
				default:                      return std::string ("unknown");
			}
		}
		int Window::queryContextMajorVersion() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			return glfwGetWindowAttrib(glfwWindow, GLFW_CONTEXT_VERSION_MAJOR);
		}
		int Window::queryContextMinorVersion() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			return glfwGetWindowAttrib(glfwWindow, GLFW_CONTEXT_VERSION_MINOR);
		}
		int Window::queryContextRevision() const {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			return glfwGetWindowAttrib(glfwWindow, GLFW_CONTEXT_REVISION);
		}

		// Setters
		void Window::setTitle(const std::string& title) {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			glfwSetWindowTitle(glfwWindow, title.c_str());
		}
		void Window::setPosition(int x, int y) {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			glfwSetWindowPos(glfwWindow, x, y);
			glfwGetWindowPos(reinterpret_cast<GLFWwindow*>(backendHandle), &this->x, &this->y);
		}
		void Window::setSize(int width, int height) {
			// Validate new size against minimum and maximum size
			if (width < minimumWidth)
				width = minimumWidth;
			else if (width > maximumWidth)
				width = maximumWidth;
			if (height < minimumHeight)
				height = minimumHeight;
			else if (height > maximumHeight)
				height = maximumHeight;

			// Set new window size
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			glfwSetWindowSize(glfwWindow, width, height);
			glfwGetWindowSize(reinterpret_cast<GLFWwindow*>(backendHandle), &this->width, &this->height); // Requesting size in case OS decides to set a different size.
		}

		// Setters (window state)
		void Window::applyFocus() {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			glfwFocusWindow(glfwWindow);
		}
		void Window::applyIconified(bool iconified) {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			if (iconified)
				glfwIconifyWindow(glfwWindow);
			else
				glfwRestoreWindow(glfwWindow);
		}
		void Window::applyMaximized(bool maximized) {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			if (maximized)
				glfwMaximizeWindow(glfwWindow);
			else
				glfwRestoreWindow(glfwWindow);
		}
		void Window::applyVisible(bool visible) {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			if (visible)
				glfwShowWindow(glfwWindow);
			else
				glfwHideWindow(glfwWindow);
		}

		// Setters | Window Property Attributes
		void Window::applyResizable(bool resizable) {
			// Not guaranteed to work on some platforms
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			glfwSetWindowAttrib(glfwWindow, GLFW_RESIZABLE, resizable ? GLFW_TRUE : GLFW_FALSE);
		}
		void Window::applyDecorated(bool decorated) {
			// Not guaranteed to work on some platforms
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			glfwSetWindowAttrib(glfwWindow, GLFW_DECORATED, decorated ? GLFW_TRUE : GLFW_FALSE);
		}
		void Window::applyFloating(bool floating) {
			// Always-on-top
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			glfwSetWindowAttrib(glfwWindow, GLFW_FLOATING, floating ? GLFW_TRUE : GLFW_FALSE);
		}
		void Window::applyAutoiconify(bool autoiconify) {
			// Only relevant for fullscreen windows
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			glfwSetWindowAttrib(glfwWindow, GLFW_AUTO_ICONIFY, autoiconify ? GLFW_TRUE : GLFW_FALSE);
		}
		void Window::applyFocusOnShow(bool focusOnShow) {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			glfwSetWindowAttrib(glfwWindow, GLFW_FOCUS_ON_SHOW, focusOnShow ? GLFW_TRUE : GLFW_FALSE);
		}
		void Window::applyMousePassthrough(bool mousePassthrough) {
			// Mouse clicks go through window
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			glfwSetWindowAttrib(glfwWindow, GLFW_MOUSE_PASSTHROUGH, mousePassthrough ? GLFW_TRUE : GLFW_FALSE);
		}
		void Window::applyTransparentFrameBuffer(bool transparentFrameBuffer) {
			GLFWwindow* glfwWindow = reinterpret_cast<GLFWwindow*>(backendHandle);
			glfwSetWindowAttrib(glfwWindow, GLFW_TRANSPARENT_FRAMEBUFFER, transparentFrameBuffer ? GLFW_TRUE : GLFW_FALSE);
		}

		// Functions | Window
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

		// Functions
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
	}
}
