#pragma once


#include "Event.h"
#include "MouseButton.h"
#include "../Shapes/Drawable.h"

class DrawableDestroyEvent : public Event {
public:
    explicit DrawableDestroyEvent(Drawable* newDrawable);

    EventType getType() override;

    Drawable* getDrawable();

private:
    Drawable* drawable;
};

