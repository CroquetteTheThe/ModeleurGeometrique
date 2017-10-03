#pragma once


#include "Widget.h"
#include "Label.h"
#include <string>

class TextInput : public Widget {
public:
	TextInput(double x, double y, double width, double height);

	bool notify(Event *e) override;

	const std::string &getText() const;

	bool contains(int x, int y) override;

	void draw() override;

	void setSelected(bool selected);

private:
	Label label;
	bool enabled, selected;
};


