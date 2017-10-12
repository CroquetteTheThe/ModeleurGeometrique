#pragma once

#include "EventType.h"

class Event {
public:
	virtual EventType getType() = 0;
};