
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include "glUtils.h"

void glutils::rectangle(int x, int y, int width, int height, Vector3d color) {
	glColor3f(color.x, color.y, color.z);

	glBegin(GL_QUADS);
	glVertex3d(x, y, 0);
	glVertex3d(x + width, y, 0);
	glVertex3d(x + width, y + height, 0);
	glVertex3d(x, y + height, 0);
	glEnd();
}

void glutils::roundedRectangle(int x, int y, int width, int height, int radius, Vector3d color) {
	glColor3f(color.x, color.y, color.z);

	glBegin(GL_QUADS);
	glVertex3d(x + radius, y + radius, 0);
	glVertex3d(x + width - radius, y + radius, 0);
	glVertex3d(x + width - radius, y + height - radius, 0);
	glVertex3d(x + radius, y + height - radius, 0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3d(x + radius, y, 0);
	glVertex3d(x + width - radius, y, 0);
	glVertex3d(x + width - radius, y + radius, 0);
	glVertex3d(x + radius, y + radius, 0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3d(x, y + radius, 0);
	glVertex3d(x + radius, y + radius, 0);
	glVertex3d(x + radius, y + height - radius, 0);
	glVertex3d(x, y + height - radius, 0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3d(x + radius, y + height - radius, 0);
	glVertex3d(x + width - radius, y + height - radius, 0);
	glVertex3d(x + width - radius, y + height, 0);
	glVertex3d(x + radius, y + height, 0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3d(x + width - radius, y + radius, 0);
	glVertex3d(x + width, y + radius, 0);
	glVertex3d(x + width, y + height - radius, 0);
	glVertex3d(x + width - radius, y + height - radius, 0);
	glEnd();

	//top left corner
	glBegin(GL_TRIANGLE_FAN);
	glVertex3d(x + radius, y + radius, 0);
	for (double theta = M_PI; theta >= M_PI / 2; theta -= M_PI / 20) {
		glVertex3d(x + radius + radius * cos(theta), y + radius - radius * sin(theta), 0);
	}
	glEnd();

	//top right corner
	glBegin(GL_TRIANGLE_FAN);
	glVertex3d(x + width - radius, y + radius, 0);
	for (double theta = M_PI / 2; theta >= 0; theta -= M_PI / 20) {
		glVertex3d(x + width - radius + radius * cos(theta), y + radius - radius * sin(theta), 0);
	}
	glEnd();

	//bottom right corner
	glBegin(GL_TRIANGLE_FAN);
	glVertex3d(x + width - radius, y + height - radius, 0);
	for (double theta = 3 * M_PI / 2; theta <= 2 * M_PI; theta += M_PI / 20) {
		glVertex3d(x + width - radius + radius * cos(theta), y + height - radius - radius * sin(theta), 0);
	}
	glEnd();

	//bottom left corner
	glBegin(GL_TRIANGLE_FAN);
	glVertex3d(x + radius, y + height - radius, 0);
	for (double theta = M_PI; theta <= 3 * M_PI / 2; theta += M_PI / 20) {
		glVertex3d(x + radius + radius * cos(theta), y + height - radius - radius * sin(theta), 0);
	}
	glEnd();

}


void glutils::text(std::string text, int x, int y, Vector3d color) {
	glColor3f(color.x, color.y, color.z);
	char *c;
	glRasterPos3f(x, y, 0);
	for (auto c: text) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
	}
}