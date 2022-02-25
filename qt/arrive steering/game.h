#ifndef GAME_H
#define GAME_H

#include <QTimer>
#include <QObject>
#include <QApplication>
#include <QIcon>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>

#include "player.h"

class Game: public QGraphicsView {
    Q_OBJECT
public:
    Game();
    void setupWindow();
    void updatePlayer();
    void mouseMoveEvent(QMouseEvent *event);
    Player *player;

private:
    QGraphicsScene *scene;
    QPointF mousePos;
};

#endif // GAME_H
