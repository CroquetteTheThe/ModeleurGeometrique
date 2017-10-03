#include <iostream>
#include "TextInput.h"
#include "MouseClickEvent.h"
#include "KeyboardEvent.h"

TextInput::TextInput(double x, double y, double width, double height) : Widget(x, y),
                                                                        label(x, y, "", width, height, Color::black,
                                                                              Color::white) {

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
					label.setText(label.getText().substr(0, label.getText().size() - 1));
				} else if (keyboardEvent->getKey() == 13) { // enter
					setSelected(false);
				} else {
					label.setText(label.getText() + keyboardEvent->getKey());
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
	return label.getText();
}

bool TextInput::contains(int x, int y) {
	return label.contains(x, y);
}

void TextInput::draw() {
	label.draw();
}

void TextInput::setSelected(bool selected) {
	TextInput::selected = selected;
	if (selected) {
		label.setBgColor({138 / 255.0, 219 / 255.0, 232 / 255.0});
		label.setColor(Color::black);
	} else {
		label.setBgColor(Color::white);
		label.setColor(Color::black);
	}
}
