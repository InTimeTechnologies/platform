#pragma once

namespace it {
	namespace platform {
		struct KeyModifierParser {
			// Properties
			int shift{ 0 };
			int control{ 0 };
			int alt{ 0 };
			int super{ 0 };
			int capsLock{ 0 };
			int numLock{ 0 };

            // Functions
			bool shiftPressed(int modifiers) const;
			bool controlPressed(int modifiers) const;
			bool altPressed(int modifiers) const;
			bool superPressed(int modifiers) const;
			bool capsLockPressed(int modifiers) const;
			bool numLockPressed(int modifiers) const;
		};
	}
}

// Backup
/*
				// Constructor / Destructor
				KeyModifierParser() = default;
				KeyModifierParser(int shift, int control, int alt, int super, int capsLock, int numLock);
				KeyModifierParser(const KeyModifierParser& other) = default;
				KeyModifierParser(KeyModifierParser&& other) noexcept = default;
				~KeyModifierParser() = default;

				// Operators | assignment
				KeyModifierParser& operator=(const KeyModifierParser& other) = default;
				KeyModifierParser& operator=(KeyModifierParser&& other) noexcept = delete;

				// Getters
				int getShift() const;
				int getControl() const;
				int getAlt() const;
				int getSuper() const;
				int getCapsLock() const;
				int getNumLock() const;

*/
