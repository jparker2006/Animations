#ifndef GAME_H
#define GAME_H

#include "player.h"

class Game: public QGraphicsView {
    Q_OBJECT
public:
    Game();
    void setupWindow();
    void calcB();
    void follow(QPointF tFollow);
    Player *player;
    void updatePlayer();
    void grow();
private:
    QGraphicsScene *scene;
};

#endif // GAME_H
