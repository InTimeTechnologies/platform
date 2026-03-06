#pragma once

// Dependencies | it
#include "../../window/WindowImplementation.h"

// Forward declarations
struct GLFWwindow;

namespace it {
	class WindowBackendGLFW : public WindowImplementation {
		// Static
		public:
			// Functions
			static void s_windowPositionCallback(GLFWwindow* glfwWindow, int x, int y);
			static void s_windowSizeCallback(GLFWwindow* glfwWindow, int width, int height);
			static void s_windowCloseCallback(GLFWwindow* glfwWindow);
			static void s_windowFocusCallback(GLFWwindow* glfwWindow, int focused);
			static void s_windowIconifyCallback(GLFWwindow* glfwWindow, int iconify);
			static void s_windowRefreshCallback(GLFWwindow* glfwWindow);
			static void s_windowMaximizeCallback(GLFWwindow* glfwWindow, int maximized);
			static void s_contentScaleCallback(GLFWwindow* glfwWindow, float xScale, float yScale);

			static void s_keyCallback(GLFWwindow* glfwWindow, int glfwKey, int glfwScancode, int glfwAction, int glfwModifiers);

			static void s_mouseButtonCallback(GLFWwindow* glfwWindow, int glfwMouseButton, int glfwMouseButtonAction, int glfwModifiers);

		// Object
		private:
			// Properties
			GLFWwindow* glfwWindow{ nullptr };

		public:
			// Constructor / Destructor
			WindowBackendGLFW() = default;
			WindowBackendGLFW(const WindowBackendGLFW& other) = delete;
			WindowBackendGLFW(WindowBackendGLFW&& other) noexcept = delete;
			virtual ~WindowBackendGLFW() = default;

			// Operators | assignment
			WindowBackendGLFW& operator=(const WindowBackendGLFW& other) = delete;
			WindowBackendGLFW& operator=(WindowBackendGLFW&& other) noexcept = delete;

			// Operators | equality
			bool operator==(const WindowBackendGLFW& other) const;

			// Getters | Window
			std::string getTitle() const override;
			void getPosition(int* x, int* y) const override;
			void getSize(int* width, int* height) const override;

			// Getters | Window (window state)
			bool getFocused() const;
			bool getIconified() const;
			bool getMaximized() const;
			bool getVisible() const;
			bool getHovered() const;

			// Getters | Window (window property attributes)
			bool getResizable() const;
			bool getDecorated() const;
			bool getFloating() const;
			bool getAutoiconify() const;
			bool getFocusOnShow() const;
			bool getMousePassthrough() const;
			bool getTransparentFrameBuffer() const;

			// Getters | Window (constext attributes OpenGL / OpenGL ES)
			std::string getClientAPI() const;
			std::string getContextCreationAPI() const;
			int getContextMajorVersion() const;
			int getContextMinorVersion() const;
			int getContextRevision() const;

			// Setters | Window
			void setTitle(const std::string& title) override;
			void setPosition(int x, int y) override;
			void setSize(int width, int height) override;

			// Setters (window state)
			void setFocus() override;
			void setIconified(bool iconified) override;
			void setMaximized(bool maximized) override;
			void setVisible(bool visible) override;

			// Setters (window property attributes)
			void setResizable(bool resizable) override;
			void setDecorated(bool decorated) override;
			void setFloating(bool floating) override;
			void setAutoiconify(bool autoiconify) override;
			void setFocusOnShow(bool focusOnShow) override;
			void setMousePassthrough(bool mousePassthrough) override;
			void setTransparentFrameBuffer(bool transparentFrameBuffer) override;

			// Functions | Window
			bool create() override;
			void close() override;
			bool isCreated() const override;
			void swapBuffers() override;
			void makeContextCurrent() override;
	};
}
