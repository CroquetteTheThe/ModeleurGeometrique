#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "Label.h"
#include "../Utils/glUtils.h"


Label::Label(float x, float y, const std::string &text, float width, float height, const Vector3f &color,
             const Vector3f &bgColor) : Widget(x, y, width, height), text(text), color(color),
                                        bgColor(bgColor) {}

void Label::draw() {

	glutils::text(text, x, y + 16 + (height - 18) / 2, color);
	glutils::rectangle(x, y, width, height, bgColor);
}

const std::string &Label::getText() const {
	return text;
}

bool Label::contains(float x, float y) {
	return x >= this->x && x <= this->x + width && y >= this->y && y <= this->y + height;
}

void Label::setText(const std::string &text) {
	Label::text = text;
}

void Label::setColor(const Vector3f &color) {
	Label::color = color;
}

void Label::setBgColor(const Vector3f &bgColor) {
	Label::bgColor = bgColor;
}
