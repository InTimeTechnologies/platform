#pragma once

// Dependencies | it
#include "../../PlatformImplementation.h"

namespace it {
	// Forward declarations | it
	class Platform;

	class PlatformBackendGLFW : public PlatformImplementation, public MouseEventForwarder, public KeyboardEventForwarder, public JoystickEventForwarder {
		// Static
		private:
			// Properties
			static PlatformBackendGLFW* s_singleton;

		public:
			// Getters
			static PlatformBackendGLFW* s_getSingleton();
		
		// Object
		public:
			// Constructor / Destructor
			PlatformBackendGLFW();
			virtual ~PlatformBackendGLFW();

			// Getters | PlatformImplementation
			bool getIsInit() const override;

			// Functions | PlatformImplementation
			bool init() override;
			void deinit() override;
			void update() override;

			// Functions | MouseEventForwarder
			void addMouseEvent(MouseButtonCode mouseButtonCode, MouseButton::Action mouseButtonAction) override;

			// Functions | KeyboardEventForwarder
			void addKeyEvent(KeyCode keycode, Key::Action keyAction) override;

			// Functions | JoystickEventForwarder
			void addJoystickEvent() override;
	};
}
