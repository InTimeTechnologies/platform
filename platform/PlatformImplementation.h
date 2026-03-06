#pragma once

// Dependencies | it
#include "mouse/MouseButton.h"
#include "keyboard/Key.h"

namespace it {
	// Forward declarations
	class Platform;

	class PlatformImplementation {
		// Friends
		friend class Platform;

		// Object
		protected:
			// Properties
			Platform* owner{ nullptr };
			bool isInit{ false };

		public:
			// Constructor / Destructor
			PlatformImplementation() = default;
			virtual ~PlatformImplementation() = default;

			// Getters
			virtual bool getIsInit() const = 0;

			// Functions
			virtual bool init() = 0;
			virtual void deinit() = 0;
			virtual void update() = 0;
	};

	class MouseEventForwarder {
		// Object
		public:
			// Properties
			bool mouseEventForwardingEnabled{ true };

			// Functions
			virtual void addMouseEvent(MouseButtonCode mouseButtonCode, MouseButton::Action mouseButtonAction) = 0;
	};

	class KeyboardEventForwarder {
		// Object
		public:
			// Properties
			bool keyboardEventForwardingEnabled{ true };

			// Functions
			virtual void addKeyEvent(KeyCode keycode, Key::Action keyAction) = 0;
	};

	class JoystickEventForwarder {
		// Object
		public:
			// Properties
			bool joystickEventForwardingEnabled{ true };

			// Functions
			virtual void addJoystickEvent() = 0;
	};
}
