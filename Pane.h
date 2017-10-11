#pragma once


#include <vector>
#include "Widget.h"
#include <string>
#include <functional>

class Pane : public Widget {
public:
	Pane(double x, double y, std::string title);

	void add(Widget *widget);

	void draw() override;

	bool contains(int x, int y) override;

	bool notify(Event *e) override;

private:
	std::string title;
	std::vector<Widget *> widgets;
	bool selected;
	int marginLeft, marginTop, dx, dy;
};



