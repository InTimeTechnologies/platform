// Dependencies | std
#include <iostream>
#include <chrono>
#include <thread>

// Dependencies it::platform
#include "Platform.h"
#include "window/Window.h"
#include "keyboard/to_string.h"
#include "gamepad/GamepadInput.h"

void print(const it::platform::Window& window) {
	std::cout << "title: " << window.getTitle() << std::endl;
	std::cout << "x: " << window.getX() << ", y: " << window.getY() << ", width: " << window.getWidth() << ", height: " << window.getHeight() << std::endl;
	std::cout << "visible: " << window.getVisible() << std::endl;
	std::cout << "resizable: " << window.getResizable() << std::endl;
	std::cout << "focused: " << window.getFocused() << std::endl;
}

void testGamepad(it::platform::Platform& platform) {
	it::platform::Gamepad& gamepad = platform.gamepadInput.getGamepad(it::platform::GamepadCode::GAMEPAD_0);
	if (gamepad.getButtonA().pressed) {
		std::cout << "pressed" << std::endl;
	}
	else {
		std::cout << "released" << std::endl;
	}
}

int testWindowing() {
	// Platform
	std::cout << "Creating platform." << std::endl;
	it::platform::Platform platform{};
	bool platformInitiated = platform.init();
	if (!platformInitiated) {
		std::cout << "Error: Failed to initiate platform." << std::endl;
		return 1;
	}

	// Window
	std::cout << "Creating window." << std::endl;
	it::platform::Window& window = platform.windowManager.windowList.emplace_back();
	bool windowCreated = window.create();
	if (!windowCreated) {
		std::cout << "Error: Failed to create window." << std::endl;
		return 2;
	}
	window.setVisible(true);

	// Setup
	bool exit = false;
	window.onClose = [&exit]() { exit = true; };
	
	// Loop
	std::cout << "Running loop." << std::endl;
	while (!exit) {
		platform.update();
		window.makeContextCurrent();
		window.swapBuffers();

		testGamepad(platform);

		for (const it::platform::KeyEvent& keyEvent : window.getKeyEventList()) {

			if (keyEvent.keyCode == it::platform::KeyCode::ENTER && keyEvent.action == it::platform::KeyAction::PRESS)
				window.setSize(500, 500);
	
			if (keyEvent.keyCode == it::platform::KeyCode::ESCAPE && keyEvent.action == it::platform::KeyAction::PRESS)
				exit = true;
		}
	}
	std::cout << "Terminated loop." << std::endl;

	return 0;
}

int main(int argc, char* argv[]) {
	std::cout << "Program operating." << std::endl;
	int errorCode = 0;

	errorCode = testWindowing();

	std::cout << "Program terminating." << std::endl;
	return errorCode;
}
