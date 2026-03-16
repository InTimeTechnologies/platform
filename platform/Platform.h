#pragma once

// Dependencies | it::platform
#if defined(WINDOW)
#include "window/WindowManager.h"
#endif

#if defined(MOUSE)
#include "mouse/MouseInput.h"
#endif

#if defined(KEYBOARD)
#include "keyboard/KeyboardInput.h"
#endif

#if defined(JOYSTICK)
#include "joystick/JoystickInput.h"
#endif

namespace it {
	namespace platform {
		class Platform {
			// Static
			private:
				// Properties
				static Platform* s_singleton;
			
			public:
				// Getters
				static Platform* s_getSingleton();

			// Object
			private:
				// Properties
				bool isInit{ false };

			public:
				// Properties
				#if defined(WINDOW)
				WindowManager windowManager{};
				#endif
				#if defined(MOUSE)
				MouseInput mouseInput{};
				#endif
				#if defined(KEYBOARD)
				KeyboardInput keyboardInput{};
				#endif
				#if defined(JOYSTICK)
				JoystickInput joystickInput{};
				#endif

				// Constructor / Destructor
				Platform();
				Platform(const Platform& other) = delete;
				Platform(Platform&& other) noexcept = delete;
				~Platform();

				// Operators | assignment
				Platform& operator=(const Platform& other) = delete;
				Platform& operator=(Platform&& other) noexcept = delete;

				// Getters
				bool getIsInit() const;

				// Functions
				bool init();
				void deinit();
				void update();
		};
	}
}
