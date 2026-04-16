#include "Event.h"

namespace it {
	namespace platform {
		// struct WindowPositionEvent
	
		// Constructor / Destructor
		WindowPositionEvent::WindowPositionEvent(int x, int y) : Event(), x(x), y(y) {

		}

		// Functions | Event
		EventType WindowPositionEvent::getType() const {
			return EventType::WINDOW_POSITION;
		}

		// struct WindowSizeEvent

		// Constructor / Destructor
		WindowSizeEvent::WindowSizeEvent(int width, int height) : Event(), width(width), height(height) {

		}

		// Functions
		EventType WindowSizeEvent::getType() const {
			return EventType::WINDOW_SIZE;
		}

		// struct WindowCloseEvent

		// Functions
		EventType WindowCloseEvent::getType() const {
			return EventType::WINDOW_CLOSE;
		}

		// struct WindowFocusEvent

		// Constructor / Destructor
		WindowFocusEvent::WindowFocusEvent(bool focused) : Event(), focused(focused) {

		}

		// Functions
		EventType WindowFocusEvent::getType() const {
			return EventType::WINDOW_FOCUS;
		}

		// struct WindowIconifyEvent

		// Constructor / Destructor
		WindowIconifyEvent::WindowIconifyEvent(bool iconified) : Event(), iconified(iconified) {

		}

		// Functions
		EventType WindowIconifyEvent::getType() const {
			return EventType::WINDOW_ICONIFY;
		}
		
		// struct WindowRefreshEvent

		// Functions
		EventType WindowRefreshEvent::getType() const {
			return EventType::WINDOW_REFRESH;
		}

		// struct WindowMaximizeEvent

		// Constructor / Destructor
		WindowMaximizeEvent::WindowMaximizeEvent(bool maximized) : Event(), maximized(maximized) {

		}

		// Functions
		EventType WindowMaximizeEvent::getType() const {
			return EventType::WINDOW_MAXIMIZE;
		}

		// struct WindowContentScaleEvent

		// Constructor / Destructor
		WindowContentScaleEvent::WindowContentScaleEvent(float xScale, float yScale) : Event(), xScale(xScale), yScale(yScale) {

		}

		// Functions
		EventType WindowContentScaleEvent::getType() const {
			return EventType::WINDOW_CONTENT_SCALE;
		}

		// struct WindowFrameBufferSizeEvent

		// Constructor / Destructor
		WindowFrameBufferSizeEvent::WindowFrameBufferSizeEvent(int width, int height) : Event(), width(width), height(height) {

		}

		// Functions
		EventType WindowFrameBufferSizeEvent::getType() const {
			return EventType::WINDOW_FRAME_BUFFER_SIZE;
		}

		// struct WindowPathDropEvent

		// Constructor / Destructor
		WindowPathDropEvent::WindowPathDropEvent(const std::vector<std::string>& paths) : Event(), paths(paths) {

		}

		// Functions
		EventType WindowPathDropEvent::getType() const {
			return EventType::WINDOW_PATH_DROP;
		}

		// struct MouseButtonEvent

		// Constructor / Destructor
		MouseButtonEvent::MouseButtonEvent(MouseButtonCode code, MouseButtonAction action, int modifiers) : Event(), code(code), action(action), modifiers(modifiers) {

		}

		// Functions
		EventType JoystickConnectionEvent::getType() const {
			return EventType::JOYSTICK_CONNECTION_EVENT;
		}

		// Functions
		EventType MouseButtonEvent::getType() const {
			return EventType::MOUSE_BUTTON;
		}

		// struct MousePositionEvent

		// Constructor / Destructor
		MousePositionEvent::MousePositionEvent(int x, int y) : Event(), x(x), y(y) {
			
		}

		// Functions
		EventType MousePositionEvent::getType() const {
			return EventType::MOUSE_POSITION;
		}

		// struct MouseEnterEvent

		// Constructor / Destructor
		MouseEnterEvent::MouseEnterEvent(bool entered) : Event(), entered(entered) {

		}

		// struct MouseScrollEvent

		// Constructor / Destructor
		MouseScrollEvent::MouseScrollEvent(double xScroll, double yScroll) : Event(), xScroll(xScroll), yScroll(yScroll) {

		}

		// Functions
		EventType MouseScrollEvent::getType() const {
			return EventType::MOUSE_SCROLL_EVENT;
		}

		// Functions
		EventType MouseEnterEvent::getType() const {
			return EventType::MOUSE_ENTER;
		}

		// struct JoystickConnectionEvent

		// Constructor / Destructor
		JoystickConnectionEvent::JoystickConnectionEvent(JoystickCode code, bool connected) : Event(), code(code), connected(connected) {

		}

		// struct KeyEvent

		// Constructor / Destructor
		KeyEvent::KeyEvent(KeyCode code, int scanCode, KeyAction action, int modifiers) : Event(), code(code), scanCode(scanCode), action(action), modifiers(modifiers) {
			
		}

		// Functions
		EventType KeyEvent::getType() const {
			return EventType::KEY;
		}

		// struct KeyCharEvent

		// Constructor / Destructor
		KeyCharEvent::KeyCharEvent(unsigned int codePoint) : Event(), codePoint(codePoint) {

		}

		// Functions
		EventType KeyCharEvent::getType() const {
			return EventType::KEY_CHAR;
		}

		// struct KeyCharWithModifiersEvent

		// Constructor / Destructor
		KeyCharWithModifiersEvent::KeyCharWithModifiersEvent(unsigned int codePoint, int modifiers) : Event(), codePoint(codePoint), modifiers(modifiers) {

		}

		// Functions
		EventType KeyCharWithModifiersEvent::getType() const {
			return EventType::KEY_CHAR_WITH_MODIFIERS;
		}

		// struct PlatformBackendErrorEvent

		// Constructor / Destructor
		PlatformBackendErrorEvent::PlatformBackendErrorEvent(const std::string& description) : Event(), description(description) {

		}

		// Functions
		EventType PlatformBackendErrorEvent::getType() const {
			return EventType::PLATFORM_BACKEND_ERROR;
		}

		// struct MonitorConnectionEvent

		// Constructor / Destructor
		MonitorConnectionEvent::MonitorConnectionEvent(bool connected) : Event(), connected(connected) {

		}

		// Functions
		EventType MonitorConnectionEvent::getType() const {
			return EventType::MONITOR_CONNECTION;
		}

	}
}
