#pragma once

namespace it {
	namespace platform {
		class Window;
		class Event;

		struct EventEntry {
			Window* window{ nullptr };
			Event* event{ nullptr };
		};
	}
}
