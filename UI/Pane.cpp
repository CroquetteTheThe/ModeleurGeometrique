#include <algorithm>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <utility>
#include "Pane.h"
#include "../Utils/glUtils.h"
#include "Label.h"
#include "../Events/MouseClickEvent.h"
#include "../Events/MouseMotionEvent.h"

Pane::Pane(float x, float y, std::string title) : AbstractPane(x, y, std::move(title)) {
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
