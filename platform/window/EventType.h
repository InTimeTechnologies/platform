#pragma once

namespace it {
	namespace platform {
		enum class EventType {
			UNKNOWN,

			MOVE,
			RESIZE,
			WINDOW_CLOSE,
			FOCUS,
			ICONIFY,
			REFRESH,
			WINDOW_MAXIMIZE,
			CONTENT_SCALE,

			KEY,

			MOUSE_BUTTON,
			MOUSE_POSITION
		};
	}
}
