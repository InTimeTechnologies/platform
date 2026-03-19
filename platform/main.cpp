// Dependencies | std
#include <iostream>
#include <chrono>
#include <thread>

// Dependencies it::platform
#include "Platform.h"
#include "joystick/JoystickButtonCode.h"

void print(const it::platform::Window& window) {
	std::cout << "title: " << window.getTitle() << std::endl;
	std::cout << "x: " << window.getX() << ", y: " << window.getY() << ", width: " << window.getWidth() << ", height: " << window.getHeight() << std::endl;
	std::cout << "visible: " << window.getVisible() << std::endl;
	std::cout << "resizable: " << window.getResizable() << std::endl;
	std::cout << "focused: " << window.getFocused() << std::endl;
}

void testGamepad(it::platform::Platform& platform) {
	const it::platform::Joystick& joystick = platform.joystickInput.getJoystick(it::platform::JoystickCode::JOYSTICK_0);
	bool justPressedA = joystick.getButton(it::platform::JoystickButtonCode::A).justPressed;
	if (justPressedA)
		std::cout << "just pressed A" << std::endl;
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
	it::platform::Joystick& joystick = platform.joystickInput.getJoystick(it::platform::JoystickCode::JOYSTICK_0);
	joystick.onConnection = [&joystick](bool connected) {
		std::string message = connected ? "connected" : "disconnected";
		std::cout << message + ": " + joystick.getName() << std::endl;
	};
	
	// Loop
	std::cout << "Running loop." << std::endl;
	while (!exit) {
		platform.update();
		window.makeContextCurrent();
		window.swapBuffers();

		testGamepad(platform);

		//for (const it::platform::KeyEvent& keyEvent : window.getKeyEventList()) {
		//	if (keyEvent.keyCode == it::platform::KeyCode::ENTER && keyEvent.action == it::platform::KeyAction::PRESS)
		//		window.setSize(500, 500);
		//	if (keyEvent.keyCode == it::platform::KeyCode::ESCAPE && keyEvent.action == it::platform::KeyAction::PRESS)
		//		exit = true;
		//}
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
