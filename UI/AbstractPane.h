//
#pragma once


#include <vector>
#include "Widget.h"
#include <string>
#include <functional>

class AbstractPane : public Widget {
public:
    AbstractPane(float x, float y, std::string title);

    void draw() override;

    bool contains(float x, float y) override;

    bool notify(Event *e) override;

protected:
    std::vector<Widget *> widgets;
    std::string title;
    bool selected;
    float marginLeft, marginTop, dx, dy;
};



