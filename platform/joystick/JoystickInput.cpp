#include "JoystickInput.h"

// Dependencies | std
#include <cassert>

namespace it {
	namespace platform {
		// class JoystickInput
	
		// Object | public
	
		// Getters
		const std::vector<Joystick>& JoystickInput::getGamepads() const {
			return joysticks;
		}
		const Joystick& JoystickInput::getJoystick(JoystickCode joystickCode) const {
			size_t i = static_cast<size_t>(joystickCode);
			assert(i < joysticks.size() && "joystickCode is not present.");
			return joysticks[i];
		}
	
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
