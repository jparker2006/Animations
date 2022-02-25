#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QApplication>
#include <QIcon>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QScreen>
#include <QMouseEvent>
#include <QTimer>
#include <QKeyEvent>
#include <QPointF>
#include <QLineF>
#include <QtMath>
#include <QKeyEvent>
#include <QColor>

class Player: public QGraphicsEllipseItem {
public:
    Player(float fx, float fy, float frad, QColor color);
    void move(QPointF p);
    float getRad();
    void grow();
    float getScore();
private:
    float fx;
    float fy;
    float frad;
    float fscore;
    QPointF fvel;
    QColor color;
};

#endif // PLAYER_H
