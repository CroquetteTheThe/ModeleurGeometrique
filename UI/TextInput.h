#pragma once


#include "Widget.h"
#include "Label.h"
#include <string>
#include <functional>

class TextInput : public Widget {
public:
	TextInput(float x, float y, int size, float height);

	bool notify(Event *e) override;

	const std::string &getText() const;

	bool contains(float x, float y) override;

	void draw() override;

	void setOnEnter(const std::function<void()> &onEnter);

	void setText(std::string text);

private:
	int size;
	bool enabled, selected;
	std::function<void(void)> onEnter;
	std::string text;
	Vector3f bgColor, color;
};


