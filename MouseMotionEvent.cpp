#include "MouseMotionEvent.h"

MouseMotionEvent::MouseMotionEvent(int x, int y) : x(x), y(y) {}

int MouseMotionEvent::getX() const {
	return x;
}

int MouseMotionEvent::getY() const {
	return y;
}

EventType MouseMotionEvent::getType() {
	return MOUSE_MOTION_EVENT;
}
