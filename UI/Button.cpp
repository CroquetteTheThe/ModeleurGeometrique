#include <iostream>
#include <utility>
#include "Button.h"
#include "../Events/MouseClickEvent.h"
#include "../Events/MouseMotionEvent.h"
#include "../Utils/glUtils.h"

Button::Button(float x, float y, float width, float height, std::string text) : Widget(x, y, width, height),
                                                                                text(std::move(text)),
                                                                        hover(false) {

}

void Button::bind(const std::function<void(void)> &f) {
	this->onClick = f;
}

void Button::draw() {
	glutils::text(text, x + 8, y + 16 + (height - 18) / 2, {200 / 255.0f, 200 / 255.0f, 200 / 255.0f});
	if (hover)
		glutils::roundedRectangle(x, y, width, height, 8, {76 / 255.0f, 76 / 255.0f, 76 / 255.0f});
	else
		glutils::roundedRectangle(x, y, width, height, 8, {64 / 255.0f, 64 / 255.0f, 64 / 255.0f});
}

bool Button::contains(float x, float y) {
	return x >= this->x && x <= this->x + width && y >= this->y && y <= this->y + height;
}

bool Button::notify(Event *e) {
	if (e->getType() == MOUSE_CLICK_EVENT) {
		auto clickEvent = dynamic_cast<MouseClickEvent *>(e);
		if (contains(clickEvent->getX(), clickEvent->getY()) && clickEvent->isDown()) {
			onClick();
			return true;
		}
	} else if (e->getType() == MOUSE_MOTION_EVENT) {
		auto motionEvent = dynamic_cast<MouseMotionEvent *>(e);
		bool prev = hover;
		hover = contains(motionEvent->getX(), motionEvent->getY());
		return prev == hover;

	}
	return false;
}
