#pragma once

// Dependencies | std
#include <list>
#include <utility>

// Dependencies | it::platform
#if defined(WINDOW)
#include <window/Window.h>
#include <window/Monitor.h>
#endif

#if defined(MOUSE)
#include <mouse/MouseInput.h>
#endif

#if defined(KEYBOARD)
#include <keyboard/KeyboardInput.h>
#endif

#if defined(JOYSTICK)
#include <joystick/JoystickInput.h>
#endif

namespace it {
	namespace platform {
		class Platform {
			// Static
			protected:
				// Properties
				static Platform* s_singleton;
			
			public:
				// Getters
				static Platform* s_getSingleton();

			// Object
			protected:
				// Properties
				bool isInit{ false };

			public:
				// Properties
				std::list<std::pair<int, std::string>> platformBackendErrorList{};
				size_t platformBackendErrorLimit{ 50 };

				#if defined(WINDOW)
				std::list<Window> windowList{};
				std::list<std::pair<Window*, Event*>> windowEventList{};
				std::list<Monitor> monitorList{};
				std::list<std::pair<Monitor, MonitorConnectionEvent>> monitorConnectionEventList{};
				#endif

				#if defined(MOUSE)
				MouseInput mouseInput{};
				#endif
				
				#if defined(KEYBOARD)
				KeyboardInput keyboardInput{};
				#endif
				
				#if defined(JOYSTICK)
				JoystickInput joystickInput{};
				std::list<JoystickConnectionEvent> joystickConnectionEventList{};
				#endif

				// Constructor / Destructor
				Platform();
				Platform(const Platform& other) = delete;
				Platform(Platform&& other) noexcept = delete;
				virtual ~Platform();

				// Operators | assignment
				Platform& operator=(const Platform& other) = delete;
				Platform& operator=(Platform&& other) noexcept = delete;

				// Getters
				bool getIsInit() const;

				// Functions
				virtual bool init() = 0;
				virtual void deinit() = 0; // Must clear window list prior to deinit window API
				virtual void update() = 0;

				#if defined(WINDOW)
				virtual Window& createWindow() = 0;
				virtual void destroyWindow(Window& window) = 0;
				virtual void updateMonitorList() = 0;
				#endif

			protected:
				#if defined(WINDOW)
				// Functions
				void clearWindowEvents();
				#endif
		};
	}
}
