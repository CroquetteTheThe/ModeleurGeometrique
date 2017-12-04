#ifndef MODELISATEURGEOMETRIQUE_CAMERA_H
#define MODELISATEURGEOMETRIQUE_CAMERA_H

#include "Drawable.h"
#include "Shape.h"
#include <string>

class Camera : public Drawable {
private:
    Vector3f position = {2, 2, 2};
    Vector3f direction = {0, 0, 0};
    std::string resource = "../resources/cam.off";
    float fov = 45.0;
    Shape *shape;

public:
    explicit Camera(const Vector3f &color);

    void draw() override;

    void setPosition(Vector3f position);

    Vector3f getPosition();

    void setDirection(Vector3f direction);

    Vector3f getDirection();

    void setFov(float fov);
};

#endif //MODELISATEURGEOMETRIQUE_CAMERA_H
