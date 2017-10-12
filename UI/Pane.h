#pragma once


#include <vector>
#include "Widget.h"
#include <string>
#include <functional>

class Pane : public Widget {
public:
	Pane(float x, float y, std::string title);

	void add(Widget *widget);

	void draw() override;

	bool contains(float x, float y) override;

	bool notify(Event *e) override;

private:
	std::string title;
	std::vector<Widget *> widgets;
	bool selected;
	float marginLeft, marginTop, dx, dy;
};



