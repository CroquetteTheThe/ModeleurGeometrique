#pragma once

/**
 * A simple interface for things that can be drawn
 */
class Drawable {
public:
	virtual ~Drawable() = default;

	virtual void draw() = 0;
};