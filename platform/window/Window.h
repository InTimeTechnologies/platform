#pragma once

// Dependencies | std
#include <string>
#include <functional>

namespace it {
	// Forward declarations
	class WindowImplementation;

	class Window {
		// Structs
		struct Position {
			int x{ 0 };
			int y{ 0 };
		};
		struct Size {
			int width{ 0 };
			int height{ 0 };
		};

		// Static
		public:
			// Properties
			static std::string s_defaultTitle;
			static int s_defaultX, s_defaultY;
			static int s_defaultWidth, s_defaultHeight;
			static bool s_defaultVisible;
			static bool s_defaultResizable;
		
		// Object
		protected:
			// Properties
			WindowImplementation& windowImplementation;

			std::string title{};
			int x{ 0 }, y{ 0 };
			int width{ 0 }, height{ 0 };
			bool closed{ false };

			// Properties (window state)
			bool focused{ false };
			bool iconified{ false };
			bool maximized{ false };
			bool visible{ false };
			bool hovered{ false };

			// Properties (window property attributes)
			bool resizable{ false };
			bool decorated{ false };
			bool floating{ false };
			bool autoiconify{ false };
			bool focusOnShow{ false };
			bool mousePassthrough{ false };
			bool transparentFrameBuffer{ false };

			// Properties (context attributes OpenGL / OpenGL ES)
			std::string clientAPI{};
			std::string contextCreationAPI{};
			std::string contextMajorVersion{};
			std::string contextMinorVersion{};
			std::string contextRevision{};
		
		public:
			// Properties
			std::function<void(int, int)> onResize;
			std::function<void(int, int)> onMove;
			std::function<void()> onClose;
			std::function<void(bool)> onFocus;
			std::function<void(bool)> onIconify;
			std::function<void()> onRefresh;
			std::function<void(bool)> onMaximize;
			std::function<void(float, float)> onScale;

			// Constructor / Destructor
			Window() = delete;
			Window(WindowImplementation& windowImplementation);
			Window(const Window& other) = delete;
			Window(Window&& other) = delete;
			virtual ~Window() = default;
		
			// Operators | assignment
			Window& operator=(const Window& other) = delete;
			Window& operator=(Window&& other) = delete;
			
			// Operators | equality
			bool operator==(const Window& other) const;
			
			// Getters
			WindowImplementation& getWindowImplementation() const;
			std::string getTitle() const;
			int getX() const;
			int getY() const;
			int getWidth() const;
			int getHeight() const;

			// Getters (window state)
			bool getFocused() const;
			bool getIconified() const;
			bool getMaximized() const;
			bool getVisible() const;
			bool getHovered() const;

			// Getters (window property attributes)
			bool getResizeable() const;
			bool getDecorated() const;
			bool getFloating() const;
			bool getAutoiconify() const;
			bool getFocusOnShow() const;
			bool getMousePassthrough() const;
			bool getTransparentFrameBuffer() const;

			// Getters (context attributes OpenGL / OpenGL ES)
			std::string getClientAPI() const;
			std::string getContextCreationAPI() const;
			std::string getContextMajorVersion() const;
			std::string getContextMinorVersion() const;
			std::string getContextRevision() const;
			
			// Setters
			void setTitle(const std::string& title);
			void setPosition(int x, int y);
			void setSize(int width, int height);
			void setVisible(bool visible);
			void setResizeable(bool resizable);
			void setFocused(bool focused);

			// Functions
			bool create();
			void close();
			bool isCreated() const;
			void makeContextCurrent();
			void swapBuffers();
			void synchWithBackend();

			// Feeders
			void feedTitle(const std::string& title);
			void feedPosition(int x, int y);
			void feedSize(int width, int height);
			void feedVisible(bool visible);
			void feedResizable(bool resizable);
			void feedFocused(bool focused);
	};
}
