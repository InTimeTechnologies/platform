#include "JoystickInput.h"

// Dependencies | std
#include <cassert>

namespace it {
	namespace platform {
		// class JoystickInput
	
		// Object | public
	
		// Getters
		const std::vector<Joystick>& JoystickInput::getJoysticks() const {
			return joysticks;
		}
		Joystick& JoystickInput::getJoystick(JoystickCode joystickCode) {
			size_t i = static_cast<size_t>(joystickCode);
			assert(i < joysticks.size() && "joystickCode is not present.");
			return joysticks[i];
		}

		// Object | private
	
		// Functions
		void JoystickInput::reset() {
			for (size_t i = 0; i < joysticks.size(); i++)
				joysticks[i].reset();
		}
		void JoystickInput::resetTransientStates() {
			for (size_t i = 0; i < joysticks.size(); i++)
				joysticks[i].resetTransientState();
		}
	}
}
