#include <iostream>
#include "Window.h"
#include "Shape.h"
#include "OFFReader.h"
#include "Label.h"
#include "TextInput.h"
#include "Button.h"
#include "Pane.h"
#include <fstream>

int main(int argc, char **argv) {
	auto window = new Window(&argc, argv, "Projet image - Groupe 5", 600, 600);
	auto reader = OFFReader();

	auto pane = new Pane(10, 10, "Load");
	window->addWidget(pane);
	window->addListener(pane);

	auto label = new Label(10, 10, "Fichier", 65, 22);
	pane->add(label);

	auto textInput = new TextInput(10, 42, 10, 22);
	pane->add(textInput);

	auto statusBar = new Label(0, 600 - 22, "", 600, 22);
	window->addWidget(statusBar);

	auto button = new Button(10, 74, 85, 22, "Charger");
	button->bind([&]() {
		try {
			window->add(reader.fromFile(textInput->getText()));
			statusBar->setText("");
		} catch (const std::exception &e) {
			statusBar->setText("Le fichier n'existe pas");
		}
	});
	pane->add(button);

	window->show();
	return EXIT_SUCCESS;
}