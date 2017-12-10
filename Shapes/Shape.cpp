#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <cmath>
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
            if (idx % 4 == 0 && idx > 4) {
                Vector3f u = Vector3f(points[(idx + 1) % points.size()].x - points[(idx) % points.size()].x,
                                      points[(idx + 1) % points.size()].y - points[(idx) % points.size()].y,
                                      points[(idx + 1) % points.size()].z - points[(idx) % points.size()].z);
                Vector3f v = Vector3f(points[(idx + 2) % points.size()].x - points[(idx) % points.size()].x,
                                      points[(idx + 2) % points.size()].y - points[(idx) % points.size()].y,
                                      points[(idx + 2) % points.size()].z - points[(idx) % points.size()].z);

                float x = (u.y * v.z) - (u.z * v.y);
                float y = (u.z * v.x) - (u.x * v.z);
                float z = (u.x * v.y) - (u.y * v.x);

                float length = (float) sqrt((pow(x, 2)) + (pow(y, 2)) + (z, 2));
                x /= length;
                y /= length;
                z /= length;

                glNormal3f(x, y, z);
            }
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

void Shape::calculeNormales() {

    for (auto &face : faces) {
        for (int idx : face) {
            Vector3f u = Vector3f(points[(idx + 1) % points.size()].x - points[(idx) % points.size()].x,
                                  points[(idx + 1) % points.size()].y - points[(idx) % points.size()].y,
                                  points[(idx + 2) % points.size()].z - points[(idx) % points.size()].z);
            Vector3f v = Vector3f(points[(idx + 2) % points.size()].x - points[(idx) % points.size()].x,
                                  points[(idx + 2) % points.size()].y - points[(idx) % points.size()].y,
                                  points[(idx + 2) % points.size()].z - points[(idx) % points.size()].z);

            float x = (u.y * v.z) - (u.z * v.y);
            float y = (u.z * v.x) - (u.x * v.z);
            float z = (u.x * v.y) - (u.y * v.x);

            normales.emplace_back(Vector3f(x, y, z));
        }
    }
}