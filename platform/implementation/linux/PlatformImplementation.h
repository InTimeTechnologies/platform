#pragma once

// Dependencies | platform
#include <Platform.h>

namespace it {
	namespace platform {
		class PlatformImplementation : public Platform {
			// Object
			public:
				// Constructor / Destructor
				PlatformImplementation();
				PlatformImplementation(const PlatformImplementation& other) = delete;
				PlatformImplementation(PlatformImplementation&& other) noexcept = delete;
				virtual ~PlatformImplementation();

				// Operators | assignment
				PlatformImplementation& operator=(const PlatformImplementation& other) = delete;
				PlatformImplementation& operator=(PlatformImplementation&& other) = delete;

				// Functions (Platform)
				bool init() override;
				void deinit() override;
				void update() override;

				#if defined(WINDOW)
				Window& createWindow() override;
				void destroyWindow(Window& window) override;
				void updateMonitorList() override;
				#endif
		};
	}
}
