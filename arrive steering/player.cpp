#include "player.h"

Player::Player(float fx, float fy, float frad, QColor color) {
    this->fx = fx;
    this->fy = fy;
    this->frad = frad;
    this->fvel = QPointF(0, 0);
    this->acc = QPointF(0, 0);

    QBrush b(Qt::black, Qt::SolidPattern);
    setRect(this->fx, this->fy, this->frad, this->frad);
    setFocus();
    setBrush(b);
}

void Player::move(QPointF p) {
    if (p.x() == fx && p.y() == fy) return;
    QPointF force = QPointF((p.x() - frad * 0.75) - fx, (p.y() - frad * 0.75) - fy);
    float fspeed = 1.2;
    float distance = qSqrt(qPow(force.x(), 2) + qPow(force.y(), 2));
    if (distance < 150) // 150 == slow down radius
        fspeed = map(distance, 0, 100, 0, 1.2); // 1.2 == max speed
    float mag = qSqrt(qPow(force.x(), 2) + qPow(force.y(), 2));
    if (0 != mag && 1 != mag) {
        force.setX(force.x() / mag);
        force.setY(force.y() / mag);
    }
    force.setX(force.x() * fspeed);
    force.setY(force.y() * fspeed);
    force = QPointF(force.x() - fvel.x(), force.y() - fvel.y());
    this->acc = QPointF(acc.x() + force.x(), acc.y() + force.y());
    if (fx < 0)
        fx = 1200;
    if (fx > 1200)
        fx = 0;
    if (fy < 0)
        fy = 800;
    if (fy > 800)
        fy = 0;
}

float Player::map(float num, float min1, float max1, float min2, float max2) {
    return min2 + (max2 - min2) * ((num - min1) / (max1 - min1));
}

void Player::update() {
    this->fvel = QPointF(fvel.x() + acc.x(), fvel.y() + acc.y());
    fx += fvel.x();
    fy += fvel.y();
    this->acc = QPointF(0, 0);
    setPos(fx, fy);
}
