#pragma once

#include <GLFW/glfw3.h>
#include "Drawable.h"
#include "Widget.h"
#include <string>
#include <vector>

/**
 * A glut window
 */
class Window {
public:
	explicit Window(int *pargc, char **argv, std::string title, int width, int height);

	void show();

	/**
	 * Adds a drawable to render
	 * @param drawable the drawable to add to the lsit
	 */
	void add(Drawable *drawable);

	void addWidget(Widget *widget);

	void addListener(EventListener *listener);

private:
	GLFWwindow *window;
	static std::vector<Drawable *> drawables;
	static std::vector<Widget *> widgets;
	static std::vector<EventListener *> listeners;
	static bool leftButtonPressed;
	static int angleX, angleY, x, y, width, height;
	static double scaleFactor;
	static GLenum faceMode;

	static void render();

	static void keyboardHandler(unsigned char key, int x, int y);

	static void reshape(int x, int y);

	static void mouseHandler(int button, int state, int x, int y);

	static void mouseMotionHandler(int x, int y);

};