#include <iostream>
#include "Window.h"
#include "Shape.h"
#include "OFFReader.h"
#include "Label.h"
#include "TextInput.h"

int main(int argc, char **argv) {
	auto window = new Window(&argc, argv, "Projet image - Groupe 5", 600, 600);
	auto reader = OFFReader();
	window->add(reader.fromFile("../resources/teapot.off"));

	auto label = new Label(10, 10, "Teapot", 65, 22);
	window->addWidget(label);
	auto textInput = new TextInput(10, 42, 150, 22);
	window->addWidget(textInput);
	window->addListener(textInput);
	window->show();
	return EXIT_SUCCESS;
}