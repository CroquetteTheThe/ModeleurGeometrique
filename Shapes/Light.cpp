#ifdef __APPLE__
#include <GLUT/glut.h>
#else

#include <GL/glut.h>

#endif

#include "Light.h"
#include "../Readers/OFFReader.h"

void Light::draw() {

    glPushMatrix();
    glTranslatef(this->position[0], this->position[1], this->position[2]);
    this->model->draw();
    //printf("Positions : %f %f %f",this->position[0],this->position[1],this->position[2]);

    glPopMatrix();

    // glPushMatrix();
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, this->position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, this->ambient);
    glLightfv(GL_LIGHT0, GL_SPECULAR, this->specular);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, this->diffuse);

    // glPopMatrix();


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

Light::Light(const Vector3f &color, float x, float y, float z) : Drawable(color) {
    this->position[0] = x;
    this->position[1] = y;
    this->position[2] = z;
    auto reader = OFFReader();
    this->model = reader.fromFile("../resources/seashell.off");
    this->model->setColor(color);
}