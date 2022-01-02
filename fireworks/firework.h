#ifndef FIREWORK_H
#define FIREWORK_H

#include <QRandomGenerator>
#include <QVector>
#include <QColor>

#include "particle.h"

class Firework {
public:
    Firework();
    QPointF show();
    void explode();
    bool update();
    QVector<Particle *> getParticleArray();
    QPointF show(int index);
    QColor getColor();
private:
    Particle *firework;

    QRandomGenerator rand;
    QPointF gravity = QPointF(0, 0.2);
    bool bExploded;
    QVector<Particle*> vParticles;
    QColor color;
};

#endif // FIREWORK_H
