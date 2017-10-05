#include <algorithm>
#include <GL/gl.h>
#include "Pane.h"
#include "glUtils.h"

Pane::Pane(double x, double y) : Widget(x, y, 0, 0) {}

void Pane::add(Widget *widget) {
	widgets.emplace_back(widget);
	height += widget->height;
	width = (*std::max_element(widgets.begin(), widgets.end(),
	                           [](Widget *a, Widget *b) { return a->width < b->width; }))->width + 10;
}

void Pane::draw() {

	for (auto widget : widgets) {
		glPushMatrix();
		widget->draw();
		glPopMatrix();
	}

	glutils::rectangle(x, y, width, height, {46 / 255.0, 46 / 255.0, 46 / 255.0});

}

bool Pane::notify(Event *e) {
	bool res = false;
	for (auto widget : widgets) {
		res |= widget->notify(e);
	}
	return res;
}

bool Pane::contains(int x, int y) {
	return x >= this->x && x <= this->x + width && y >= this->y && y <= this->y + height;
}
