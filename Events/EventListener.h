#pragma once

#include "Event.h"

class EventListener {
public:

	/**
	 * Notify an event
	 * @param e The event
	 * @return Whether or not we should force redisplay
	 */
	virtual bool notify(Event *e) = 0;
};