#pragma once

#include <string>
#include "Widget.h"
#include "../Utils/Vector3f.h"
#include "../Utils/Color.h"

class Label : public Widget {
public:
	Label(float x, float y, const std::string &text, float width, float height,
	      const Vector3f &color = Color::white,
	      const Vector3f &bgColor = {46 / 255.0, 46 / 255.0, 46 / 255.0});

	void draw() override;

	bool contains(float x, float y) override;

	const std::string &getText() const;

	void setText(const std::string &text);

	void setColor(const Vector3f &color);

	void setBgColor(const Vector3f &bgColor);

private:
	std::string text;
	Vector3f color, bgColor;
};



