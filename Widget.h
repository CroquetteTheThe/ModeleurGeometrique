#pragma once

#include "Drawable.h"

class Widget : public Drawable {
public:
	Widget(double x, double y) : x(x), y(y) {}

	~Widget() override = default;

protected:
	double x, y;
};