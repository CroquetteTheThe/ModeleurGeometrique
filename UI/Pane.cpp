#include <algorithm>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include "Pane.h"
#include "../Utils/glUtils.h"
#include "Label.h"
#include "../Events/MouseClickEvent.h"
#include "../Events/MouseMotionEvent.h"

Pane::Pane(float x, float y, std::string title) : Widget(x, y, 0, 22), title(title), marginLeft(5), marginTop(10),
                                                    selected(false), dx(0), dy(0) {
	Widget *label = new Label(x, y, title, 0, 22, {200 / 255.0f, 200 / 255.0f, 200 / 255.0f},
	                          {64 / 255.0f, 64 / 255.0f, 64 / 255.0f});
	widgets.emplace_back(label);
}

void Pane::add(Widget *widget) {
	widgets.emplace_back(widget);
	widget->x = x + marginLeft;
	widget->y = y + marginTop + height;
	height += marginTop + widget->height;
	width = (*std::max_element(widgets.begin(), widgets.end(),
	                           [](Widget *a, Widget *b) { return a->width < b->width; }))->width + 10;
	widgets[0]->width = width;
}

void Pane::draw() {

	for (auto widget : widgets) {
		glPushMatrix();
		widget->draw();
		glPopMatrix();
	}

	glutils::rectangle(x, y, width, height + marginTop, {46 / 255.0f, 46 / 255.0f, 46 / 255.0f});

}

bool Pane::notify(Event *e) {

	bool res = false;
	if (e->getType() == MOUSE_CLICK_EVENT) {
		auto clickEvent = dynamic_cast<MouseClickEvent *>(e);
		if (widgets[0]->contains(clickEvent->getX(), clickEvent->getY()) && clickEvent->getButton() == LEFT) {
			selected = clickEvent->isDown();
			dx = clickEvent->getX() - x;
			dy = clickEvent->getY() - y;
			res = true;
		}
	}
	if (e->getType() == MOUSE_MOTION_EVENT && selected) {
		auto motionEvent = dynamic_cast<MouseMotionEvent *>(e);
		x = motionEvent->getX() - dx;
		y = motionEvent->getY() - dy;
		widgets[0]->x = x;
		widgets[0]->y = y;
		float newY = y + widgets[0]->height + marginTop;
		for (int i = 1; i < widgets.size(); i++) {
			auto widget = widgets[i];
			widget->x = x + marginLeft;
			widget->y = newY;
			newY += widget->height + marginTop;
		}
	}

	for (int i = 1; i < widgets.size(); i++) {
		auto widget = widgets[i];
		res |= widget->notify(e);
	}
	return res;
}

bool Pane::contains(float x, float y) {
	return x >= this->x && x <= this->x + width && y >= this->y && y <= this->y + height;
}
