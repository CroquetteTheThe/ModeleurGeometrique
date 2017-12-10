#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <cmath>
#endif
#include "Shape.h"

void Shape::draw() {
    glColor3d(color.x, color.y, color.z);
    if (faces[0].size() == 3) {
        glBegin(GL_TRIANGLES);
    }
    else {
        glBegin(GL_QUADS);
    }
    for (auto &face : faces) {
        Vector3f u = Vector3f(points[face[1]].x - points[face[0]].x,
                              points[face[1]].y - points[face[0]].y,
                              points[face[1]].z - points[face[0]].z);
        Vector3f v = Vector3f(points[face[2]].x - points[face[0]].x,
                              points[face[2]].y - points[face[0]].y,
                              points[face[2]].z - points[face[0]].z);

        float x = (u.y * v.z) - (u.z * v.y);
        float y = (u.z * v.x) - (u.x * v.z);
        float z = (u.x * v.y) - (u.y * v.x);

        auto length = (float) sqrt((pow(x, 2)) + (pow(y, 2)) + (z, 2));
        x /= length;
        y /= length;
        z /= length;

        glNormal3f(x, y, z);
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