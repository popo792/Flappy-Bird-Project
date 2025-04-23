#include "bird.h"

Bird::Bird(const QPixmap &sprite, const QPoint &startPos)
    : sprite(sprite), rect(startPos.x(), startPos.y(), 34, 24), velocity(0) {}

void Bird::update() {
    rect.moveTop(rect.top() + velocity);
    velocity += 1;
}

void Bird::jump() {
    velocity = -10;
}

QRect Bird::getRect() const {
    return rect;
}

void Bird::reset() {
    rect.moveTo(100, 250);
    velocity = 0;
}
