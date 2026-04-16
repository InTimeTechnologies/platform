#pragma once

namespace it {
	namespace platform {
		enum class EventType {
			// Unknown
			UNKNOWN = -1,

			// Window events
			WINDOW_POSITION,
			WINDOW_SIZE,
			WINDOW_CLOSE,
			WINDOW_FOCUS,
			WINDOW_ICONIFY,
			WINDOW_REFRESH,
			WINDOW_MAXIMIZE,
			WINDOW_CONTENT_SCALE,
			WINDOW_FRAME_BUFFER_SIZE,
			WINDOW_PATH_DROP,

			// Mouse events
			MOUSE_BUTTON,
			MOUSE_POSITION,
			MOUSE_ENTER,
			MOUSE_SCROLL_EVENT,

			// Keyboard events
			KEY,
			KEY_CHAR,
			KEY_CHAR_WITH_MODIFIERS,

			// Monitor
			MONITOR_CONNECTION,

			// Joystick events
			JOYSTICK_CONNECTION_EVENT,

			// Platform bacend events
			PLATFORM_BACKEND_ERROR
		};
	}
}
