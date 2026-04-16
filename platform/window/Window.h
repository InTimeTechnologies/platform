#pragma once

// Dependencies | std
#include <string>
#include <functional>

// Dependencies | platform
#include <event/Event.h>

namespace it {
	namespace platform {
		class Window {
			// Friends
			friend class Platform;
			friend class PlatformImplementation;

			// Static
			public:
				// Properties
				static std::string s_defaultTitle;
				static int s_defaultX;
				static int s_defaultY;
				static int s_defaultWidth;
				static int s_defaultHeight;
				static int s_defaultMinimumWidth;
				static int s_defaultMinimumHeight;
				static int s_defaultMaximumWidth;
				static int s_defaultMaximumHeight;

				static bool s_defaultVisible;
				static bool s_defaultResizable;
			
			// Object
			protected:
				// Properties
				void* backendHandle{ nullptr };
				std::string title{ s_defaultTitle };
				int x{ s_defaultX };
				int y{ s_defaultY };
				int width{ s_defaultWidth };
				int height{ s_defaultHeight };
				int minimumWidth{ s_defaultMinimumWidth };
				int minimumHeight{ s_defaultMinimumHeight };
				int maximumWidth{ s_defaultMaximumWidth };
				int maximumHeight{ s_defaultMaximumHeight };
			
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
				Window();
				Window(const Window& other) = delete;
				Window(Window&& other) = delete;
				virtual ~Window();
			
				// Operators | assignment
				Window& operator=(const Window& other) = delete;
				Window& operator=(Window&& other) = delete;
				
				// Operators | equality
				bool operator==(const Window& other) const;

				// -------------------------------------------------------------------------
				// Implementation specific start
				// -------------------------------------------------------------------------
				
				// Getters
				std::string getTitle() const;
				int getX() const;
				int getY() const;
				int getWidth() const;
				int getHeight() const;

				// Getters (window state)
				bool queryFocused() const;
				bool queryIconified() const;
				bool queryMaximized() const;
				bool queryVisible() const;
				bool queryHovered() const;

				// Getters (window property attributes)
				bool queryResizable() const;
				bool queryDecorated() const;
				bool queryFloating() const;
				bool queryAutoiconify() const;
				bool queryFocusOnShow() const;
				bool queryMousePassthrough() const;
				bool queryTransparentFrameBuffer() const;

				// Getters (context attributes OpenGL / OpenGL ES)
				std::string queryClientAPI() const;
				std::string queryContextCreationAPI() const;
				int queryContextMajorVersion() const;
				int queryContextMinorVersion() const;
				int queryContextRevision() const;
				
				// Setters
				void setTitle(const std::string& title);
				void setPosition(int x, int y);
				void setSize(int width, int height);

				// Setters (window state)
				void applyFocus();
				void applyIconified(bool iconified);
				void applyMaximized(bool maximized);
				void applyVisible(bool visible);
				
				// Setters (window property attributes)
				void applyResizable(bool resizable);
				void applyDecorated(bool decorated);
				void applyFloating(bool floating);
				void applyAutoiconify(bool autoiconify);
				void applyFocusOnShow(bool focusOnShow);
				void applyMousePassthrough(bool mousePassthrough);
				void applyTransparentFrameBuffer(bool transparentFrameBuffer);

				// Functions
				bool isCreated() const;
				void makeContextCurrent();
				void swapBuffers();

				// -------------------------------------------------------------------------
				// Implementation specific end
				// -------------------------------------------------------------------------

			private:
				// Functions
				void feedTitle(const std::string& title);
				void feedPosition(int x, int y);
				void feedSize(int width, int height);
		};
	}
}
