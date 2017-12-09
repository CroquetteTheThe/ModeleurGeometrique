#include "DrawableDestroyEvent.h"

DrawableDestroyEvent::DrawableDestroyEvent(Drawable* drawable) : drawable(drawable) {}

EventType DrawableDestroyEvent::getType() {
    return DRAWABLE_DESTROY_EVENT;
}

Drawable* DrawableDestroyEvent::getDrawable() {
    return drawable;
}
