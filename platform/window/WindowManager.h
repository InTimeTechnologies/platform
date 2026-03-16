#pragma once

// Dependencies | std
#include <list>

// Dependencies | it::platform
#include "Window.h"

namespace it {
	namespace platform {
		class WindowManager {
			// Object
			public:
				// Properties
				std::list<Window> windowList{};

				// Constructor / Destructor
				WindowManager() = default;
				WindowManager(const WindowManager& other) = delete;
				WindowManager(WindowManager&& other) noexcept = delete;
				~WindowManager() = default;

				// Operators | assignment
				WindowManager& operator=(const WindowManager& other) = delete;
				WindowManager& operator=(WindowManager&& other) noexcept = delete;
		};
	}
}
