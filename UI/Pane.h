#pragma once


#include <vector>
#include "Widget.h"
#include "AbstractPane.h"
#include <string>
#include <functional>

class Pane : public AbstractPane {
public:
	Pane(float x, float y, std::string title);

	void add(Widget *widget);

};



