#pragma once

// Dependencies | std
#include <array>
#include <forward_list>

// Dependencies | it
#include "Key.h"

namespace it {
	namespace platform {
		class KeyboardInput {
			// Object
			private:
				// Properties
				std::forward_list<Key*> keysInTransientState{};
				std::array<Key, static_cast<size_t>(KeyCode::COUNT)> keys{};
	
			public:
				// Constructor / Destructor
				KeyboardInput();
				KeyboardInput(const KeyboardInput& other) = delete;
				KeyboardInput(KeyboardInput&& other) noexcept = delete;
				~KeyboardInput() = default;
	
				// Operators | assignment
				KeyboardInput& operator=(const KeyboardInput& other) = delete;
				KeyboardInput& operator=(KeyboardInput&& other) noexcept = delete;
	
				// Getters
				const std::forward_list<Key*>& getKeysToReset() const;
				const std::array<Key, static_cast<size_t>(KeyCode::COUNT)>& getKeys() const;
	
				const Key& getKey(KeyCode keyCode) const;
				size_t getKeyIndex(KeyCode keyCode) const;
	
				// Functions
				void feedEvent(KeyCode code, KeyAction action);
				void reset();
				void resetTransientStates();
				void resetAllTransientStates();	
		};
	}
}
