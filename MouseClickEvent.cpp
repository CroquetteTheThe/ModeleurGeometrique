#include "MouseClickEvent.h"

EventType MouseClickEvent::getType() {
	return MOUSE_CLICK_EVENT;
}

MouseClickEvent::MouseClickEvent(MouseButton button, int x, int y, bool down) : button(button), x(x), y(y),
                                                                                down(down) {}

MouseButton MouseClickEvent::getButton() const {
	return button;
}

int MouseClickEvent::getX() const {
	return x;
}

int MouseClickEvent::getY() const {
	return y;
}

bool MouseClickEvent::isDown() const {
	return down;
}
