
#include <GL/glut.h>
#include "Label.h"
#include "glUtils.h"


Label::Label(double x, double y, const std::string &text, double width, double height, const Vector3d &color,
             const Vector3d &bgColor) : Widget(x, y, width, height), text(text), color(color),
                                        bgColor(bgColor) {}

void Label::draw() {

	glutils::text(text, x, y + 16 + (height - 18) / 2, {159 / 255.0, 159 / 255.0, 159 / 255.0});
}

const std::string &Label::getText() const {
	return text;
}

bool Label::contains(int x, int y) {
	return x >= this->x && x <= this->x + width && y >= this->y && y <= this->y + height;
}

void Label::setText(const std::string &text) {
	Label::text = text;
}

void Label::setColor(const Vector3d &color) {
	Label::color = color;
}

void Label::setBgColor(const Vector3d &bgColor) {
	Label::bgColor = bgColor;
}
