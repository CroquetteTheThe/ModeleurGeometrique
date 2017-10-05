#include <iostream>
#include "Window.h"
#include "Shape.h"
#include "OFFReader.h"
#include "Label.h"
#include "TextInput.h"
#include "Button.h"
#include "Pane.h"

int main(int argc, char **argv) {
	auto window = new Window(&argc, argv, "Projet image - Groupe 5", 600, 600);
	auto reader = OFFReader();

	auto pane = new Pane(10, 10);
	window->addWidget(pane);
	window->addListener(pane);

	auto label = new Label(10, 10, "Label", 65, 22);
	pane->add(label);

	auto textInput = new TextInput(10, 42, 10, 22);
	pane->add(textInput);

	auto button = new Button(10, 74, 150, 22, "Charger");
	button->bind([&]() {
		window->add(reader.fromFile(textInput->getText()));
	});
	pane->add(button);

	window->show();
	return EXIT_SUCCESS;
}