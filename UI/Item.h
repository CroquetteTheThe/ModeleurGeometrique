#pragma once

#include "Widget.h"
#include "Label.h"
#include "Button.h"
#include "TextInput.h"
#include <string>
#include <vector>
#include <map>

/**
 * An Item is a widget which is a line of an ItemPane
 * It aims to move drawables
 */

class Item : public Label {
public:
    Item(Drawable* drawable, float x, float y, const std::string &label);

    Drawable* getDrawable();

    void setSelected(bool selected);
    bool isSelected();

private:
    Drawable* drawable;
    bool selected;
};