#include <iostream>
#include "UI/Window.h"
#include "Shapes/Shape.h"
#include "Readers/OFFReader.h"
#include "UI/Label.h"
#include "UI/TextInput.h"
#include "UI/Button.h"
#include "UI/Pane.h"
#include "UI/Slider.h"
#include <fstream>

const int windowWidth = 1366;
const int windowHeight = 720;

int main(int argc, char **argv) {
	auto window = new Window(&argc, argv, "Projet image - Groupe 5", windowWidth, windowHeight);
	auto reader = OFFReader();


    auto itemPane = new ItemPane(10.f, 500.f, "Items");
    window->addWidget(itemPane);
    window->addListener(itemPane);

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
		std::cout << textInput << std::endl;
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



	window->show();
	return EXIT_SUCCESS;
}