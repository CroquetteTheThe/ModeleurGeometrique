#include <GL/gl.h>
#include <GL/glut.h>
#include "Label.h"


void Label::draw() {

	glColor3f(color.x, color.y, color.z);
	char *c;
	glRasterPos3f(x, y + 16 + (height - 18) / 2, 0);
	for (auto c: text) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
	}

	glColor3f(bgColor.x, bgColor.y, bgColor.z);
	glBegin(GL_QUADS);
	glVertex3d(x, y, 0);
	glVertex3d(x + width, y, 0);
	glVertex3d(x + width, y + height, 0);
	glVertex3d(x, y + height, 0);
	glEnd();
}

Label::Label(double x, double y, const std::string &text, double width, double height, const Vector3d &color,
             const Vector3d &bgColor) : Widget(x, y), text(text), width(width), height(height), color(color),
                                        bgColor(bgColor) {}

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
