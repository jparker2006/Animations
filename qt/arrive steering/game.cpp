#include "game.h"

Game::Game() {
    setupWindow();

    player = new Player(0, 0, 30, Qt::black); // 0, 0 error
    scene->addItem(player);
    QTimer *t = new QTimer(this);
    connect(t, &QTimer::timeout, this, &Game::updatePlayer);
    t->start(3);
}

void Game::setupWindow() {
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,1200,800);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200, 800);
    setStyleSheet("background-color: white;");
    setWindowTitle("Arrival");
    setMouseTracking(true);
}

void Game::mouseMoveEvent(QMouseEvent *event) {
    this->mousePos = event->pos();
}

void Game::updatePlayer() {
    player->move(mousePos);
    player->update();
}
