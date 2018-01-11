#include <algorithm>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#endif
#include <iostream>
#include <sstream>
#include "ItemPane.h"
#include "../Events/MouseClickEvent.h"
#include "../Events/DrawableCreationEvent.h"
#include "../Events/DrawableDestroyEvent.h"


//src: https://stackoverflow.com/a/19751887
bool isFloat(const std::string& string){
    std::string::const_iterator it = string.begin();
    bool decimalPoint = false;
    int minSize = 0;
    if(!string.empty() && (string[0] == '-' || string[0] == '+')){
        it++;
        minSize++;
    }
    while(it != string.end()){
        if(*it == '.'){
            if(!decimalPoint) decimalPoint = true;
            else break;
        }else if(!std::isdigit(*it) && ((*it!='f') || it+1 != string.end() || !decimalPoint)){
            break;
        }
        ++it;
    }
    return string.size()>minSize && it == string.end();
}

ItemPane::ItemPane(float x, float y, std::string title) : AbstractPane(x, y, std::move(title)) {
    xInput = new TextInput(x+50.f, y, 8, 22.f);
    xInput->setOnEnter([&]() {
        if (isFloat(xInput->getText())) {
            applyX(std::stof(xInput->getText()));
        }
    });
    xInput->setText("x");
    add(xInput);
    yInput = new TextInput(x+80.f, y, 8, 22.f);
    yInput->setOnEnter([&]() {
        if (isFloat(yInput->getText())) {
            applyY(std::stof(yInput->getText()));
        }
    });
    yInput->setText("y");
    add(yInput);
    zInput = new TextInput(x+110.f, y, 8, 22.f);
    zInput->setOnEnter([&]() {
        if (isFloat(zInput->getText())) {
            applyZ(std::stof(zInput->getText()));
        }
    });
    zInput->setText("z");
    add(zInput);
    auto apply = new Button(x+140, y, 45, 22, "Ok");
    apply->bind([&]() {
        if (isFloat(xInput->getText()) && isFloat(yInput->getText()) && isFloat(zInput->getText())) {
            applyX(std::stof(xInput->getText()));
            applyY(std::stof(yInput->getText()));
            applyZ(std::stof(zInput->getText()));
        }
    });
    add(apply);
}

void ItemPane::add(Drawable *drawable) {
    DrawableType type = drawable->getType();
    int nbType = 1;
    for (int i = 5; i < widgets.size(); i++) {
        auto item = dynamic_cast<Item *>(widgets[i]);
        if (item->getDrawable()->getType() == type) {
            nbType++;
        }
    }
    std::string title;
    if (type == SHAPE) {
        title = "Shape " + std::to_string(nbType);
    }
    if (type == CAMERA) {
        title = "Camera " + std::to_string(nbType);
    }
    if (type == LIGHT) {
        title = "Light " + std::to_string(nbType);
    }
    auto newItem = new Item(drawable, x+22*(widgets.size() -5), y, title);
    add(newItem);
}



bool ItemPane::notify(Event *e) {

    bool res = false;
    if (e->getType() == MOUSE_CLICK_EVENT) {
        auto clickEvent = dynamic_cast<MouseClickEvent *>(e);
        if (clickEvent->getButton() == LEFT && clickEvent->isDown()) {
            for (int i = 5; i < widgets.size(); i++) {
                auto item = dynamic_cast<Item *>(widgets[i]);
                if (item->contains(clickEvent->getX(), clickEvent->getY())) {
                    if (itemSelected == item) {
                        setItemSelected(nullptr);
                    }
                    else {
                        setItemSelected(item);
                    }
                    res = true; //When the item is the same as before, we haven't to redraw
                    break;
                }
            }

        }
    }

    if (e->getType() == DRAWABLE_CREATION_EVENT) {
        auto creationEvent = dynamic_cast<DrawableCreationEvent *>(e);
        add(creationEvent->getNewDrawable());
        res = true;
    }
    if (e->getType() == DRAWABLE_DESTROY_EVENT) {
        auto destroyEvent = dynamic_cast<DrawableDestroyEvent *>(e);
        for (int i=5; i<widgets.size(); i++) {
            auto item = dynamic_cast<Item *>(widgets[i]);
            if (item->getDrawable() == destroyEvent->getDrawable()) {
                if (itemSelected == item) {
                    setItemSelected(nullptr);
                }
                widgets.erase(std::remove(widgets.begin(), widgets.end(), item), widgets.end());
                break;
            }
        }
    }
    return AbstractPane::notify(e) || res;
}

void ItemPane::applyX(float newX) {
    if (itemSelected != nullptr) {
            itemSelected->getDrawable()->x = newX;
    }
}

void ItemPane::applyY(float newY) {
    if (itemSelected != nullptr) {
        itemSelected->getDrawable()->y = newY;
    }
}

void ItemPane::applyZ(float newZ) {
    if (itemSelected != nullptr) {
        itemSelected->getDrawable()->z = newZ;
    }
}

void ItemPane::setItemSelected(Item *selected) {
    if (itemSelected != nullptr) {
        itemSelected->setSelected(false);
    }

    itemSelected = selected;

    auto xInput = dynamic_cast<TextInput *>(widgets[1]);
    auto yInput = dynamic_cast<TextInput *>(widgets[2]);
    auto zInput = dynamic_cast<TextInput *>(widgets[3]);
    if (itemSelected == nullptr) {
        xInput->setText("x");
        yInput->setText("y");
        zInput->setText("z");
    }
    else {
        xInput->setText(std::to_string(selected->getDrawable()->x));
        yInput->setText(std::to_string(selected->getDrawable()->y));
        zInput->setText(std::to_string(selected->getDrawable()->z));
        itemSelected->setSelected(true);
    }
}


void ItemPane::add(Widget *widget) {
    widgets.emplace_back(widget);
    widget->x = x + marginLeft;
    widget->y = y + marginTop + height;
    height += marginTop + widget->height;
    width = (*std::max_element(widgets.begin(), widgets.end(),
                               [](Widget *a, Widget *b) { return a->width < b->width; }))->width + 10;
    widgets[0]->width = width;
}

Item *ItemPane::getItemSelected() const {
    return itemSelected;
}
