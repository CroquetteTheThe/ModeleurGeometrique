#pragma once

#include "Widget.h"
#include "Item.h"
#include "Pane.h"
#include <string>
#include <vector>
#include <map>


class ItemPane : public AbstractPane {
public:
    ItemPane(float x, float y, std::string title);

    void add(Drawable* drawable);
    bool notify(Event *e) override;

    void setItemSelected(Item* selected);

    Item *getItemSelected() const;

private:
    Item* itemSelected = nullptr;

    TextInput* xInput;
    TextInput* yInput;
    TextInput* zInput;

    void applyX(float newX);
    void applyY(float newY);
    void applyZ(float newZ);
    void add(Widget* widget);

};



