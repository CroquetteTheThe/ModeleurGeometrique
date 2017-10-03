#include <iostream>
#include "Window.h"
#include "Shape.h"
#include "OFFReader.h"
#include "Label.h"

int main(int argc, char **argv) {
	auto window = new Window(&argc, argv, "Projet image - Groupe 5", 600, 600);
	auto reader = OFFReader();
	window->add(reader.fromFile("../resources/teapot.off"));

	auto label = new Label(10, 10, "Teapot", 65, 22);
	window->addWidget(label);
	auto label2 = new Label(520, 568, "Bonjour", 70, 22, Color::purple, Color::white);
	window->addWidget(label2);
	window->show();
	return EXIT_SUCCESS;
}