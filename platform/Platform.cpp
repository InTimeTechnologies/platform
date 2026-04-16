#include <Platform.h>

// Dependencies | std
#include <cassert>
#include <list>
#include <utility>

// Dependencies | glfw
#include <GLFW/glfw3.h>

// Dependencies | t::platform
#include "event/Event.h"

namespace it {
	namespace platform {
		// class Platform

		// Static | private

		// Properties
		Platform* Platform::s_singleton{ nullptr };

		// Static | public

		// Getters
		Platform* Platform::s_getSingleton() {
			return s_singleton;
		}

		// Object | public
		
		// Constructor / Destructor
		Platform::Platform() {
			assert(s_singleton == nullptr && "s_singleton != nullptr");
			s_singleton = this;
		}
		Platform::~Platform() {
			assert(s_singleton == this && "s_singleton != this");
			s_singleton = nullptr;

			#if defined(WINDOW)
			clearWindowEvents();
			#endif
		}
	
		// Getters
		bool Platform::getIsInit() const {
			return isInit;
		}

		// Object | protected

		// Functions
		#if defined(WINDOW)
		void Platform::clearWindowEvents() {
			for (std::pair<Window*, Event*>& windowEvent : windowEventList)
				delete windowEvent.second;
			windowEventList.clear();
		}
		#endif
	}
}
