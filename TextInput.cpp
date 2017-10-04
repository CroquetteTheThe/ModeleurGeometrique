#include <iostream>
#include "glUtils.h"
#include "TextInput.h"
#include "MouseClickEvent.h"
#include "KeyboardEvent.h"

TextInput::TextInput(double x, double y, int size, double height) : Widget(x, y),
                                                                        size(size),
                                                                        width(12*size),
                                                                        height(height),
																		text(""),
																		bgColor(Color::white),
																		color(Color::white){

}

bool TextInput::notify(Event *e) {
	switch (e->getType()) {
		case MOUSE_CLICK_EVENT: {
			auto clickEvent = dynamic_cast<MouseClickEvent *>(e);
			bool previousState = selected;
			if (contains(clickEvent->getX(), clickEvent->getY())) {
				setSelected(true);
				return !previousState;
			} else {
				setSelected(false);
				return previousState;
			}
		}
		case KEYBOARD_EVENT: {
			auto keyboardEvent = dynamic_cast<KeyboardEvent *>(e);
			if (selected) {
				if (keyboardEvent->getKey() == '\b') {
					text = text.substr(0, text.size() - 1);
				} else if (keyboardEvent->getKey() == 13) { // enter
					setSelected(false);
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
		glutils::text(text, x, y+16+(height-18)/2, color);
	else
		glutils::text(text.substr(text.size()-size, text.size()-1), x, y+16+(height-18)/2, color);

	glutils::rectangle(x+1, y+1, width-2, height-2, bgColor);
	glutils::rectangle(x, y, width, height, Color::black);
}

void TextInput::setSelected(bool selected) {
	TextInput::selected = selected;
	if (selected) {
		bgColor = {138 / 255.0, 219 / 255.0, 232 / 255.0};
		color = Color::black;
	} else {
		bgColor = Color::white;
		color = Color::black;
	}
}
