#pragma once


#include "ShapeReader.h"

class OFFReader : public ShapeReader {
public:
	Shape *fromFile(std::string path) override;
};


