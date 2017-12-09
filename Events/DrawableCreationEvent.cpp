#include "DrawableCreationEvent.h"

DrawableCreationEvent::DrawableCreationEvent(Drawable* drawable) : newDrawable(drawable) {}

EventType DrawableCreationEvent::getType() {
    return DRAWABLE_CREATION_EVENT;
}

Drawable* DrawableCreationEvent::getNewDrawable() {
    return newDrawable;
}
