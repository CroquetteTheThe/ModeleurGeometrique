#pragma once

#include <functional>
#include "Widget.h"

class Slider : public Widget {
public:
	Slider(float x, float y, float width, float height, int min, int max, int current);

	void draw() override;

	bool notify(Event *e) override;

	bool contains(float x, float y) override;

	void setOnChange(const std::function<void(int)> &onChange);

	int getCurrent() const;

private:
	int min, max, current;
	std::function<void(int)> onChange;
};
