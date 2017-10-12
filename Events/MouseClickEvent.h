#pragma once


#include "Event.h"
#include "MouseButton.h"

class MouseClickEvent : public Event {
public:
	MouseClickEvent(MouseButton button, int x, int y, bool down = true);

	EventType getType() override;

	MouseButton getButton() const;

	int getX() const;

	int getY() const;

	bool isDown() const;

private:
	MouseButton button;
	int x, y;
	bool down;
};


