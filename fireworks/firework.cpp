#include "firework.h"

Firework::Firework() {
    this->firework = new Particle(rand.global()->bounded(0, 800), 600, false);
    this->bExploded = false;
    this->color = QColor(
        rand.global()->bounded(0, 255),
        rand.global()->bounded(0, 255),
        rand.global()->bounded(0, 255)
    );
}

bool Firework::update() { // return true if its a firework post explode
    if (this->bExploded) {
        for (int i=vParticles.length()-1; i>=0; i--) {
            this->vParticles[i]->applyForce(this->gravity); //
            this->vParticles[i]->updatePosition();
        }
        return true;
    }

    this->firework->applyForce(this->gravity);
    this->firework->updatePosition();

    if (0 <= this->firework->getVelo()) {
        this->bExploded = true;
        explode();
    }

    return false;
}

QPointF Firework::show(int index) {
    if (-1 == index)
        return this->firework->getPosition();

    if (this->bExploded)
        return this->vParticles[index]->getPosition();

    return QPointF(-10, -10);
}

void Firework::explode() {
    for (int i=0; i<100; i++) {
        QPointF topPos = this->firework->getPosition();
        Particle *p = new Particle(topPos.x(), topPos.y(), true);
        this->vParticles.push_back(p);
    }
}

QVector<Particle*> Firework::getParticleArray() {
    return this->vParticles;
}

QColor Firework::getColor() {
    this->color.setAlpha(vParticles[0]->getLifespan());
    return this->color;
}








