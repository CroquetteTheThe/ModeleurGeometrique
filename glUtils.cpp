
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include "glUtils.h"

void glutils::rectangle(int x, int y, int width, int height, Vector3d color){
	glColor3f(color.x, color.y, color.z);
	glBegin(GL_QUADS);
	glVertex3d(x, y, 0);
	glVertex3d(x + width, y, 0);
	glVertex3d(x + width, y + height, 0);
	glVertex3d(x, y + height, 0);
	glEnd();
}

void glutils::text(std::string text, int x, int y, Vector3d color){
	glColor3f(color.x, color.y, color.z);
	char *c;
	glRasterPos3f(x, y, 0);
	for (auto c: text) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
	}
}