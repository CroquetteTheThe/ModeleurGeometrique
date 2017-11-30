#pragma once

#include "../Utils/Vector3f.h"
#include "DrawableType.h"

/**
 * A simple interface for things that can be drawn
 */
class Drawable {
public:

	explicit Drawable(Vector3f color) : color(color) {}

	virtual ~Drawable() = default;

	virtual void draw() = 0;

	virtual DrawableType getType() = 0;

	const Vector3f &getColor() const {
		return color;
	}

	void setColor(const Vector3f &color) {
		Drawable::color = color;
	}

	float x;
	float y;
	float z;

protected:
	Vector3f color;
};