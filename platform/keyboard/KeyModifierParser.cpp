#include "KeyModifierParser.h"

namespace it {
	namespace platform {
		// struct KeyModifierParser

		// Object | public

		// Functions
		bool KeyModifierParser::shiftPressed(int modifiers) const {
			return static_cast<bool>(shift & modifiers);
		}
		bool KeyModifierParser::controlPressed(int modifiers) const {
			return static_cast<bool>(control & modifiers);
		}
		bool KeyModifierParser::altPressed(int modifiers) const {
			return static_cast<bool>(alt & modifiers);
		}
		bool KeyModifierParser::superPressed(int modifiers) const {
			return static_cast<bool>(super & modifiers);
		}
		bool KeyModifierParser::capsLockPressed(int modifiers) const {
			return static_cast<bool>(capsLock & modifiers);
		}
		bool KeyModifierParser::numLockPressed(int modifiers) const {
			return static_cast<bool>(numLock & modifiers);
		}
	}
}

// Backup
/*
		// Constructor / Destructor
		KeyModifierParser::KeyModifierParser(int shift, int control, int alt, int super, int capsLock, int numLock) : shift(shift), control(control), alt(alt), super(super), capsLock(capsLock), numLock(numLock) {

		}

		// Getters
		int KeyModifierParser::getShift() const {
			return shift;
		}
		int KeyModifierParser::getControl() const {
			return control;
		}
		int KeyModifierParser::getAlt() const {
			return alt;
		}
		int KeyModifierParser::getSuper() const {
			return super;
		}
		int KeyModifierParser::getCapsLock() const {
			return capsLock;
		}
		int KeyModifierParser::getNumLock() const {
			return numLock;
		}
*/
