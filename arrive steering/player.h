#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsEllipseItem>
#include <QPointF>
#include <QtMath>
#include <QColor>
#include <QBrush>
#include <QPen>

class Player: public QGraphicsEllipseItem {
public:
    Player(float fx, float fy, float frad, QColor color);
    void move(QPointF p);
    void update();
    float map(float num, float min1, float max1, float min2, float max2);
private:
    float fx;
    float fy;
    float frad;
    QPointF fvel;
    QPointF acc;
};

#endif // PLAYER_H
