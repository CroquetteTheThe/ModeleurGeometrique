#pragma once


#include "Event.h"

class KeyboardEvent : public Event {
public:
	explicit KeyboardEvent(char key);

	EventType getType() override;

	char getKey() const;

private:
	char key;
};


