// Dependencies | std
#include <iostream>
#include <chrono>
#include <thread>
#include <filesystem>

// Dependencies it::platform
#include "Platform.h"
#include "implementation/glfw/PlatformImplementation.h"

void print(const it::platform::Window& window) {
	std::cout << "title: " << window.getTitle() << std::endl;
	std::cout << "x: " << window.getX() << ", y: " << window.getY() << ", width: " << window.getWidth() << ", height: " << window.getHeight() << std::endl;
	std::cout << "visible: " << window.queryVisible() << std::endl;
	std::cout << "resizable: " << window.queryResizable() << std::endl;
	std::cout << "focused: " << window.queryFocused() << std::endl;
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
	it::platform::PlatformImplementation platformImplementation{};
	it::platform::Platform& platform = platformImplementation;
	bool platformInitiated = platform.init();
	if (!platformInitiated) {
		std::cout << "Error: Failed to initiate platform." << std::endl;
		return 1;
	}

	// Window
	std::cout << "Creating window." << std::endl;
	it::platform::Window& window = platform.createWindow();
	window.applyVisible(true);

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

		if (platform.keyboardInput.getKey(it::platform::KeyCode::ESCAPE).justPressed)
			exit = true;
		if (platform.keyboardInput.getKey(it::platform::KeyCode::ENTER).justPressed)
			window.setSize(500, 500);
		if (platform.keyboardInput.getKey(it::platform::KeyCode::ARROW_UP).pressed) {
			int currentWidth = window.getWidth();
			int currentHeight = window.getHeight();
			int newWidth = currentWidth;
			int newHeight = currentHeight + 1;
			window.setSize(newWidth, newHeight);
			std::cout << "Size: (" << window.getHeight() << ", " << window.getWidth() << ")" << std::endl;
		}
		if (platform.keyboardInput.getKey(it::platform::KeyCode::ARROW_DOWN).pressed) {
			int currentWidth = window.getWidth();
			int currentHeight = window.getHeight();
			int newWidth = currentWidth;
			int newHeight = currentHeight - 1;
			window.setSize(newWidth, newHeight);
			std::cout << "Size: (" << window.getHeight() << ", " << window.getWidth() << ")" << std::endl;
		}
		if (platform.keyboardInput.getKey(it::platform::KeyCode::ARROW_RIGHT).pressed) {
			int currentWidth = window.getWidth();
			int currentHeight = window.getHeight();
			int newWidth = currentWidth + 1;
			int newHeight = currentHeight;
			window.setSize(newWidth, newHeight);
			std::cout << "Size: (" << window.getHeight() << ", " << window.getWidth() << ")" << std::endl;
		}
		if (platform.keyboardInput.getKey(it::platform::KeyCode::ARROW_LEFT).pressed) {
			int currentWidth = window.getWidth();
			int currentHeight = window.getHeight();
			int newWidth = currentWidth - 1;
			int newHeight = currentHeight;
			window.setSize(newWidth, newHeight);
			std::cout << "Size: (" << window.getHeight() << ", " << window.getWidth() << ")" << std::endl;
		}
		
		// int keysPressedCount = platform.keyboardInput.getKeysPressedCount();
		// std::cout << "keysPressedCount: " << keysPressedCount << std::endl;
	}
	std::cout << "Terminated loop." << std::endl;

	return 0;
}

int main(int argc, char* argv[]) {
	std::cout << "Program operating." << std::endl;

	std::cout << "argc: " << argc << std::endl;
	for (size_t i = 0; i < static_cast<size_t>(argc); i++) {
		std::cout << "\t" << argv[i] << std::endl;
	}

	int errorCode = 0;
	errorCode = testWindowing();

	std::cout << "Program terminating." << std::endl;
	return errorCode;
}
