#pragma once


#include <vector>
#include "Vector3d.h"
#include "Drawable.h"

class Shape : public Drawable {
public:
	explicit Shape(const Vector3d &color);

	void draw() override;

	void addPoint(Vector3d point);

	void addFace(std::vector<int> face);

private:
	Vector3d color;
	std::vector<Vector3d> points;
	std::vector<std::vector<int>> faces;
};


