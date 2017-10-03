#include <iostream>
#include "Window.h"
#include "Shape.h"
#include "OFFReader.h"
#include "Label.h"
#include "TextInput.h"
#include "Button.h"

int main(int argc, char **argv) {
	auto window = new Window(&argc, argv, "Projet image - Groupe 5", 600, 600);
	auto reader = OFFReader();

	auto label = new Label(10, 10, "../resources/teapot.off", 65, 22);
	window->addWidget(label);
	auto textInput = new TextInput(10, 42, 150, 22);
	window->addWidget(textInput);
	window->addListener(textInput);

	auto button = new Button(10, 74, 150, 22, "Charger");
	button->bind([&]() {
		window->add(reader.fromFile(textInput->getText()));
	});
	window->addWidget(button);
	window->addListener(button);

	window->show();
	return EXIT_SUCCESS;
}