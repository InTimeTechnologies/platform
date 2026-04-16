#pragma once

// Dependencies | std
#include <vector>
#include <string>

// Dependencies | it::platform
#include "EventType.h"
#include <keyboard/KeyCode.h>
#include <keyboard/KeyAction.h>
#include <mouse/MouseButtonCode.h>
#include <mouse/MouseButtonAction.h>
#include <joystick/JoystickCode.h>

namespace it {
	namespace platform {
		// Forward declarations
		class Window;

		struct Event {
			// Constructor / Destructor
			Event() = default;
			Event(const Event& other) = default;
			Event(Event&& other) noexcept = default;
			virtual ~Event() = default;

			// Operators | assignment
			Event& operator=(const Event& other) = default;
			Event& operator=(Event&& other) noexcept = default;

			// Functions
			virtual EventType getType() const = 0;
		};

		struct WindowPositionEvent : public Event {
			// Properties
			int x{ -1 };
			int y{ -1 };

			// Constructor / Destructor
			WindowPositionEvent() = default;
			WindowPositionEvent(int x, int y);
			WindowPositionEvent(const WindowPositionEvent& other) = default;
			WindowPositionEvent(WindowPositionEvent&& other) noexcept = default;

			// Operators | assignment
			WindowPositionEvent& operator=(const WindowPositionEvent& other) = default;
			WindowPositionEvent& operator=(WindowPositionEvent&& other) noexcept = default;

			// Functions
			virtual EventType getType() const override;
		};

		struct WindowSizeEvent : public Event {
			// Properties
			int width{ -1 };
			int height{ -1 };

			// Constructor / Destructor
			WindowSizeEvent() = default;
			WindowSizeEvent(int width, int height);
			WindowSizeEvent(const WindowSizeEvent& other) = default;
			WindowSizeEvent(WindowSizeEvent&& other) noexcept = default;

			// Operators | assignment
			WindowSizeEvent& operator=(const WindowSizeEvent& other) = default;
			WindowSizeEvent& operator=(WindowSizeEvent&& other) noexcept = default;

			// Functions
			virtual EventType getType() const override;
		};

		struct WindowCloseEvent : public Event {
			// Properties

			// Functions
			virtual EventType getType() const override;
		};

		struct WindowFocusEvent : public Event {
			// Properties
			bool focused{ false };

			// Constructor / Destructor
			WindowFocusEvent() = default;
			WindowFocusEvent(bool focused);
			WindowFocusEvent(const WindowFocusEvent& other) = default;
			WindowFocusEvent(WindowFocusEvent&& other) noexcept = default;

			// Operators | assignment
			WindowFocusEvent& operator=(const WindowFocusEvent& other) = default;
			WindowFocusEvent& operator=(WindowFocusEvent&& other) noexcept = default;

			// Functions
			virtual EventType getType() const override;
		};

		struct WindowIconifyEvent : public Event {
			// Properties
			bool iconified{ false };

			// Constructor / Destructor
			WindowIconifyEvent() = default;
			WindowIconifyEvent(bool iconified);
			WindowIconifyEvent(const WindowIconifyEvent& other) = default;
			WindowIconifyEvent(WindowIconifyEvent&& other) noexcept = default;

			// Operators | assignment
			WindowIconifyEvent& operator=(const WindowIconifyEvent& other) = default;
			WindowIconifyEvent& operator=(WindowIconifyEvent&& other) noexcept = default;

			// Functions
			virtual EventType getType() const override;
		};

		struct WindowRefreshEvent : public Event {
			// Properties

			// Functions
			virtual EventType getType() const override;
		};

		struct WindowMaximizeEvent : public Event {
			// Properties
			bool maximized{ false };

			// Constructor / Destructor
			WindowMaximizeEvent() = default;
			WindowMaximizeEvent(bool maximized);
			WindowMaximizeEvent(const WindowMaximizeEvent& other) = default;
			WindowMaximizeEvent(WindowMaximizeEvent&& other) noexcept = default;

			// Operators | assignment
			WindowMaximizeEvent& operator=(const WindowMaximizeEvent& other) = default;
			WindowMaximizeEvent& operator=(WindowMaximizeEvent&& other) noexcept = default;

			// Functions
			virtual EventType getType() const override;
		};

		struct WindowContentScaleEvent : public Event {
			// Properties
			float xScale{ 1.0f };
			float yScale{ 1.0f };

			// Constructor / Destructor
			WindowContentScaleEvent() = default;
			WindowContentScaleEvent(float xScale, float yScale);
			WindowContentScaleEvent(const WindowContentScaleEvent& other) = default;
			WindowContentScaleEvent(WindowContentScaleEvent&& other) noexcept = default;

			// Operators | assignment
			WindowContentScaleEvent& operator=(const WindowContentScaleEvent& other) = default;
			WindowContentScaleEvent& operator=(WindowContentScaleEvent&& other) noexcept = default;

			// Functions
			virtual EventType getType() const override;
		};

		struct WindowFrameBufferSizeEvent : public Event {
			// Properties
			int width{ 0 };
			int height{ 0 };

			// Constructor / Destructor
			WindowFrameBufferSizeEvent() = default;
			WindowFrameBufferSizeEvent(int width, int height);
			WindowFrameBufferSizeEvent(const WindowFrameBufferSizeEvent& other) = default;
			WindowFrameBufferSizeEvent(WindowFrameBufferSizeEvent&& other) noexcept = default;

			// Operators | assignment
			WindowFrameBufferSizeEvent& operator=(const WindowFrameBufferSizeEvent& other) = default;
			WindowFrameBufferSizeEvent& operator=(WindowFrameBufferSizeEvent&& other) noexcept = default;

			// Functions
			virtual EventType getType() const override;
		};

		struct WindowPathDropEvent : public Event {
			// Properties
			std::vector<std::string> paths{};

			// Constructor / Destructor
			WindowPathDropEvent() = default;
			WindowPathDropEvent(const std::vector<std::string>& paths);
			WindowPathDropEvent(const WindowPathDropEvent& other) = default;
			WindowPathDropEvent(WindowPathDropEvent&& other) noexcept = default;

			// Operators | assignment
			WindowPathDropEvent& operator=(const WindowPathDropEvent& other) = default;
			WindowPathDropEvent& operator=(WindowPathDropEvent&& other) noexcept = default;

			// Functions
			virtual EventType getType() const override;
		};

		struct MouseButtonEvent : public Event {
			// Properties
			MouseButtonCode code{ MouseButtonCode::UNKNOWN };
			MouseButtonAction action{ MouseButtonAction::UNKNOWN };
			int modifiers{ 0 };

			// Constructor / Destructor
			MouseButtonEvent() = default;
			MouseButtonEvent(MouseButtonCode code, MouseButtonAction action, int modifiers);
			MouseButtonEvent(const MouseButtonEvent& other) = default;
			MouseButtonEvent(MouseButtonEvent&& other) noexcept = default;

			// Operators | assignment
			MouseButtonEvent& operator=(const MouseButtonEvent& other) = default;
			MouseButtonEvent& operator=(MouseButtonEvent&& other) noexcept = default;

			// Functions
			virtual EventType getType() const override;
		};

		struct MousePositionEvent : public Event {
			// Properties
			int x{ -1 };
			int y{ -1 };

			// Constructor / Destructor
			MousePositionEvent() = default;
			MousePositionEvent(int x, int y);
			MousePositionEvent(const MousePositionEvent& other) = default;
			MousePositionEvent(MousePositionEvent&& other) noexcept = default;

			// Operators | assignment
			MousePositionEvent& operator=(const MousePositionEvent& other) = default;
			MousePositionEvent& operator=(MousePositionEvent&& other) noexcept = default;

			// Functions
			virtual EventType getType() const override;
		};

		struct MouseEnterEvent : public Event {
			// Properties
			bool entered{ false };

			// Constructor / Destructor
			MouseEnterEvent() = default;
			MouseEnterEvent(bool entered);
			MouseEnterEvent(const MouseEnterEvent& other) = default;
			MouseEnterEvent(MouseEnterEvent&& other) noexcept = default;

			// Operators | assignment
			MouseEnterEvent& operator=(const MouseEnterEvent& other) = default;
			MouseEnterEvent& operator=(MouseEnterEvent&& other) noexcept = default;

			// Functions
			virtual EventType getType() const override;
		};

		struct MouseScrollEvent : public Event {
			// Properties
			double xScroll{ 0.0 };
			double yScroll{ 0.0 };

			// Constructor / Destructor
			MouseScrollEvent() = default;
			MouseScrollEvent(double xScroll, double yScroll);
			MouseScrollEvent(const MouseScrollEvent& other) = default;
			MouseScrollEvent(MouseScrollEvent&& other) noexcept = default;

			// Operators | assignment
			MouseScrollEvent& operator=(const MouseScrollEvent& other) = default;
			MouseScrollEvent& operator=(MouseScrollEvent&& other) noexcept = default;

			// Functions
			virtual EventType getType() const override;
		};

		struct KeyEvent : public Event {
			// Properties
			KeyCode code{ KeyCode::UNKNOWN };
			int scanCode{ -1 };
			KeyAction action{ KeyAction::UNKNOWN };
			int modifiers{ -1 };

			// Constructor / Destructor
			KeyEvent() = default;
			KeyEvent(KeyCode code, int scanCode, KeyAction action, int modifiers);
			KeyEvent(const KeyEvent& other) = default;
			KeyEvent(KeyEvent&& other) noexcept = default;

			// Operators | assignment
			KeyEvent& operator=(const KeyEvent& other) = default;
			KeyEvent& operator=(KeyEvent&& other) noexcept = default;

			// Functions
			virtual EventType getType() const override;
		};

		struct KeyCharEvent : public Event {
			// Properties
			unsigned int codePoint{ 0u };

			// Constructor / Destructor
			KeyCharEvent() = default;
			KeyCharEvent(unsigned int codePoint);
			KeyCharEvent(const KeyCharEvent& other) = default;
			KeyCharEvent(KeyCharEvent&& other) noexcept = default;

			// Operators | assignment
			KeyCharEvent& operator=(const KeyCharEvent& other) = default;
			KeyCharEvent& operator=(KeyCharEvent&& other) noexcept = default;

			// Functions
			virtual EventType getType() const override;
		};

		struct KeyCharWithModifiersEvent : public Event {
			// Properties
			unsigned int codePoint{ 0u };
			int modifiers{ 0 };

			// Constructor / Destructor
			KeyCharWithModifiersEvent() = default;
			KeyCharWithModifiersEvent(unsigned int codePoint, int modifiers);
			KeyCharWithModifiersEvent(const KeyCharWithModifiersEvent& other) = default;
			KeyCharWithModifiersEvent(KeyCharWithModifiersEvent&& other) noexcept = default;

			// Operators | assignment
			KeyCharWithModifiersEvent& operator=(const KeyCharWithModifiersEvent& other) = default;
			KeyCharWithModifiersEvent& operator=(KeyCharWithModifiersEvent&& other) noexcept = default;

			// Functions
			virtual EventType getType() const override;
		};

		struct JoystickConnectionEvent : public Event {
			// Properties
			JoystickCode code{ JoystickCode::UNKNOWN };
			bool connected{ false };

			// Constructor / Destructor
			JoystickConnectionEvent() = default;
			JoystickConnectionEvent(JoystickCode code, bool connected);
			JoystickConnectionEvent(const JoystickConnectionEvent& other) = default;
			JoystickConnectionEvent(JoystickConnectionEvent&& other) noexcept = default;

			// Operators | assignment
			JoystickConnectionEvent& operator=(const JoystickConnectionEvent& other) = default;
			JoystickConnectionEvent& operator=(JoystickConnectionEvent&& other) noexcept = default;

			// Functions
			virtual EventType getType() const override;
		};

		struct PlatformBackendErrorEvent : public Event {
			// Properties
			std::string description{};

			// Constructor / Destructor
			PlatformBackendErrorEvent() = default;
			PlatformBackendErrorEvent(const std::string& description);
			PlatformBackendErrorEvent(const PlatformBackendErrorEvent& other) = default;
			PlatformBackendErrorEvent(PlatformBackendErrorEvent&& other) noexcept = default;

			// Operators | assignment
			PlatformBackendErrorEvent& operator=(const PlatformBackendErrorEvent& other) = default;
			PlatformBackendErrorEvent& operator=(PlatformBackendErrorEvent&& other) noexcept = default;

			// Functions
			virtual EventType getType() const override;
		};

		struct MonitorConnectionEvent : public Event {
			// Properties
			bool connected{ false };

			// Constructor / Destructor
			MonitorConnectionEvent() = default;
			MonitorConnectionEvent(bool connected);
			MonitorConnectionEvent(const MonitorConnectionEvent& other) = default;
			MonitorConnectionEvent(MonitorConnectionEvent&& other) noexcept = default;

			// Operators | assignment
			MonitorConnectionEvent& operator=(const MonitorConnectionEvent& other) = default;
			MonitorConnectionEvent& operator=(MonitorConnectionEvent&& other) noexcept = default;

			// Functions
			virtual EventType getType() const override;
		};
	}
}
