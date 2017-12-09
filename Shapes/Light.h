#pragma once


#include <vector>
#include <GL/gl.h>
#include "../Utils/Vector3f.h"
#include "Drawable.h"
#include "Shape.h"

class Light : public Drawable {
public:
    explicit Light(const Vector3f &color, float x, float y, float z, float rAmb, float gAmb, float bAmb, float rDiff,
                   float gDiff, float bDiff, float rSpec, float gSpec, float bSpec, int lightNb);

    void setPosition(float x, float y, float z);

    void setAmbient(float r, float g, float b, float a = 1.0);

    void setSpecular(float r, float g, float b, float a = 1.0);

    void setDiffuse(float r, float g, float b, float a = 1.0);

    void draw() override;

    void enableLight0();

    void enableLight1();

    void enableLight2();

    void enableLight3();

    void enableLight4();

    void enableLight5();

    void enableLight6();

    void enableLight7();


private:
    Shape *model;
    int lightNb;
    GLfloat position[4] = {1.0, 1.0, 1.0, 0.0};
    GLfloat ambient[4] = {0.0, 0.0, 0.0, 1.0};
    GLfloat specular[4] = {1.0, 0.0, 0.0, 1.0};
    GLfloat diffuse[4] = {1.0, 0.0, 0.0, 1.0};
};