#include "Window.h"

// Dependencies | std
#include <cassert>

// Dependencies | it
#include "WindowImplementation.h"

namespace it {
	// class Window
	
	// Static | public
	
	// Properties
	std::string Window::s_defaultTitle{ "Title" };
	int Window::s_defaultX{ 0 };
	int Window::s_defaultY{ 0 };
	int Window::s_defaultWidth{ 800 };
	int Window::s_defaultHeight{ 600 };
	bool Window::s_defaultVisible{ true };
	bool Window::s_defaultResizable{ true };
	
	// Object | public

	// Constructor / Destructor
	Window::Window(WindowImplementation& windowImplementation) : windowImplementation(windowImplementation) {
    	windowImplementation.owner = this;
	}	
	// Operators | equality
	bool Window::operator==(const Window& other) const {
		return this == &other;
	}
	
	// Getters
	WindowImplementation& Window::getWindowImplementation() const {
		return windowImplementation;
	}
	std::string Window::getTitle() const {
		return windowImplementation.getTitle();
	}
	int Window::getX() const {
		return x;
	}
	int Window::getY() const {
		return y;
	}
	int Window::getWidth() const {
		return width;
	}
	int Window::getHeight() const {
		return height;
	}

	// Getters (window state)
	bool Window::getFocused() const {
		return focused;
	}
	bool Window::getIconified() const {
		return iconified;
	}
	bool Window::getMaximized() const {
		return maximized;
	}
	bool Window::getVisible() const {
		return visible;
	}
	bool Window::getHovered() const {
		return hovered;
	}

	// Getters (window property attributes)
	bool Window::getResizeable() const {
		return resizable;
	}
	bool Window::getDecorated() const {
		return decorated;
	}
	bool Window::getFloating() const {
		return floating;
	}
	bool Window::getAutoiconify() const {
		return autoiconify;
	}
	bool Window::getFocusOnShow() const {
		return focusOnShow;
	}
	bool Window::getMousePassthrough() const {
		return mousePassthrough;
	}
	bool Window::getTransparentFrameBuffer() const {
		return transparentFrameBuffer;
	}

	// Getters (context attributes OpenGL / OpenGL ES)
	std::string Window::getClientAPI() const {
		return clientAPI;
	}
	std::string Window::getContextCreationAPI() const {
		return contextCreationAPI;
	}
	std::string Window::getContextMajorVersion() const {
		return contextMajorVersion;
	}
	std::string Window::getContextMinorVersion() const {
		return contextMinorVersion;
	}
	std::string Window::getContextRevision() const {
		return contextRevision;
	}

	// Setters
	void Window::setTitle(const std::string& title) {
		windowImplementation.setTitle(title);
		this->title = title;
	}
	void Window::setPosition(int x, int y) {
		windowImplementation.setPosition(x, y);
		this->x = x;
		this->y = y;
	}
	void Window::setSize(int width, int height) {
		windowImplementation.setSize(width, height);
		this->width = width;
		this->height = height;
	}
	void Window::setVisible(bool visible) {
		windowImplementation.setVisible(visible);
		this->visible = visible;
	}
	void Window::setResizeable(bool resizable) {
		windowImplementation.setResizable(resizable);
		this->resizable = resizable;
	}
	
	// Functions
	bool Window::create() {
		return windowImplementation.create();
	}
	void Window::close() {
		windowImplementation.close();
	}
	bool Window::isCreated() const {
		return windowImplementation.isCreated();
	}
	void Window::makeContextCurrent() {
		windowImplementation.makeContextCurrent();
	}
	void Window::swapBuffers() {
		windowImplementation.swapBuffers();
	}
	void Window::synchWithBackend() {
		title = windowImplementation.getTitle();
		windowImplementation.getPosition(&x, &y);
		windowImplementation.getSize(&width, &height);
		visible = windowImplementation.getVisible();
		resizable = windowImplementation.getResizable();
	}

	// Feeders
	void Window::feedTitle(const std::string& title) {
		this->title = title;
	}
	void Window::feedPosition(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void Window::feedSize(int width, int height) {
		this->width = width;
		this->height = height;
	}
	void Window::feedVisible(bool visible) {
		this->visible = visible;
	}
	void Window::feedResizable(bool resizable) {
		this->resizable = resizable;
	}
	void Window::feedFocused(bool focused) {
		this->focused = focused;
	}
}
