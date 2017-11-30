#pragma once


#include <vector>
#include <GL/gl.h>
#include "../Utils/Vector3f.h"
#include "Drawable.h"
#include "Shape.h"

class Light : public Drawable {
public:
    explicit Light(const Vector3f &color, float x, float y, float z);

    void setPosition(float x, float y, float z);

    void setAmbient(float r, float g, float b, float a = 1.0);

    void setSpecular(float r, float g, float b, float a = 1.0);

    void setDiffuse(float r, float g, float b, float a = 1.0);

    void draw() override;


private:
    Shape *model;
    GLfloat position[4] = {1.0, 1.0, 1.0, 0.0};
    GLfloat ambient[4] = {0.0, 0.0, 0.0, 1.0};
    GLfloat specular[4] = {1.0, 0.0, 0.0, 1.0};
    GLfloat diffuse[4] = {1.0, 0.0, 0.0, 1.0};
};