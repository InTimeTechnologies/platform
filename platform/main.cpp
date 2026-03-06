// Dependencies | std
#include <iostream>
#include <chrono>
#include <thread>

// Dependencies | it
#include "backend/glfw/PlatformBackendGLFW.h"
#include "backend/glfw/WindowBackendGLFW.h"

#include "Platform.h"
#include "window/Window.h"

void print(const it::Window& window) {
	std::cout << "title: " << window.getTitle() << std::endl;
	std::cout << "x: " << window.getX() << ", y: " << window.getY() << ", width: " << window.getWidth() << ", height: " << window.getHeight() << std::endl;
	std::cout << "visible: " << window.getVisible() << std::endl;
	std::cout << "resizable: " << window.getResizeable() << std::endl;
	std::cout << "focused: " << window.getFocused() << std::endl;
}

int testWindowing() {
	// Platform
	std::cout << "Creating platform." << std::endl;
	it::PlatformBackendGLFW platformBackendGLFW{};
	it::Platform platform{platformBackendGLFW};
	bool platformInitiated = platform.init();
	if (!platformInitiated) {
		std::cout << "Error: Failed to initiate platform." << std::endl;
		return 1;
	}

	// Window
	std::cout << "Creating window." << std::endl;
	it::WindowBackendGLFW windowBackendGLFW{};
	it::Window window{ windowBackendGLFW };
	bool windowCreated = window.create();
	std::cout << "test" << std::endl;
	if (!windowCreated) {
		std::cout << "Error: Failed to create window." << std::endl;
		return 2;
	}
	window.setVisible(true);

	// Setup
	std::cout << window.getContextMajorVersion() << ":" << window.getContextMinorVersion() << ":" << window.getContextRevision() << std::endl;
	
	// Loop
	std::cout << "Running loop." << std::endl;
	std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();
	std::chrono::steady_clock::time_point currentTime = startTime;
	std::chrono::steady_clock::time_point stopTime = startTime + std::chrono::seconds(10);
	std::chrono::nanoseconds sleepTime = std::chrono::milliseconds(16);
	while (currentTime < stopTime) {
		platform.update();
		window.makeContextCurrent();
		window.swapBuffers();
		//print(window);

		if (platform.keyboardInput.getKey(it::KeyCode::ENTER).justPressed)
			window.setSize(500, 500);

		const it::Key& quitKey = platform.keyboardInput.getKey(it::KeyCode::ESCAPE);
		if (quitKey.justPressed)
			return 0;

		std::this_thread::sleep_for(sleepTime);
		currentTime = std::chrono::steady_clock::now();
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
