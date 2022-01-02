#include "particle.h"

Particle::Particle(float x, float y, bool firework) {
    this->pos = QPointF(x, y);
    this->lifespan = 255;

    if (firework) {
        float angle = rand.global()->bounded(9.0) * M_PI_2;
        float multiple = rand.global()->bounded(4, 16);
        this->vel = QPointF(qCos(angle) * multiple, qSin(angle) * multiple);
        this->firework = true;
        float multX = rand.global()->bounded(80, 90) / 100.0;
        float multY = rand.global()->bounded(80, 90) / 100.0;
        this->mult = QPointF(multX, multY);
    }
    else
        this->vel = QPointF(0, rand.global()->bounded(-15, -9));
    this->acc = QPointF(0, 0);
}

void Particle::updatePosition() {
    if (this->firework) {
        this->vel.setX(this->vel.x() * this->mult.x());
        this->vel.setY(this->vel.y() * this->mult.y());
        this->lifespan -= 2.5;
    }

    this->pos.setX(this->pos.x() + this->vel.x());
    this->pos.setY(this->pos.y() + this->vel.y());

    this->vel.setX(this->vel.x() + this->acc.x());
    this->vel.setY(this->vel.y() + this->acc.y());

    this->acc.setX(0);
    this->acc.setY(0);
}

void Particle::applyForce(QPointF force) {
    this->acc.setX(this->acc.x() + force.x());
    this->acc.setY(this->acc.y() + force.y());
}

QPointF Particle::getPosition() {
    return this->pos;
}

float Particle::getLifespan() {
    return this->lifespan;
}

float Particle::getVelo() {
    return this->vel.y();
}
