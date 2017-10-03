#pragma once


#include "Event.h"
#include "MouseButton.h"

class MouseClickEvent : public Event {
public:
	MouseClickEvent(MouseButton button, int x, int y);

	EventType getType() override;

	MouseButton getButton() const;

	int getX() const;

	int getY() const;

private:
	MouseButton button;
	int x, y;
};


