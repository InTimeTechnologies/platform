#pragma once

// Dependencies | std
#include <string>

namespace it {
	// Forward declarations
	class Window;

	class WindowImplementation {
		// Friends
		friend class Window;

		// Object
		protected:
			// Properties
			Window* owner{ nullptr };

		public:
			// Constructor / Destructor
			WindowImplementation() = default;
			WindowImplementation(const WindowImplementation& other) = delete;
			WindowImplementation(WindowImplementation&& other) noexcept = delete;
			virtual ~WindowImplementation() = default;

			// Operators | assignment
			WindowImplementation& operator=(const WindowImplementation& other) = delete;
			WindowImplementation& operator=(WindowImplementation&& other) = delete;

			// Getters
			virtual std::string getTitle() const = 0;
			virtual void getPosition(int* x, int* y) const = 0;
			virtual void getSize(int* width, int* height) const = 0;

			// Getters (window state)
			virtual bool getFocused() const = 0;
			virtual bool getIconified() const = 0;
			virtual bool getMaximized() const = 0;
			virtual bool getVisible() const = 0;
			virtual bool getHovered() const = 0;

			// Getters (window property attributes)
			virtual bool getResizable() const = 0;
			virtual bool getDecorated() const = 0;
			virtual bool getFloating() const = 0;
			virtual bool getAutoiconify() const = 0;
			virtual bool getFocusOnShow() const = 0;
			virtual bool getMousePassthrough() const = 0;
			virtual bool getTransparentFrameBuffer() const = 0;

			// Getters (constext attributes OpenGL / OpenGL ES)
			virtual std::string getClientAPI() const = 0;
			virtual std::string getContextCreationAPI() const = 0;
			virtual int getContextMajorVersion() const = 0;
			virtual int getContextMinorVersion() const = 0;
			virtual int getContextRevision() const = 0;

			// Setters
			virtual void setTitle(const std::string& title) = 0;
			virtual void setPosition(int x, int y) = 0;
			virtual void setSize(int width, int height) = 0;

			// Setters (window state)
			virtual void setFocus() = 0;
			virtual void setIconified(bool iconified) = 0;
			virtual void setMaximized(bool maximized) = 0;
			virtual void setVisible(bool visible) = 0;

			// Setters (window property attributes)
			virtual void setResizable(bool resizable) = 0;
			virtual void setDecorated(bool decorated) = 0;
			virtual void setFloating(bool floating) = 0;
			virtual void setAutoiconify(bool autoiconify) = 0;
			virtual void setFocusOnShow(bool focusOnShow) = 0;
			virtual void setMousePassthrough(bool mousePassthrough) = 0;
			virtual void setTransparentFrameBuffer(bool transparentFrameBuffer) = 0;

			// Functions
			virtual bool create() = 0;
			virtual void close() = 0;
			virtual bool isCreated() const = 0;
			virtual void makeContextCurrent() = 0;
			virtual void swapBuffers() = 0;
	};
}
