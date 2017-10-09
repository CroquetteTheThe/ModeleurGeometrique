#pragma once

#include <string>
#include "Vector3d.h"

namespace glutils {

	void rectangle(int x, int y, int width, int height, Vector3d color);

	void roundedRectangle(int x, int y, int width, int height, int radius, Vector3d color);

	void text(std::string text, int x, int y, Vector3d color);

}