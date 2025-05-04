#include "Latch.h"

Latch::Latch() : isOn(false) {}

Latch::operator bool() const {
    return isOn;
}

void Latch::setOn() {
    isOn = true;
}
