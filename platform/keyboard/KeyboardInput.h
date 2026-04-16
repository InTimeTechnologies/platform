#pragma once

// Dependencies | std
#include <array>
#include <forward_list>
#include <vector>

// Dependencies | it
#include "Key.h"
#include "KeyModifierParser.h"

namespace it {
	namespace platform {
		class KeyboardInput {
			// Friends
			friend class PlatformImplementation;

			// Object
			private:
				// Properties
				std::array<Key, static_cast<size_t>(KeyCode::COUNT)> keys{};
				std::forward_list<Key*> keysInTransientState{};
				int keysPressedCount{ 0 };
				KeyModifierParser keyModifierParser{};
	
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
				const std::array<Key, static_cast<size_t>(KeyCode::COUNT)>& getKeys() const;
				int getKeysPressedCount() const;
				
				const std::forward_list<Key*>& getKeysToReset() const;
				const Key& getKey(KeyCode keyCode) const;
				size_t getKeyIndex(KeyCode keyCode) const;
				
			private:
				// Functions
				void feedEvent(KeyCode code, KeyAction action);
				void reset();
				void resetTransientStates();
		};
	}
}
