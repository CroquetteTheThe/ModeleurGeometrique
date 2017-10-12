#include "KeyboardEvent.h"

KeyboardEvent::KeyboardEvent(char key) : key(key) {}

EventType KeyboardEvent::getType() {
	return KEYBOARD_EVENT;
}

char KeyboardEvent::getKey() const {
	return key;
}
