#include <iostream>
#include "Button.h"
#include "MouseClickEvent.h"
#include "MouseMotionEvent.h"
#include "glUtils.h"

Button::Button(int x, int y, int width, int height, std::string text) : Widget(x, y, width, height),
                                                                        text(text),
                                                                        hover(false) {

}

void Button::bind(const std::function<void(void)> &f) {
	this->f = f;
}

void Button::draw() {
	glutils::text(text, x, y + 16 + (height - 18) / 2, Color::black);
	if (hover)
		glutils::rectangle(x, y, width, height, Color::yellow);
	else
		glutils::rectangle(x, y, width, height, Color::red);
}

bool Button::contains(int x, int y) {
	return x >= this->x && x <= this->x + width && y >= this->y && y <= this->y + height;
}

bool Button::notify(Event *e) {
	if (e->getType() == MOUSE_CLICK_EVENT) {
		auto clickEvent = dynamic_cast<MouseClickEvent *>(e);
		if (contains(clickEvent->getX(), clickEvent->getY())) {
			f();
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
