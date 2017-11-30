#pragma once


#include "Event.h"
#include "MouseButton.h"
#include "../Shapes/Drawable.h"

class DrawableCreationEvent : public Event {
public:
    explicit DrawableCreationEvent(Drawable* newDrawable);

    EventType getType() override;

    Drawable* getNewDrawable();

private:
    Drawable* newDrawable;
};

