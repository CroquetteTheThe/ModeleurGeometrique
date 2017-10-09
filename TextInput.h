#pragma once


#include "Widget.h"
#include "Label.h"
#include <string>

class TextInput : public Widget {
public:
	TextInput(double x, double y, int size, double height);

	bool notify(Event *e) override;

	const std::string &getText() const;

	bool contains(int x, int y) override;

	void draw() override;

private:
	int size;
	bool enabled, selected;
	std::string text;
	Vector3d bgColor, color;
};


