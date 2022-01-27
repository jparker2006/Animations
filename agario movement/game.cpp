#include "game.h"

Game::Game() {
    setupWindow();
    player = new Player(0, 0, 30, Qt::black); // cant start at anywhere other than (0,0) now / make rad even
    scene->addItem(player);
    QTimer *t = new QTimer(this);
    connect(t, &QTimer::timeout, this, &Game::updatePlayer);
    t->start(3);
    QTimer *t2 = new QTimer(this);
    connect(t2, &QTimer::timeout, this, &Game::grow);
    t2->start(400);
}

void Game::setupWindow() {
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,1200,800);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200, 800);
    setStyleSheet("background-color: white;");
    setWindowTitle("Movement");
    setMouseTracking(true);
}

void Game::updatePlayer() {
    player->move(QWidget::cursor().pos());
}

void Game::grow() {
    player->grow();
}
