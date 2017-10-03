#pragma once

#include "Drawable.h"
#include "EventListener.h"

class Widget : public Drawable, public EventListener {
public:
	Widget(double x, double y) : x(x), y(y) {}

	bool notify(Event *e) override { return false; }

	virtual bool contains(int x, int y) = 0;

public:
	~Widget() override = default;

protected:
	double x, y;
};