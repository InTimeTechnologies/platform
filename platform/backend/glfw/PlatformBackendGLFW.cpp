#include "PlatformBackendGLFW.h"

// Dependencies | std
#include <cassert>

// Dependencies | glfw
#include <GLFW/glfw3.h>

// Dependencies | it
#include "../../Platform.h"
#include "../../mouse/MouseInput.h"
#include "../../keyboard/KeyboardInput.h"

namespace it {
	// class PlatformBackendGLFW

	// Static | private
	PlatformBackendGLFW* PlatformBackendGLFW::s_singleton{ nullptr };

	// Static | public

	// Functions
	PlatformBackendGLFW* PlatformBackendGLFW::s_getSingleton() {
		return s_singleton;
	}

	// Object | public

	// Constructor / Destructor
	PlatformBackendGLFW::PlatformBackendGLFW() {
		assert(s_singleton == nullptr && "singleton != nullptr");
		s_singleton = this;
	}
	PlatformBackendGLFW::~PlatformBackendGLFW() {
		deinit();
		s_singleton = nullptr;
	}

	// Getters | PlatformBackend
	bool PlatformBackendGLFW::getIsInit() const {
		return isInit;
	}

	// Functions | PlatformBackend
	bool PlatformBackendGLFW::init() {
		isInit = static_cast<bool>(glfwInit());
		return isInit;
	}
	void PlatformBackendGLFW::deinit() {
		if (isInit)
			glfwTerminate();
	}
	void PlatformBackendGLFW::update() {
		Platform* platform = owner;
		platform->mouseInput.resetTransientStates();
		platform->keyboardInput.resetTransientStates();
		glfwPollEvents();
	}

	// Functions | MouseEventForwarder
	void PlatformBackendGLFW::addMouseEvent(MouseButtonCode mouseButtonCode, MouseButton::Action mouseButtonAction) {
		if (mouseEventForwardingEnabled)
			owner->mouseInput.feedAction(mouseButtonCode, mouseButtonAction);
	}

	// Functions | KeyboardEventForwarder
	void PlatformBackendGLFW::addKeyEvent(KeyCode keyCode, Key::Action keyAction) {
		if (keyboardEventForwardingEnabled)
			owner->keyboardInput.feedAction(keyCode, keyAction);
	}

	// Functions | JoysticEventForwarder
	void PlatformBackendGLFW::addJoystickEvent() {

	}
}
