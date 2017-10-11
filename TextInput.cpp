#include <iostream>
#include "glUtils.h"
#include "TextInput.h"
#include "MouseClickEvent.h"
#include "KeyboardEvent.h"

TextInput::TextInput(double x, double y, int size, double height) : Widget(x, y, 12 * size, height),
                                                                    size(size),
                                                                    text(""),
                                                                    bgColor(Color::white),
                                                                    color(Color::white),
                                                                    selected(false),
                                                                    onEnter(nullptr) {

}

bool TextInput::notify(Event *e) {
	switch (e->getType()) {
		case MOUSE_CLICK_EVENT: {
			auto clickEvent = dynamic_cast<MouseClickEvent *>(e);
			if (!clickEvent->isDown()) return false;
			bool previousState = selected;
			if (contains(clickEvent->getX(), clickEvent->getY())) {
				selected = true;
				return !previousState;
			} else {
				selected = false;
				return previousState;
			}
		}
		case KEYBOARD_EVENT: {
			auto keyboardEvent = dynamic_cast<KeyboardEvent *>(e);
			if (selected) {
				if (keyboardEvent->getKey() == '\b') {
					text = text.substr(0, text.size() - 1);
				} else if (keyboardEvent->getKey() == 13) { // enter
					if (onEnter != nullptr) onEnter();
					selected = false;
				} else {
					text = text + keyboardEvent->getKey();
				}
				return true;
			}
			return false;
		}
		default:
			return false;
	}
}

const std::string &TextInput::getText() const {
	return text;
}

bool TextInput::contains(int x, int y) {
	return x >= this->x && x <= this->x + width && y >= this->y && y <= this->y + height;
}

void TextInput::draw() {

	if (text.size() <= size)
		glutils::text(text, x, y + 16 + (height - 18) / 2, Color::black);
	else
		glutils::text(text.substr(text.size() - size, text.size() - 1), x, y + 16 + (height - 18) / 2, Color::black);

	glutils::rectangle(x + 1, y + 1, width - 2, height - 2, Color::white);
	if (selected)
		glutils::rectangle(x, y, width, height, {138 / 255.0, 219 / 255.0, 232 / 255.0});
	else
		glutils::rectangle(x, y, width, height, Color::black);
}

void TextInput::setOnEnter(const std::function<void()> &onEnter) {
	TextInput::onEnter = onEnter;
}


