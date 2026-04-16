#pragma once

// Dependencies | std
#include <string>

namespace it {
	namespace platform {
		struct Monitor {
			// Properties
			void* backendHandle{ nullptr };
			std::string name{};
			int width{ 0 };
			int height{ 0 };
		};
	}
}
