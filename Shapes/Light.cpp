#ifdef __APPLE__
#include <GLUT/glut.h>
#else

#include <GL/glut.h>

#endif

#include "Light.h"
#include "../Readers/OFFReader.h"

void Light::draw() {

    //glPushMatrix();
    //glTranslatef(this->position[0], this->position[1], this->position[2]);
    //this->model->draw();
    //printf("Positions : %f %f %f",this->position[0],this->position[1],this->position[2]);

    //glPopMatrix();

    // glPushMatrix();

    switch (this->lightNb) {
        case 0:
            this->enableLight0();
            break;
        case 1:
            this->enableLight1();
            break;
        case 2:
            this->enableLight2();
            break;
        case 3:
            this->enableLight3();
            break;
        case 4:
            this->enableLight4();
            break;
        case 5:
            this->enableLight5();
            break;
        case 6:
            this->enableLight6();
            break;
        case 7:
            this->enableLight7();
            break;

    }


    // glPopMatrix();


}

DrawableType Light::getType() {
    return LIGHT;
}

GLfloat *Light::getPosition() {
    return this->position;
}

GLfloat *Light::getAmbient() {
    return this->ambient;
}

GLfloat *Light::getDiffuse() {
    return this->diffuse;
}

GLfloat *Light::getSpecular() {
    return this->specular;
}

void Light::setPosition(float x, float y, float z) {
    this->position[0] = x;
    this->position[1] = y;
    this->position[2] = z;
    this->position[3] = 0.0;
}

void Light::setAmbient(float r, float g, float b, float a) {
    this->ambient[0] = r;
    this->ambient[1] = g;
    this->ambient[2] = b;
    this->ambient[3] = a;
}

void Light::setSpecular(float r, float g, float b, float a) {

    this->specular[0] = r;
    this->specular[1] = g;
    this->specular[2] = b;
    this->specular[3] = a;
}

void Light::setDiffuse(float r, float g, float b, float a) {

    this->diffuse[0] = r;
    this->diffuse[1] = g;
    this->diffuse[2] = b;
    this->diffuse[3] = a;
}

Light::Light(const Vector3f &color, float x, float y, float z, float rAmb, float gAmb, float bAmb, float rDiff,
             float gDiff, float bDiff, float rSpec, float gSpec, float bSpec, int lightNb) : Drawable(color) {
    this->position[0] = x;
    this->position[1] = y;
    this->position[2] = z;

    this->ambient[0] = rAmb;
    this->ambient[1] = gAmb;
    this->ambient[2] = bAmb;

    this->diffuse[0] = rDiff;
    this->diffuse[1] = gDiff;
    this->diffuse[2] = bDiff;

    this->specular[0] = rSpec;
    this->specular[1] = gSpec;
    this->specular[2] = bSpec;

    this->lightNb = lightNb;
    auto reader = OFFReader();
    this->model = reader.fromFile("../resources/seashell.off");
    this->model->setColor(color);
}

void Light::enableLight0() {
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, this->position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, this->ambient);
    glLightfv(GL_LIGHT0, GL_SPECULAR, this->specular);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, this->diffuse);
}

void Light::enableLight1() {
    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1, GL_POSITION, this->position);
    glLightfv(GL_LIGHT1, GL_AMBIENT, this->ambient);
    glLightfv(GL_LIGHT1, GL_SPECULAR, this->specular);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, this->diffuse);
}

void Light::enableLight2() {
    glEnable(GL_LIGHT2);
    glLightfv(GL_LIGHT2, GL_POSITION, this->position);
    glLightfv(GL_LIGHT2, GL_AMBIENT, this->ambient);
    glLightfv(GL_LIGHT2, GL_SPECULAR, this->specular);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, this->diffuse);
}

void Light::enableLight3() {
    glEnable(GL_LIGHT3);
    glLightfv(GL_LIGHT3, GL_POSITION, this->position);
    glLightfv(GL_LIGHT3, GL_AMBIENT, this->ambient);
    glLightfv(GL_LIGHT3, GL_SPECULAR, this->specular);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, this->diffuse);
}

void Light::enableLight4() {
    glEnable(GL_LIGHT4);
    glLightfv(GL_LIGHT4, GL_POSITION, this->position);
    glLightfv(GL_LIGHT4, GL_AMBIENT, this->ambient);
    glLightfv(GL_LIGHT4, GL_SPECULAR, this->specular);
    glLightfv(GL_LIGHT4, GL_DIFFUSE, this->diffuse);
}

void Light::enableLight5() {
    glEnable(GL_LIGHT5);
    glLightfv(GL_LIGHT5, GL_POSITION, this->position);
    glLightfv(GL_LIGHT5, GL_AMBIENT, this->ambient);
    glLightfv(GL_LIGHT5, GL_SPECULAR, this->specular);
    glLightfv(GL_LIGHT5, GL_DIFFUSE, this->diffuse);
}

void Light::enableLight6() {
    glEnable(GL_LIGHT6);
    glLightfv(GL_LIGHT6, GL_POSITION, this->position);
    glLightfv(GL_LIGHT6, GL_AMBIENT, this->ambient);
    glLightfv(GL_LIGHT6, GL_SPECULAR, this->specular);
    glLightfv(GL_LIGHT6, GL_DIFFUSE, this->diffuse);
}

void Light::enableLight7() {
    glEnable(GL_LIGHT7);
    glLightfv(GL_LIGHT7, GL_POSITION, this->position);
    glLightfv(GL_LIGHT7, GL_AMBIENT, this->ambient);
    glLightfv(GL_LIGHT7, GL_SPECULAR, this->specular);
    glLightfv(GL_LIGHT7, GL_DIFFUSE, this->diffuse);
}