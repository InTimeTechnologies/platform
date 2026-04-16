#include "EventSystem.h"

// Dependencies | it::platform
#include <window/Window.h>

namespace it {
	namespace platform {
		// class EventSystem

		// Object | public

		// Getters
		const std::list<Event*>& EventSystem::getEventList() const {
		return eventList;
		}

		// Object | private

		// Functions
		void EventSystem::feedEvent(Event* event) {
		eventList.push_back(event);
		}
		void EventSystem::dispatchEvents() {

		}
		void EventSystem::dispatch(Event* event) {
			switch (event->getType()) {
				case EventType::WINDOW_POSITION:
				case EventType::WINDOW_SIZE:
				case EventType::WINDOW_CLOSE:
				case EventType::WINDOW_FOCUS:
				case EventType::WINDOW_ICONIFY:
				case EventType::WINDOW_REFRESH:
				case EventType::WINDOW_MAXIMIZE:
				case EventType::WINDOW_CONTENT_SCALE:
				case EventType::KEY:
				case EventType::MOUSE_BUTTON:
				case EventType::MOUSE_POSITION:
					{
						//MousePositionEvent* mousePositionEvent = static_cast<MousePositionEvent*>(event);
						//mousePositionEvent->window->processEvent(mousePositionEvent);
					}
				case EventType::UNKNOWN:
				default:
					break;
			}
		}
	}
}
