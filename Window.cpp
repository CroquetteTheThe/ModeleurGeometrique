#include "Window.h"
#include "Color.h"
#include <GL/glut.h>

bool Window::leftButtonPressed = false;
int Window::x = 0;
int Window::y = 0;
int Window::angleX = 0;
int Window::angleY = 0;
double Window::scaleFactor = 0.40;
std::vector<Drawable *> Window::drawables;

Window::Window(int *pargc, char **argv, std::string title, int width, int height) {
	glutInit(pargc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(width, height);
	glutCreateWindow(title.c_str());

	glClearColor(Color::grey.x, Color::grey.y, Color::grey.z, 0);
	glPointSize(2.0);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 4, 0, 0, 0, 0, 0, 1, 0);

	glutDisplayFunc(render);
	glutKeyboardFunc(keyboardHandler);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouseHandler);
	glutMotionFunc(mouseMotionHandler);

}

void Window::add(Drawable *drawable) {
	Window::drawables.push_back(drawable);
}

void Window::render() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glScalef(Window::scaleFactor, Window::scaleFactor, Window::scaleFactor);
	glRotatef(Window::angleY, 1.0, 0.0, 0.0);
	glRotatef(Window::angleX, 0.0, 1.0, 0.0);


	for (auto d: Window::drawables) {
		glPushMatrix();
		d->draw();
		glPopMatrix();
	}

	//x axis
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0, 0, 0.0);
	glVertex3f(1, 0, 0.0);
	glEnd();
	//y axis
	glBegin(GL_LINES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0, 0, 0.0);
	glVertex3f(0, 1, 0.0);
	glEnd();
	//z axis
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0, 0, 0.0);
	glVertex3f(0, 0, 1.0);
	glEnd();

	glFlush();
	glutSwapBuffers();
}

void Window::keyboardHandler(unsigned char key, int x, int y) {
	switch (key) {
		case 'l':
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			glutPostRedisplay();
			break;
		case 'p' :
			glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
			glutPostRedisplay();
			break;
		case 'f' :
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glutPostRedisplay();
			break;
		case 'q' :
			exit(EXIT_SUCCESS);
		default:
			break;
	}
}

void Window::reshape(int x, int y) {
	if (x < y)
		glViewport(0, (y - x) / 2, x, x);
	else
		glViewport((x - y) / 2, 0, y, y);
}

void Window::mouseHandler(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		Window::leftButtonPressed = true;
		Window::x = x;
		Window::y = y;
	} else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		Window::leftButtonPressed = false;
	} else if (button == 3 && state == GLUT_UP) {
		Window::scaleFactor += 0.02;
	} else if (button == 4 && state == GLUT_UP) {
		Window::scaleFactor -= 0.02;
	}
}

void Window::mouseMotionHandler(int x, int y) {
	if (Window::leftButtonPressed) {
		Window::angleX += (x - Window::x);
		Window::angleY += (y - Window::y);
		glutPostRedisplay();
	}

	Window::x = x;
	Window::y = y;
}

void Window::show() {
	glutMainLoop();
}