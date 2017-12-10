#include "TestCamera.h"


TestCamera::TestCamera() {
    this->camera = new Camera(Vector3f({1.0, 1.0, 1.0}), Vector3f{1.0, 0.0, 0.0});
}

void TestCamera::execute() {
    this->testGetPosition();
    this->testSetPosition();
    this->testGetDirection();
    this->testSetDirection();
}

/* Position initialized at 1.0,1.0,1.0, so position.x, position.y and position.z should be 1.0 */

void TestCamera::testGetPosition() {
    printf("\n###### Test getPosition ######\n");

    bool res = true;
    Vector3f position = this->camera->getPosition();

    if (position.x != 1.0) {
        res = false;
        printf("Test failed : position in X is : %f\n", position.x);
    }
    if (position.y != 1.0) {
        res = false;
        printf("Test failed : position in Y is : %f\n", position.y);
    }
    if (position.z != 1.0) {
        res = false;
        printf("Test failed : position in Z is : %f\n", position.z);
    }
    if (res) {
        printf("Position is correct, test passed\n");
    }

    printf("##############################\n");
}

/* Change the position of the camera thanks to setPosition and then verifying the new position */
void TestCamera::testSetPosition() {
    printf("\n###### Test setPosition ######\n");

    bool res = true;
    Vector3f newPosition = {(float) -0.2, 1.5, (float) -0.5};

    this->camera->setPosition(newPosition);

    if (this->camera->getPosition().x != newPosition.x) {
        res = false;
        printf("Test failed : position of the camera in X is : %f\n", this->camera->getPosition().x);
    }
    if (this->camera->getPosition().y != newPosition.y) {
        res = false;
        printf("Test failed : position of the camera in Y is : %f\n", this->camera->getPosition().y);
    }
    if (this->camera->getPosition().z != newPosition.z) {
        res = false;
        printf("Test failed : position of the camera in Z is : %f\n", this->camera->getPosition().z);
    }

    if (res) {
        printf("Position has been successfully changed, test passed\n");
    }
    printf("##############################\n");
}

/* By default the direction is initialized at 0.0, 0.0, 0.0, so direction.x, direction.y and direction.z should be 0.0 */

void TestCamera::testGetDirection() {

    printf("\n###### Test getDirection ######\n");

    bool res = true;
    Vector3f direction = this->camera->getDirection();

    if (direction.x != 0.0) {
        res = false;
        printf("Test failed : direction in X is : %f\n", direction.x);
    }
    if (direction.y != 0.0) {
        res = false;
        printf("Test failed : direction in Y is : %f\n", direction.y);
    }
    if (direction.z != 0.0) {
        res = false;
        printf("Test failed : direction in Z is : %f\n", direction.z);
    }
    if (res) {
        printf("Direction is correct, test passed\n");
    }
    printf("##############################\n");
}

/* Change the direction of the camera thanks to setDirection and then verifying the new direction */
void TestCamera::testSetDirection() {
    bool res = true;

    Vector3f newDirection = {(float) -0.2, 1.5, (float) -0.5};

    this->camera->setDirection(newDirection);

    printf("\n###### Test setDirection ######\n");
    if (this->camera->getDirection().x != newDirection.x) {
        res = false;
        printf("Test failed : direction of the camera in X is : %f\n", this->camera->getDirection().x);
    }
    if (this->camera->getDirection().y != newDirection.y) {
        res = false;
        printf("Test failed : direction of the camera in Y is : %f\n", this->camera->getDirection().y);
    }
    if (this->camera->getDirection().z != newDirection.z) {
        res = false;
        printf("Test failed : direction of the camera in Z is : %f\n", this->camera->getDirection().z);
    }

    if (res) {
        printf("Direction has been successfully changed, test passed\n");
    }
    printf("##############################\n");
}