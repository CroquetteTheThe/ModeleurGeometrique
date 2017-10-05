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

	bool contains(int x, int y) override;

	const std::string &getText() const;

	void setText(const std::string &text);

	void setColor(const Vector3d &color);

	void setBgColor(const Vector3d &bgColor);

private:
	std::string text;
	Vector3d color, bgColor;
};



