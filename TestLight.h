#include "Shapes/Light.h"

class TestLight {
public:
    bool testSetterAmbient(GLfloat amb[4], Light l);

    bool testSetterDiffuse(GLfloat diff[4], Light l);

    bool testSetterSpecular(GLfloat spec[4], Light l);

    bool testSetterPosition(GLfloat pos[3], Light l);

    void runTestLight();
};