#include "Item.h"
#include "../Utils/glUtils.h"
#include "../Events/MouseClickEvent.h"
#include <GL/gl.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <iostream>

#endif

Item::Item(Drawable *drawable, float x, float y, const std::string &label) : Label(x, y, label, 110, 20), drawable(drawable), selected(false) {
}


Drawable* Item::getDrawable() {
    return drawable;
}

void Item::setSelected(bool selected) {
    this->selected = selected;
    if (selected) {
        setBgColor(Vector3f(175.f / 255.f, 175.f / 255.f, 175.f / 255.f));
    }
    else {
        setBgColor(Vector3f(46.f / 255.f, 46.f / 255.f, 46.f / 255.f));
    }
}

bool Item::isSelected() {
    return selected;
}

