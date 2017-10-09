#pragma once

#include "Drawable.h"
#include "EventListener.h"

class Widget : public Drawable, public EventListener {
public:
	Widget(double x, double y, double width, double height) : x(x), y(y), width(width), height(height) {}

	bool notify(Event *e) override { return false; }

	virtual bool contains(int x, int y) = 0;

	~Widget() override = default;

	double x, y, width, height;
};