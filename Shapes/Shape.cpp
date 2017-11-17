#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <algorithm>

#endif
#include "Shape.h"

void Shape::draw() {
	glColor3d(color.x, color.y, color.z);
	if (faces[0].size() == 3)
		glBegin(GL_TRIANGLES);
	else
		glBegin(GL_QUADS);
	for (auto &face : faces) {
		for (int idx : face) {
			glVertex3d(points[idx].x, points[idx].y, points[idx].z);
		}
	}
	glEnd();
}

Shape::Shape(const Vector3f &color) : Drawable(color) {}

void Shape::addFace(std::vector<int> face) {
	faces.emplace_back(face);
}

void Shape::addPoint(Vector3f point) {
	points.emplace_back(point);
}

std::set<int> Shape::neigborVertices(int verticeIndex) {
	std::set<int> res;
	for (auto face : faces) {
		auto it = std::find(face.begin(), face.end(), verticeIndex);
		if (it == face.end()) continue;
		res.emplace(it + 1 == face.end() ? face[0] : *it);
		res.emplace(it == face.begin() ? face[face.size() - 1] : *(it + 1));
	}
	return res;
}
