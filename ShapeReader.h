#pragma once

#include "Shape.h"
#include <string>

class ShapeReader {
public:
	virtual Shape *fromFile(std::string path) = 0;
};