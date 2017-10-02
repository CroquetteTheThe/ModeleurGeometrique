#include <iostream>
#include "Window.h"

int main(int argc, char **argv) {
	auto window = new Window(&argc, argv, "TP1 - Orval Touitou", 600, 600);
	window->show();
	return EXIT_SUCCESS;
}