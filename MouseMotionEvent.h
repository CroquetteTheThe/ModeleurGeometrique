#pragma once


#include "Event.h"

class MouseMotionEvent : public Event {
public:
	MouseMotionEvent(int x, int y);

	EventType getType() override;

	int getX() const;

	int getY() const;

private:
	int x, y;
};



