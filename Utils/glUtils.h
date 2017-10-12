#pragma once

#include <string>
#include "Vector3f.h"

namespace glutils {

	void rectangle(float x, float y, float width, float height, Vector3f color);

	void roundedRectangle(float x, float y, float width, float height, float radius, Vector3f color);

	void text(const std::string &text, float x, float y, Vector3f color);

}