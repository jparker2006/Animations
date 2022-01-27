#include "player.h"

Player::Player(float fx, float fy, float frad, QColor color) {
    this->fx = fx;
    this->fy = fy;
    this->frad = frad;
    this->fvel = QPointF(0, 0);
    this->color = color;

    QBrush b(color, Qt::SolidPattern);
    setRect(this->fx, this->fy, this->frad, this->frad);
    setFocus();
    setBrush(b);
}

void Player::move(QPointF p) {
    QPointF nw_vel(p.x() - 600, p.y() - 400);

    float mag = (float) qSqrt(qPow(nw_vel.x(), 2) + qPow(nw_vel.y(), 2));
    if (0 != mag && 1 != mag) {
        nw_vel.setX(nw_vel.x() / mag);
        nw_vel.setY(nw_vel.y() / mag);
    }

    nw_vel.setX(nw_vel.x() * 3);
    nw_vel.setY(nw_vel.y() * 3);


    this->fvel.setX((nw_vel.x() - fvel.x()) * 0.2);
    this->fvel.setY((nw_vel.y() - fvel.y()) * 0.2);

    this->fx += fvel.x();
    this->fy += fvel.y();
    setPos(fx, fy);

    if (fx < 0)
        fx = 1200;
    if (fx > 1200)
        fx = 0;
    if (fy < 0)
        fy = 800;
    if (fy > 800)
        fy = 0;
}

float Player::getRad() {
    return this->frad;
}

void Player::grow() {
    this->frad += this->frad >= 130 ? 0 : 4;
    setRect(0, 0, frad, frad);
    this->fscore += 1;
}

float Player::getScore() {
    return this->fscore;
}
