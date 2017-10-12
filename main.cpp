#include <iostream>
#include "UI/Window.h"
#include "Shapes/Shape.h"
#include "Readers/OFFReader.h"
#include "UI/Label.h"
#include "UI/TextInput.h"
#include "UI/Button.h"
#include "UI/Pane.h"
#include <fstream>

int main(int argc, char **argv) {
	auto window = new Window(&argc, argv, "Projet image - Groupe 5", 600, 600);
	auto reader = OFFReader();

	auto pane = new Pane(10, 10, "Load");
	window->addWidget(pane);
	window->addListener(pane);

	auto label = new Label(10, 10, "Fichier", 65, 22);
	pane->add(label);

	auto statusBar = new Label(0, 600 - 22, "", 600, 22);
	window->addWidget(statusBar);

	auto textInput = new TextInput(10, 42, 10, 22);
	textInput->setOnEnter([&]() {
		try {
			window->add(reader.fromFile(textInput->getText()));
			statusBar->setText("");
		} catch (const std::exception &e) {
			statusBar->setText("Le fichier n'existe pas");
		}
	});
	pane->add(textInput);

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