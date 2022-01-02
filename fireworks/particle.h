#ifndef PARTICLE_H
#define PARTICLE_H

#include <QPointF>
#include <QRandomGenerator>
#include <QtMath>

class Particle {
public:
    Particle(float x, float y, bool firework);
    void updatePosition();
    void applyForce(QPointF force);
    QPointF getPosition();
    float getVelo();
    float getLifespan();
private:
    QPointF pos;
    QPointF vel;
    QPointF acc;
    bool firework = false;
    float lifespan;
    QPointF mult;

    QRandomGenerator rand;
};

#endif // PARTICLE_H
