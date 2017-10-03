#pragma once

#include <string>
#include "Widget.h"
#include "Vector3d.h"
#include "Color.h"

class Label : public Widget {
public:
	Label(double x, double y, const std::string &text, double width, double height,
	      const Vector3d &color = Color::white,
	      const Vector3d &bgColor = Color::grey);

	void draw() override;

private:
	std::string text;
	double width, height;
	Vector3d color, bgColor;
};



