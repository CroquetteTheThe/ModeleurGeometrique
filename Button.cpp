#include "Button.h"
#include "MouseClickEvent.h"

Button::Button(int x, int y, int width, int height, std::string text) : Widget(x, y),
                                                                        label(x, y, text, width, height, Color::black,
                                                                              Color::yellow) {

}

void Button::bind(const std::function<void(void)> &f) {
	this->f = f;
}

void Button::draw() {
	label.draw();
}

bool Button::contains(int x, int y) {
	return label.contains(x, y);
}

bool Button::notify(Event *e) {
	if (e->getType() == MOUSE_CLICK_EVENT) {
		auto clickEvent = dynamic_cast<MouseClickEvent *>(e);
		if (contains(clickEvent->getX(), clickEvent->getY())) {
			f();
			return true;
		}
	}
	return false;
}
