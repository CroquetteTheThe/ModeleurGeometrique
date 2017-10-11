#pragma once


#include <functional>
#include "Widget.h"
#include "Label.h"

class Button : public Widget {
public:
	Button(int x, int y, int width, int height, std::string text);

	void bind(const std::function<void(void)> &f);

	bool notify(Event *e) override;

	bool contains(int x, int y) override;

	void draw() override;

private:
	std::string text;
	std::function<void(void)> onClick;
	bool hover;
};


