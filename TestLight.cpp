#include <cstdio>
#include "TestLight.h"

bool TestLight::testSetterAmbient(GLfloat amb[4], Light l) {
    l.setAmbient(amb[0], amb[1], amb[2], amb[3]);
    if (amb[0] == l.getAmbient()[0] && amb[1] == l.getAmbient()[1] && amb[2] == l.getAmbient()[2] &&
        amb[3] == l.getAmbient()[3]) {
        return true;
    }

    return false;
}

bool TestLight::testSetterDiffuse(GLfloat diff[4], Light l) {
    l.setDiffuse(diff[0], diff[1], diff[2], diff[3]);
    if (diff[0] == l.getDiffuse()[0] && diff[1] == l.getDiffuse()[1] && diff[2] == l.getDiffuse()[2] &&
        diff[3] == l.getDiffuse()[3]) {
        return true;
    }

    return false;
}

bool TestLight::testSetterSpecular(GLfloat spec[4], Light l) {
    l.setSpecular(spec[0], spec[1], spec[2], spec[3]);
    if (spec[0] == l.getSpecular()[0] && spec[1] == l.getSpecular()[1] && spec[2] == l.getSpecular()[2] &&
        spec[3] == l.getSpecular()[3]) {
        return true;
    }

    return false;
}

bool TestLight::testSetterPosition(GLfloat pos[4], Light l) {
    l.setPosition(pos[0], pos[1], pos[2]);
    if (pos[0] == l.getPosition()[0] && pos[1] == l.getPosition()[1] && pos[2] == l.getPosition()[2]) {
        return true;
    }

    return false;
}

void TestLight::runTestLight() {
    Light l = Light(Vector3f(.0, .5, .5), 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0,
                    1.0, 1.0, 1.0, 1);
    GLfloat position[4] = {2.0, 5.0, 5.0, 0.0};
    GLfloat ambient[4] = {0.1, 0.1, 0.1, 1.0};
    GLfloat diffuse[4] = {1.0, 0.1, 0.1, 1.0};
    GLfloat specular[4] = {0.8, 0.2, 0.0, 1.0};
    if (this->testSetterAmbient(ambient, l)) {
        printf("Test setter ambient : valide\n");
    } else {
        printf("Test setter ambient : non valide\n");
    }

    if (this->testSetterDiffuse(diffuse, l)) {
        printf("Test setter diffuse : valide\n");
    } else {
        printf("Test setter diffuse : non valide\n");
    }

    if (this->testSetterSpecular(specular, l)) {
        printf("Test setter specular : valide\n");
    } else {
        printf("Test setter specular : non valide\n");
    }

    if (this->testSetterPosition(position, l)) {
        printf("Test setter position : valide\n");
    } else {
        printf("Test setter position : non valide\n");
    }


}
