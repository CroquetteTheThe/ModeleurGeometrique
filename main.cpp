#include <iostream>
#include "UI/Window.h"
#include "Shapes/Shape.h"
#include "Shapes/Camera.h"
#include "Readers/OFFReader.h"
#include "UI/Slider.h"
#include "Shapes/Light.h"
#include "TestLight.h"
#include "TestCamera.h"
#include <fstream>

const int windowWidth = 1366;
const int windowHeight = 720;

int main(int argc, char **argv) {

	/* Test Lights */
	TestLight testL = TestLight();
	testL.runTestLight();

	/* Test Camera */
	TestCamera *testCam = new TestCamera();
	testCam->execute();

	auto window = new Window(&argc, argv, "Projet image - Groupe 5", windowWidth, windowHeight);
	auto reader = OFFReader();

    int nbLights = 0;
	auto itemPane = new ItemPane(520, 10, "Items");
    window->addWidget(itemPane);
    window->addListener(itemPane);

	auto colorPane = new Pane(10, 160, "Color");
	window->addWidget(colorPane);
	window->addListener(colorPane);

	auto sliderRed = new Slider(0, 0, 100, 20, 0, 255, 255);
	sliderRed->setOnChange([&](int newValue) {
		if (window->getDrawables().empty()) return;
		auto color = window->getDrawables()[0]->getColor();
		color.x = newValue / 255.0f;
		window->getDrawables()[0]->setColor(color);
	});
	colorPane->add(new Label(10, 10, "Red", 65, 22));
	colorPane->add(sliderRed);

	auto sliderGreen = new Slider(0, 0, 100, 20, 0, 255, 255);
	sliderGreen->setOnChange([&](int newValue) {
		if (window->getDrawables().empty()) return;
		auto color = window->getDrawables()[0]->getColor();
		color.y = newValue / 255.0f;
		window->getDrawables()[0]->setColor(color);
	});
	colorPane->add(new Label(10, 10, "Green", 65, 22));
	colorPane->add(sliderGreen);

	auto sliderBlue = new Slider(0, 0, 100, 20, 0, 255, 255);
	sliderBlue->setOnChange([&](int newValue) {
		if (window->getDrawables().empty()) return;
		auto color = window->getDrawables()[0]->getColor();
		color.z = newValue / 255.0f;
		window->getDrawables()[0]->setColor(color);
	});
	colorPane->add(new Label(10, 10, "Blue", 65, 22));
	colorPane->add(sliderBlue);

	auto pane = new Pane(10, 10, "Load");
	window->addWidget(pane);
	window->addListener(pane);

	auto label = new Label(10, 10, "Fichier", 65, 22);
	pane->add(label);

	auto statusBar = new Label(0, windowHeight - 22, "", windowWidth, 22);
	window->addWidget(statusBar);

	auto textInput = new TextInput(10, 42, 10, 22);
	textInput->setOnEnter([&]() {
		try {
			auto shape = reader.fromFile(textInput->getText());
			window->add(shape);
			statusBar->setText("");
			auto red = sliderRed->getCurrent() / 255.0f;
			auto green = sliderGreen->getCurrent() / 255.0f;
			auto blue = sliderBlue->getCurrent() / 255.0f;
			shape->setColor({red, green, blue});
		} catch (const std::exception &e) {
			statusBar->setText("Le fichier n'existe pas");
		}
	});
	pane->add(textInput);

	auto button = new Button(10, 74, 85, 22, "Charger");
	button->bind([&]() {
		try {
			auto shape = reader.fromFile(textInput->getText());
			window->add(shape);
			statusBar->setText("");
			auto red = sliderRed->getCurrent() / 255.0f;
			auto green = sliderGreen->getCurrent() / 255.0f;
			auto blue = sliderBlue->getCurrent() / 255.0f;
			shape->setColor({red, green, blue});
		} catch (const std::exception &e) {
			statusBar->setText("Le fichier n'existe pas");
		}
	});
	pane->add(button);

    /* Light Pane*/
	auto lightPane = new Pane(200, 10, "Light");
    window->addWidget(lightPane);
    window->addListener(lightPane);
    lightPane->add(new Label(10, 10, "Position X", 65, 22));
    auto xInput = new TextInput(10, 42, 10, 22);
    lightPane->add(xInput);
    lightPane->add(new Label(10, 10, "Position Y", 65, 22));
    auto yInput = new TextInput(10, 55, 10, 22);
    lightPane->add(yInput);
    lightPane->add(new Label(10, 10, "Position Z", 65, 22));
    auto zInput = new TextInput(10, 65, 10, 22);
    lightPane->add(zInput);

    lightPane->add(new Label(10, 10, "Ambient :", 65, 22));
    auto sRA = new Slider(0, 0, 100, 20, 0, 255, 0);
    sRA->setOnChange([&](int newValue) { return; });
    auto sGA = new Slider(0, 0, 100, 20, 0, 255, 0);
    sGA->setOnChange([&](int newValue) { return; });
    auto sBA = new Slider(0, 0, 100, 20, 0, 255, 0);
    sBA->setOnChange([&](int newValue) { return; });
    lightPane->add(sRA);
    lightPane->add(sGA);
    lightPane->add(sBA);

    lightPane->add(new Label(10, 10, "Diffuse :", 65, 22));
    auto sRD = new Slider(0, 0, 100, 20, 0, 255, 255);
    sRD->setOnChange([&](int newValue) { return; });
    auto sGD = new Slider(0, 0, 100, 20, 0, 255, 255);
    sGD->setOnChange([&](int newValue) { return; });
    auto sBD = new Slider(0, 0, 100, 20, 0, 255, 255);
    sBD->setOnChange([&](int newValue) { return; });
    lightPane->add(sRD);
    lightPane->add(sGD);
    lightPane->add(sBD);

    lightPane->add(new Label(10, 10, "Specular :", 65, 22));
    auto sRS = new Slider(0, 0, 100, 20, 0, 255, 255);
    sRS->setOnChange([&](int newValue) { return; });
    auto sGS = new Slider(0, 0, 100, 20, 0, 255, 255);
    sGS->setOnChange([&](int newValue) { return; });
    auto sBS = new Slider(0, 0, 100, 20, 0, 255, 255);
    sBS->setOnChange([&](int newValue) { return; });
    lightPane->add(sRS);
    lightPane->add(sGS);
    lightPane->add(sBS);

    auto lightButton = new Button(10, 74, 85, 22, "Placer");
    lightButton->bind([&]() {
        try {
            auto redAmb = sRA->getCurrent() / 255.0f;
            auto greenAmb = sGA->getCurrent() / 255.0f;
            auto blueAmb = sBA->getCurrent() / 255.0f;
            auto redDiff = sRD->getCurrent() / 255.0f;
            auto greenDiff = sGD->getCurrent() / 255.0f;
            auto blueDiff = sBD->getCurrent() / 255.0f;
            auto redSpec = sRS->getCurrent() / 255.0f;
            auto greenSpec = sGS->getCurrent() / 255.0f;
            auto blueSpec = sBS->getCurrent() / 255.0f;
            if (nbLights < 8) {

                auto light = new Light(Vector3f(.0, .5, .5), stof(xInput->getText()), stof(yInput->getText()),
                                       stof(zInput->getText()), redAmb, greenAmb, blueAmb, redDiff, greenDiff, blueDiff,
                                       redSpec, greenSpec, blueSpec, nbLights);
                window->add(light);
                nbLights++;
            } else {
                statusBar->setText("Vous avez atteint le nombre maximum de lumières (8)");
            }

            /*if (!enableLights) {
                glEnable(GL_LIGHTING);
            }*/


        } catch (const std::exception &e) {

        }
    });
    lightPane->add(lightButton);

	auto camera = new Camera(Vector3f(1.f, 1.f, 1.f), {0.5,0.5,0.5});
	window->add(camera);

	auto cameraPane = new Pane(10, 400, "Camera");
	window->addWidget(cameraPane);
	window->addListener(cameraPane);

	auto cameraX = new TextInput(10, 42, 10, 22);
	cameraPane->add(new Label(10, 10, "X", 65, 22));
	cameraPane->add(cameraX);

	auto cameraY = new TextInput(10, 42, 10, 22);
	cameraPane->add(new Label(10, 10, "Y", 65, 22));
	cameraPane->add(cameraY);

	auto cameraZ = new TextInput(10, 42, 10, 22);

	cameraPane->add(new Label(10, 10, "Z", 65, 22));
	cameraPane->add(cameraZ);

    auto buttonCamDirection = new Button(10, 74, 85, 22, "Direction");
    buttonCamDirection->bind([&]() {

        auto direction = camera->getDirection();
        direction.x = stof(cameraX->getText());
        direction.y = stof(cameraY->getText());
        direction.z = stof(cameraZ->getText());
        camera->setDirection(direction);
        //window->add(camera);
        camera->draw();
    });
    cameraPane->add(buttonCamDirection);

	window->show();
	return EXIT_SUCCESS;
}