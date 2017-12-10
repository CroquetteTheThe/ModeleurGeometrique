#include "Window.h"
#include "../Utils/Color.h"
#include "../Events/MouseClickEvent.h"
#include "../Events/KeyboardEvent.h"
#include "../Events/MouseMotionEvent.h"
//#include "../UI/ItemPane.h"
//#include "../Events/DrawableCreationEvent.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>

bool Window::leftButtonPressed = false;
int Window::x = 0;
int Window::y = 0;
int Window::angleX = 0;
int Window::angleY = 0;
int Window::width = 0;
int Window::height = 0;
const GLfloat mat_ambient[] = {0.7f, 0.7f, 0.7f, 1.0f};
const GLfloat mat_diffuse[] = {0.8f, 0.8f, 0.8f, 1.0f};
const GLfloat mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat high_shininess[] = {100.0f};
float Window::scaleFactor = 0.40;
std::vector<Drawable *> Window::drawables;
std::vector<Widget *> Window::widgets;
std::vector<EventListener *> Window::listeners;
GLenum Window::faceMode = GL_FILL;

Window::Window(int *pargc, char **argv, std::string title, int width, int height) {
    Window::width = width * 2 / 3;
    Window::height = height;
    glutInit(pargc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(100, 200);
    glutInitWindowSize(width * 2 / 3, height);
    glutCreateWindow(title.c_str());

    glClearColor(Color::grey.x, Color::grey.y, Color::grey.z, 0);
    glPointSize(2.0);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 4, 0, 0, 0, 0, 0, 1, 0);

    glutDisplayFunc(mainRender);
    glutKeyboardFunc(keyboardHandler);
    glutReshapeFunc(mainReshape);
    glutMouseFunc(mouseHandler);
    glutPassiveMotionFunc(passiveMouseMotionHandler);
    glutMotionFunc(mouseMotionHandler);


    glutInitWindowPosition(200 + Window::width, 200);
    glutCreateWindow(title.c_str());

    glClearColor(Color::grey.x, Color::grey.y, Color::grey.z, 0);
    glPointSize(2.0);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 4, 0, 0, 0, 0, 0, 1, 0);

    glutDisplayFunc(widgetRender);
    glutKeyboardFunc(keyboardHandler);
    glutReshapeFunc(widgetReshape);
    glutMouseFunc(mouseHandler);
    glutPassiveMotionFunc(passiveMouseMotionHandler);
    glutMotionFunc(mouseMotionHandler);

}

void Window::add(Drawable *drawable) {
    Window::drawables.push_back(drawable);/*
	auto e = DrawableCreationEvent(drawable);
	bool redisplay = false;
	for (auto listener : listeners) {
		redisplay |= listener->notify(&e);
	}
	if (redisplay) {
		glutPostRedisplay();
	}*/
}

void Window::mainRender() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_NORMALIZE);
    //glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glScalef(Window::scaleFactor * Window::height / Window::width, Window::scaleFactor, Window::scaleFactor);
    glRotatef(Window::angleY, 1.0, 0.0, 0.0);
    glRotatef(Window::angleX, 0.0, 1.0, 0.0);

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, high_shininess);

    glPolygonMode(GL_FRONT_AND_BACK, Window::faceMode);

    for (auto d: Window::drawables) {
        glPushMatrix();
        //glTranslatef(d->x, d->y, d->z);

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


void Window::widgetRender() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glShadeModel(GL_SMOOTH);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glScalef(Window::scaleFactor * Window::height / Window::width, Window::scaleFactor, Window::scaleFactor);
    glRotatef(Window::angleY, 1.0, 0.0, 0.0);
    glRotatef(Window::angleX, 0.0, 1.0, 0.0);


    glPolygonMode(GL_FRONT_AND_BACK, Window::faceMode);


    glPushMatrix();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glLoadIdentity();
    glOrtho(0.f, Window::width, Window::height, 0.f, 0.f, 1.f);
    for (auto widget : Window::widgets) {
        widget->draw();
    }
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}


void Window::keyboardHandler(unsigned char key, int x, int y) {
    auto e = KeyboardEvent(key);
    bool redisplay = false;
    for (auto listener : listeners) {
        redisplay |= listener->notify(&e);
    }
    if (redisplay)
        glutPostRedisplay();
    else {
        switch (key) {
            case 'l':
                Window::faceMode = GL_LINE;
                glutPostRedisplay();
                break;
            case 'p' :
                Window::faceMode = GL_POINT;
                glutPostRedisplay();
                break;
            case 'f' :
                Window::faceMode = GL_FILL;
                glutPostRedisplay();
                break;
            case 'q' :
                exit(EXIT_SUCCESS);
            default:
                break;
        }
    }
}

void Window::mainReshape(int x, int y) {
    glutReshapeWindow(width, height);
}

void Window::widgetReshape(int x, int y) {
    glutReshapeWindow(x, y);
}

void Window::mouseHandler(int button, int state, int x, int y) {

    MouseButton b;
    if (button == GLUT_LEFT_BUTTON)
        b = LEFT;
    else if (button == GLUT_RIGHT_BUTTON)
        b = RIGHT;
    else if (button == 3)
        b = WHEEL_UP;
    else if (button == 4)
        b = WHEEL_DOWN;
    else
        throw std::exception();

    auto e = MouseClickEvent(b, x, y, state == GLUT_DOWN);
    bool redisplay = false;
    for (auto listener : listeners) {
        redisplay |= listener->notify(&e);
    }
    if (redisplay) {
        glutPostRedisplay();
        return;
    }

    if (b == LEFT && state == GLUT_DOWN) {
        Window::leftButtonPressed = true;
        Window::x = x;
        Window::y = y;
    } else if (b == LEFT && state == GLUT_UP) {
        Window::leftButtonPressed = false;
    } else if (b == WHEEL_UP && state == GLUT_UP) {
        Window::scaleFactor += 0.02;
        glutPostRedisplay();
    } else if (b == WHEEL_DOWN && state == GLUT_UP) {
        Window::scaleFactor -= 0.02;
        glutPostRedisplay();
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
    auto e = MouseMotionEvent(x, y);
    bool redisplay = false;
    for (auto listener : listeners) {
        redisplay |= listener->notify(&e);
    }
    if (redisplay) glutPostRedisplay();

}

void Window::passiveMouseMotionHandler(int x, int y) {

    auto e = MouseMotionEvent(x, y);
    bool redisplay = false;
    for (auto listener : listeners) {
        redisplay |= listener->notify(&e);
    }
    if (redisplay) glutPostRedisplay();
}

void Window::show() {
    glutMainLoop();
}

void Window::addWidget(Widget *widget) {
    Window::widgets.emplace_back(widget);
}

void Window::addListener(EventListener *listener) {
    Window::listeners.emplace_back(listener);
}

const std::vector<Drawable *> &Window::getDrawables() {
    return drawables;
}