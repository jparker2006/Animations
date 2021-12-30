#include "rain.h"

Rain::Rain() {
    construct();
}

void Rain::construct() {
    this->fx = rand->global()->bounded(0, 450);
    this->fy = rand->global()->bounded(-700, -200);
    this->fz = rand->global()->bounded(0, 20);
    this->fLength = map(this->fz, 5, 35, 10, 20);
    this->fySpeed = map(this->fz, 5, 35, 1, 9);
    this->c_Color = QColor(
        rand->global()->bounded(0, 255),
        rand->global()->bounded(0, 255),
        rand->global()->bounded(0, 255)
    );
}

void Rain::descend() {
    this->fy += this->fySpeed;
    this->fySpeed += map(this->fz, 5, 35, 0.04, 0.1); // y grav

    if (this->fy > 300) // height
        construct();
}

QLineF Rain::getRainLine() {
    return QLineF(this->fx, this->fy, this->fx, this->fy + this->fLength);
}

float Rain::map(float num, float min1, float max1, float min2, float max2) {
    return min2 + (max2 - min2) * ((num - min1) / (max1 - min1));
}

float Rain::calculateWidth() {
    return map(this->fz, 0, 20, 1, 4);
}

QColor Rain::getColor() {
    return this->c_Color;
}

