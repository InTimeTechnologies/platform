#include "to_string.h"

namespace it {
	namespace platform {
		std::string to_string(KeyCode keyCode) {
			switch (keyCode) {
				case KeyCode::SPACE:           return "space";
				case KeyCode::APOSTROPHE:      return ",";
				case KeyCode::COMMA:           return ",";
				case KeyCode::MINUS:           return ",";
				case KeyCode::PERIOD:          return ",";
				case KeyCode::SLASH:           return ",";
				case KeyCode::ALPHA_0:         return "0";
				case KeyCode::ALPHA_1:         return "1";
				case KeyCode::ALPHA_2:         return "2";
				case KeyCode::ALPHA_3:         return "3";
				case KeyCode::ALPHA_4:         return "4";
				case KeyCode::ALPHA_5:         return "5";
				case KeyCode::ALPHA_6:         return "6";
				case KeyCode::ALPHA_7:         return "7";
				case KeyCode::ALPHA_8:         return "8";
				case KeyCode::ALPHA_9:         return "9";
				case KeyCode::SEMICOLON:       return ",";
				case KeyCode::EQUAL:           return ",";
				case KeyCode::A:               return "a";
				case KeyCode::B:               return "b";
				case KeyCode::C:               return "c";
				case KeyCode::D:               return "d";
				case KeyCode::E:               return "e";
				case KeyCode::F:               return "f";
				case KeyCode::G:               return "g";
				case KeyCode::H:               return "h";
				case KeyCode::I:               return "i";
				case KeyCode::J:               return "j";
				case KeyCode::K:               return "k";
				case KeyCode::L:               return "l";
				case KeyCode::M:               return "m";
				case KeyCode::N:               return "n";
				case KeyCode::O:               return "o";
				case KeyCode::P:               return "p";
				case KeyCode::Q:               return "q";
				case KeyCode::R:               return "r";
				case KeyCode::S:               return "s";
				case KeyCode::T:               return "t";
				case KeyCode::U:               return "u";
				case KeyCode::V:               return "v";
				case KeyCode::W:               return "w";
				case KeyCode::X:               return "x";
				case KeyCode::Y:               return "y";
				case KeyCode::Z:               return "z";
				case KeyCode::BRACKET_LEFT:    return ",";
				case KeyCode::BACKSLASH:       return ",";
				case KeyCode::BRACKET_RIGHT:   return ",";
				case KeyCode::GRAVE_ACCENT:    return ",";
				case KeyCode::WORLD_1:         return "1";
				case KeyCode::WORLD_2:         return "2";
				case KeyCode::ESCAPE:          return "escape";
				case KeyCode::ENTER:           return "n";
				case KeyCode::TAB:             return "t";
				case KeyCode::BACKSPACE:       return "b";
				case KeyCode::INSERT:          return "insert";
				case KeyCode::DELETE:          return "delete";
				case KeyCode::ARROW_RIGHT:     return "arrow_right";
				case KeyCode::ARROW_LEFT:      return "arrow_left";
				case KeyCode::ARROW_DOWN:      return "arrow_down";
				case KeyCode::ARROW_UP:        return "arrow";
				case KeyCode::PAGE_UP:         return "page_up";
				case KeyCode::PAGE_DOWN:       return "down";
				case KeyCode::HOME:            return "home";
				case KeyCode::END:             return "end";
				case KeyCode::CAPS_LOCK:       return "caps_lock";
				case KeyCode::SCROLL_LOCK:     return "lock";
				case KeyCode::NUM_LOCK:        return "num_lock";
				case KeyCode::PRINT_SCREEN:    return "print_screen";
				case KeyCode::PAUSE:           return "pause";
				case KeyCode::F1:              return "f1";
				case KeyCode::F2:              return "f2";
				case KeyCode::F3:              return "f3";
				case KeyCode::F4:              return "f4";
				case KeyCode::F5:              return "f5";
				case KeyCode::F6:              return "f6";
				case KeyCode::F7:              return "f7";
				case KeyCode::F8:              return "f8";
				case KeyCode::F9:              return "f9";
				case KeyCode::F10:             return "f10";
				case KeyCode::F11:             return "f11";
				case KeyCode::F12:             return "f12";
				case KeyCode::F13:             return "f13";
				case KeyCode::F14:             return "f14";
				case KeyCode::F15:             return "f15";
				case KeyCode::F16:             return "f16";
				case KeyCode::F17:             return "f17";
				case KeyCode::F18:             return "f18";
				case KeyCode::F19:             return "f19";
				case KeyCode::F20:             return "f20";
				case KeyCode::F21:             return "f21";
				case KeyCode::F22:             return "f22";
				case KeyCode::F23:             return "f23";
				case KeyCode::F24:             return "f24";
				case KeyCode::F25:             return "f25";
				case KeyCode::NUMPAD_0:        return "numpad_0";
				case KeyCode::NUMPAD_1:        return "numpad_1";
				case KeyCode::NUMPAD_2:        return "numpad_2";
				case KeyCode::NUMPAD_3:        return "numpad_3";
				case KeyCode::NUMPAD_4:        return "numpad_4";
				case KeyCode::NUMPAD_5:        return "numpad_5";
				case KeyCode::NUMPAD_6:        return "numpad_6";
				case KeyCode::NUMPAD_7:        return "numpad_7";
				case KeyCode::NUMPAD_8:        return "numpad_8";
				case KeyCode::NUMPAD_9:        return "numpad_9";
				case KeyCode::NUMPAD_DECIMAL:  return "numpad_";
				case KeyCode::NUMPAD_DIVIDE:   return "numpad_";
				case KeyCode::NUMPAD_MULTIPLY: return "numpad_";
				case KeyCode::NUMPAD_SUBTRACT: return "numpad_";
				case KeyCode::NUMPAD_ADD:      return "numpad_";
				case KeyCode::NUMPAD_ENTER:    return "numpad_enter";
				case KeyCode::NUMPAD_EQUAL:    return "numpad_";
				case KeyCode::LEFT_SHIFT:      return "left_shift";
				case KeyCode::LEFT_CONTROL:    return "left_control";
				case KeyCode::LEFT_ALT:        return "left_alt";
				case KeyCode::LEFT_SUPER:      return "left_super";
				case KeyCode::RIGHT_SHIFT:     return "left_shift";
				case KeyCode::RIGHT_CONTROL:   return "right_control";
				case KeyCode::RIGHT_ALT:       return "right_alt";
				case KeyCode::RIGHT_SUPER:     return "right_super";
				case KeyCode::MENU:            return "menu";
				case KeyCode::UNKNOWN:
				default:                       return "unknown";
			}
		}
		std::string to_string(KeyAction keyAction) {
			switch (keyAction) {
				case KeyAction::PRESS:   return "press";
				case KeyAction::RELEASE: return "release";
				case KeyAction::REPEAT:  return "repeat";
				case KeyAction::UNKNOWN:
				default:                 return "unknwon";
			}
		}
		std::string to_string(const Key& key) {
			std::string keyCode =        "keyCode      = " + to_string(key.keyCode) + "\n";
			std::string justPressed =    "justPressed  = " + key.justPressed ? "true\n" : "false\n";
			std::string repeat =         "repeat       = " + key.repeat ? "true\n" : "false\n";
			std::string justReleased =   "justReleased = " + key.justReleased ? "true\n" : "false\n";
			std::string pressed =        "pressed      = " + key.pressed ? "true\n" : "false\n";
			std::string description =    "description  = " + key.description;
			return keyCode + justPressed + repeat + justReleased + pressed + description;
		}
		std::string to_string(const KeyEvent& keyEvent) {
			std::string keyCode = it::platform::to_string(keyEvent.keyCode) + "\n";
			std::string scancode = std::to_string(keyEvent.scanCode) + "\n";
			std::string action = it::platform::to_string(keyEvent.action) + "\n";
			std::string modifier = std::to_string(keyEvent.modifier);
			return keyCode + scancode + action + modifier;
		}
	}
}
