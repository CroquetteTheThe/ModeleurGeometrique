#include <iostream>
#include "UI/Window.h"
#include "Shapes/Shape.h"
#include "Readers/OFFReader.h"
#include "UI/Label.h"
#include "UI/TextInput.h"
#include "UI/Button.h"
#include "UI/Pane.h"
#include "UI/Slider.h"
#include "Shapes/Light.h"
#include <fstream>

const int windowWidth = 1366;
const int windowHeight = 720;

int main(int argc, char **argv) {
	auto window = new Window(&argc, argv, "Projet image - Groupe 5", windowWidth, windowHeight);
	auto reader = OFFReader();
    bool enableLights = false;
    int nbLights = 0;

	auto colorPane = new Pane(10, 200, "Color");
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
    auto lightPane = new Pane(10, 430, "Light");
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

    auto lightButton = new Button(10, 74, 85, 22, "Placer");
    lightButton->bind([&]() {
        try {
            if (nbLights < 8) {
                auto light = new Light(Vector3f(.0, .5, .5), stof(xInput->getText()), stof(yInput->getText()),
                                       stof(zInput->getText()), nbLights);
                window->add(light);
                nbLights++;
            } else {
                statusBar->setText("Vous avez atteint le nombre maximum de lumières (8)");
            }

            if (!enableLights) {
                glEnable(GL_LIGHTING);
            }


        } catch (const std::exception &e) {

        }
    });
    lightPane->add(lightButton);


	window->show();
	return EXIT_SUCCESS;
}