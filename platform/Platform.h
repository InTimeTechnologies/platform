#pragma once

// Dependencies | it
#include "mouse/MouseInput.h"
#include "keyboard/KeyboardInput.h"
//#include "joystick/JoystickInput.h"
#include "PlatformImplementation.h"

namespace it {
	class Platform {
		// Object
		private:
			// Properties
			bool isInit{ false };
			PlatformImplementation& platformImplementation;
			
		public:
			// Properties
			MouseInput mouseInput{};
			KeyboardInput keyboardInput{};
			
			// Constructor / Destructor
			Platform() = delete;
			Platform(PlatformImplementation& platformImplementation);
			Platform(const Platform& other) = delete;
			Platform(Platform&& other) noexcept = delete;
			~Platform();

			// Operators | assignment
			Platform& operator=(const Platform& other) = delete;
			Platform& operator=(Platform&& other) noexcept = delete;

			// Getters
			PlatformImplementation& getPlatformBackend() const;
			bool getIsInit() const;

			// Functions
			bool init();
			void deinit();
			void update();
	};
}
