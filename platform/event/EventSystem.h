#pragma once

// Dependencies | std
#include <list>

// Dependencies | it::platform
#include "Event.h"

namespace it  {
    namespace platform {
        class EventSystem {
            // Friends
            friend class Platform;

            // Object
            private:
                // Properties
                std::list<Event*> eventList{};

            public:
                // Constructor / Destructor
                EventSystem() = default;
                EventSystem(const EventSystem& other) = delete;
                EventSystem(EventSystem&& other) noexcept = delete;

                // Operators | assignment
                EventSystem& operator=(const EventSystem& other) = delete;
                EventSystem& operator=(EventSystem&& other) noexcept = delete;

                // Getters
                const std::list<Event*> getEventList() const;

                // Functions

            private:
                // Functions
                void feedEvent(Event* event);
        };
    }
}
