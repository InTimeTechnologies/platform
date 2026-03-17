#pragma once

// Dependencies | std
#include <string>
#include <functional>
#include <list>

// Dependencies | it::platform
#include <mouse/MouseButtonEvent.h>
#include <keyboard/KeyEvent.h>

namespace it {
	namespace platform {
		class Window {
			// Friends
			friend class Platform;

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
				static int s_defaultX;
				static int s_defaultY;
				static int s_defaultWidth;
				static int s_defaultHeight;
				static bool s_defaultVisible;
				static bool s_defaultResizable;
			
			// Object
			protected:
				// Properties
				void* backendHandle{ nullptr };
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

				// Properties | key events
				std::list<KeyEvent> keyEventList{};
			
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

				std::function<void(KeyEvent keyEvent)> onKeyEvent;
				std::function<void(MouseButtonEvent mouseButtonEvent)> onMouseButtonEvent;

				// Constructor / Destructor
				Window() = default;
				Window(const Window& other) = delete;
				Window(Window&& other) = delete;
				virtual ~Window() = default;
			
				// Operators | assignment
				Window& operator=(const Window& other) = delete;
				Window& operator=(Window&& other) = delete;
				
				// Operators | equality
				bool operator==(const Window& other) const;
				
				// Getters
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
				bool getResizable() const;
				bool getDecorated() const;
				bool getFloating() const;
				bool getAutoiconify() const;
				bool getFocusOnShow() const;
				bool getMousePassthrough() const;
				bool getTransparentFrameBuffer() const;

				// Getters (context attributes OpenGL / OpenGL ES)
				std::string getClientAPI() const;
				std::string getContextCreationAPI() const;
				int getContextMajorVersion() const;
				int getContextMinorVersion() const;
				int getContextRevision() const;

				// Getters (key event list)
				const std::list<KeyEvent>& getKeyEventList() const;
				
				// Setters
				void setTitle(const std::string& title);
				void setPosition(int x, int y);
				void setSize(int width, int height);

				// Setters (window state)
				void setFocus();
				void setIconified(bool iconified);
				void setMaximized(bool maximized);
				void setVisible(bool visible);
				
				// Setters (window property attributes)
				void setResizable(bool resizable);
				void setDecorated(bool decorated);
				void setFloating(bool floating);
				void setAutoiconify(bool autoiconify);
				void setFocusOnShow(bool focusOnShow);
				void setMousePassthrough(bool mousePassthrough);
				void setTransparentFrameBuffer(bool transparentFrameBuffer);

				// Functions
				bool create();
				void close();
				bool isCreated() const;
				void makeContextCurrent();
				void swapBuffers();

				// Functions | Feeders
				void feedTitle(const std::string& title);
				void feedPosition(int x, int y);
				void feedSize(int width, int height);
				void feedVisible(bool visible);
				void feedResizable(bool resizable);
				void feedFocused(bool focused);

				void feedKeyEvent(const KeyEvent& keyEvent);
		};
	}
}
