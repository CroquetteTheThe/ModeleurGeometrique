#pragma once


#include <vector>
#include "Widget.h"

class Pane : public Widget {
public:
	Pane(double x, double y);

	void add(Widget *widget);

	void draw() override;

	bool contains(int x, int y) override;

	bool notify(Event *e) override;

private:
	std::vector<Widget *> widgets;
};



