#ifdef __APPLE__
#include <GLUT/glut.h>
#else

#include <GL/glut.h>
#include <cmath>

#endif

#include "Camera.h"
#include "../Readers/OFFReader.h"

/*Camera::Camera(const Vector3f &color, Vector3f position, Vector3f direction, float fov) : Drawable(color) {
    this->position = position;
    this->direction = direction;
    this->fov = fov;
}*/

Camera::Camera(const Vector3f &color) : Drawable(color) {
    auto reader = OFFReader();
    try {
        this->shape = reader.fromFile("../resources/cam.off");
    } catch (const std::exception &e) {
        perror("Le fichier n'existe pas");
    }
}

void Camera::setPosition(Vector3f position) {
    this->position = position;
    glTranslatef(this->getPosition().x, this->getPosition().y, this->getPosition().z);
}

Vector3f Camera::getPosition() {
    return this->position;
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
    glTranslatef(this->getPosition().x, this->getPosition().y, this->getPosition().z);
    glRotatef(
            atan2(this->getPosition().y - this->getDirection().y, this->getPosition().x - this->getDirection().x) * 360,
            this->getPosition().x, -this->getPosition().y, this->getPosition().z);
    this->shape->draw();

    glPopMatrix();
}