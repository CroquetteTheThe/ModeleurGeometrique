#ifdef __APPLE__
#include <GLUT/glut.h>
#else

#include <GL/glut.h>
#include <cmath>

#endif

#include "Camera.h"
#include "../Readers/OFFReader.h"

#define PI  3.141592653589793238463

/*Camera::Camera(const Vector3f &color, Vector3f position, Vector3f direction, float fov) : Drawable(color) {
    this->position = position;
    this->direction = direction;
    this->fov = fov;
}*/

Camera::Camera(const Vector3f &pos, const Vector3f &color) : Drawable(color) {
    x = pos.x;
    y = pos.y;
    z = pos.z;
    auto reader = OFFReader();
    try {
        this->shape = reader.fromFile("../resources/cam.off");
    } catch (const std::exception &e) {
        perror("Le fichier n'existe pas");
    }
}

void Camera::setPosition(Vector3f position) {
    this->x = position.x;
    this->y = position.y;
    this->z = position.z;
}

Vector3f Camera::getPosition() {
    return {x, y, z};
}

void Camera::setDirection(Vector3f direction) {
    this->direction = direction;
}

Vector3f Camera::getDirection() {
    return this->direction;
}

void Camera::setFov(float fov) {
    this->fov = fov;
}


void Camera::draw() {
    glPushMatrix();
    Vector3f lookAtDiff = {this->getPosition().x - this->getDirection().x,
                           this->getPosition().y - this->getDirection().y,
                           this->getPosition().z - this->getDirection().z};

    Vector3f vectRotation = {0., 0., 0.};

    auto xRotation = atan2(lookAtDiff.x, lookAtDiff.z);
    auto yRotation = atan2(lookAtDiff.y, sqrt(lookAtDiff.x * lookAtDiff.x + lookAtDiff.z * lookAtDiff.z));

    if (xRotation > 0 && yRotation > 0) {
        vectRotation.x = this->getPosition().x;
        vectRotation.y = -this->getPosition().y;
    } else if (xRotation < 0 && yRotation < 0) {
        vectRotation.x = -this->getPosition().x;
        vectRotation.y = this->getPosition().y;
    } else if (xRotation > 0 && yRotation < 0) {
        vectRotation.x = -this->getPosition().y;
        vectRotation.y = -this->getPosition().x;
    } else if (xRotation < 0 && yRotation > 0) {
        vectRotation.x = this->getPosition().y;
        vectRotation.y = this->getPosition().x;
    }
    glRotatef((GLfloat) (xRotation * 180 / PI), 0, vectRotation.x, 0);
    glRotatef((GLfloat) (yRotation * 180 / PI), vectRotation.y, 0, 0);
    this->shape->draw();


    glPopMatrix();
    glBegin(GL_LINES);
    glLoadIdentity();
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(this->getPosition().x, this->getPosition().y, this->getPosition().z);
    glVertex3f(this->getDirection().x, this->getDirection().y, this->getDirection().z);
    glEnd();
}

DrawableType Camera::getType() {
    return CAMERA;
}
