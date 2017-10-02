#pragma once

#include <GLFW/glfw3.h>
#include "Drawable.h"
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

private:
	GLFWwindow *window;
	static std::vector<Drawable *> drawables;
	static bool leftButtonPressed;
	static int angleX, angleY, x, y;
	static double scaleFactor;

	static void render();

	static void keyboardHandler(unsigned char key, int x, int y);

	static void reshape(int x, int y);

	static void mouseHandler(int button, int state, int x, int y);

	static void mouseMotionHandler(int x, int y);

};