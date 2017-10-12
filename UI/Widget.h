#pragma once

#include "../Shapes/Drawable.h"
#include "../Events/EventListener.h"

class Widget : public EventListener {
public:
	Widget(float x, float y, float width, float height) : x(x), y(y), width(width), height(height) {}

	bool notify(Event *e) override { return false; }

	virtual void draw() = 0;
	virtual bool contains(float x, float y) = 0;

	~Widget() = default;

	float x, y, width, height;
};