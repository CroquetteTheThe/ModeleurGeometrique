#include <iostream>
#include "Slider.h"
#include "../Utils/glUtils.h"
#include "../Utils/Color.h"
#include "../Events/MouseClickEvent.h"

Slider::Slider(float x, float y, float width, float height, int min, int max, int current) : Widget(x, y, width,
                                                                                                    height),
                                                                                             min(min),
                                                                                             max(max),
                                                                                             current(current) {}

void Slider::draw() {
	glutils::rectangle(x + ((1.0f * current - 1.0f * min) / (1.0f * max - 1.0f * min)) * width - 5, y, 10, height,
	                   Color::grey);
	glutils::rectangle(x, y + height / 2 - 1, width, 2, Color::white);
}

bool Slider::notify(Event *e) {
	if (e->getType() == MOUSE_CLICK_EVENT) {
		auto clickEvent = dynamic_cast<MouseClickEvent *>(e);
		if (contains(clickEvent->getX(), clickEvent->getY()) && clickEvent->isDown()) {
			float percent = (clickEvent->getX() - x) / width;
			current = static_cast<int>(percent * (max - min) + min);
			onChange(current);
			return true;
		}
	}
	return false;
}

bool Slider::contains(float x, float y) {
	return x >= this->x && y >= this->y && x <= width + this->x && y <= height + this->y;
}

void Slider::setOnChange(const std::function<void(int)> &onChange) {
	Slider::onChange = onChange;
}

int Slider::getCurrent() const {
	return current;
}
