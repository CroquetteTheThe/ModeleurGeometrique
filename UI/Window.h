#pragma once

#include <GLFW/glfw3.h>
#include "../Shapes/Drawable.h"
#include "Widget.h"
#include "ItemPane.h"
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

	static const std::vector<Drawable *> &getDrawables();

	void addWidget(Widget *widget);

	void addListener(EventListener *listener);

private:
	GLFWwindow *window;

	static std::vector<Drawable *> drawables;
	static std::vector<Widget *> widgets;
	static std::vector<EventListener *> listeners;
	static bool leftButtonPressed;
	static int angleX, angleY, x, y, width, height;
	static float scaleFactor;
	static GLenum faceMode;

	static void mainRender();

	static void widgetRender();

	static void keyboardHandler(unsigned char key, int x, int y);

	static void mainReshape(int x, int y);

	static void widgetReshape(int x, int y);

	static void mouseHandler(int button, int state, int x, int y);

	static void mouseMotionHandler(int x, int y);

	static void passiveMouseMotionHandler(int x, int y);
};