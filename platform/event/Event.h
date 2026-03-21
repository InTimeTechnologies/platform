#pragma once

// Dependencies | it::platform
#include "EventType.h"
#include <keyboard/KeyCode.h>
#include <keyboard/KeyAction.h>
#include <mouse/MouseButtonCode.h>
#include <mouse/MouseButtonAction.h>

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

		struct MoveEvent : public Event {
			// Properties
			int x{ -1 };
			int y{ -1 };

			// Functions
			virtual EventType getType() const override;
		};

		struct ResizeEvent : public Event {
			// Properties
			int width{ -1 };
			int height{ -1 };

			// Functions
			virtual EventType getType() const override;
		};

		struct WindowCloseEvent : public Event {
			// Functions
			virtual EventType getType() const override;
		};

		struct FocusEvent : public Event {
			// Properties
			bool focused{ false };

			// Functions
			virtual EventType getType() const override;
		};

		struct IconifyEvent : public Event {
			// Properties
			bool iconified{ false };

			// Functions
			virtual EventType getType() const override;
		};

		struct RefreshEvent : public Event {
			// Functions
			virtual EventType getType() const override;
		};

		struct WindowMaximizeEvent : public Event {
			// Properties
			bool maximize{ false };

			// Functions
			virtual EventType getType() const override;
		};

		struct ContentScaleEvent : public Event {
			// Functions
			virtual EventType getType() const override;
		};

		struct KeyEvent : public Event {
			// Properties
			KeyCode keyCode{ KeyCode::UNKNOWN };
			int scanCode{ -1 };
			KeyAction action{ KeyAction::UNKNOWN };
			int modifiers{ -1 };

			// Functions
			virtual EventType getType() const override;
		};

		struct MouseButtonEvent : public Event {
			// Properties
			MouseButtonCode code{ MouseButtonCode::UNKNOWN };
			MouseButtonAction action{ MouseButtonAction::UNKNOWN };

			// Functions
			virtual EventType getType() const override;
		};

		struct MousePositionEvent : public Event {
			// Properties
			int x{ -1 };
			int y{ -1 };

			// Functions
			virtual EventType getType() const override;
		};
	}
}
