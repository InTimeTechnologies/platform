#include "Platform.h"

// Dependencies | std
#include <cassert>

// Dependencies | it
#include "PlatformImplementation.h"

namespace it {
	// class Platform

	// Object | public

	// Constructor / Destructor
	Platform::Platform(PlatformImplementation& platformBackend) : platformImplementation(platformBackend) {
		platformBackend.owner = this;
	}
	Platform::~Platform() {
		platformImplementation.owner = nullptr;
	}

	// Getters
	PlatformImplementation& Platform::getPlatformBackend() const {
		return platformImplementation;
	}
	bool Platform::getIsInit() const {
		return isInit;
	}

	// Functions
	bool Platform::init() {
		isInit = platformImplementation.init();
		return isInit;
	}
	void Platform::deinit() {
		platformImplementation.deinit();
		isInit = false;
	}
	void Platform::update() {
		platformImplementation.update();
	}
}
