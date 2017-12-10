#ifndef MODELISATEURGEOMETRIQUE_TESTCAMERA_H
#define MODELISATEURGEOMETRIQUE_TESTCAMERA_H


#include "Shapes/Camera.h"

class TestCamera {
private:
    Camera *camera;
public:
    TestCamera();

    void execute();

    void testGetPosition();

    void testSetPosition();

    void testGetDirection();

    void testSetDirection();
};


#endif //MODELISATEURGEOMETRIQUE_TESTCAMERA_H
