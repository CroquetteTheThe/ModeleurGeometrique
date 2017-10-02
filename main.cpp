#include <iostream>
#include "Window.h"
#include "Color.h"
#include "Shape.h"

int main(int argc, char **argv) {
	auto window = new Window(&argc, argv, "TP1 - Orval Touitou", 600, 600);

	auto shape = new Shape(Color::purple);
	shape->addPoint({0, 0, 0});
	shape->addPoint({1, 0, 0});
	shape->addPoint({0.5, 1, 0});
	shape->addFace({1, 2, 3});
	window->add(shape);
	window->show();
	return EXIT_SUCCESS;
}