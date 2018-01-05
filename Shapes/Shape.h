#pragma once


#include <vector>
#include <set>
#include "../Utils/Vector3f.h"
#include "Drawable.h"
#include "DrawableType.h"


class Shape : public Drawable {
public:
	explicit Shape(const Vector3f &color);

	void draw() override;

	void addPoint(Vector3f point);

	void addFace(std::vector<int> face);

	std::set<int> neighborVertices(int verticeIndex);

	DrawableType getType() override;

private:
	std::vector<Vector3f> points;
	std::vector<std::vector<int>> faces;
};


