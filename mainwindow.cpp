#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setWindowTitle("Rain");

    for (int i=0; i<750; i++) {
        drops.push_back(new Rain());
    }

    QTimer *t = new QTimer(this);
    connect(t, &QTimer::timeout, this, &MainWindow::callUpdate);
    t->start(16);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event) { // draw
    Q_UNUSED(event);
    QPainter paint(this);
    QPen pen;
    QLineF droplet;
    for (int i=0; i<drops.length(); i++) {
        drops.at(i)->descend();
        pen.setWidth(drops.at(i)->calculateWidth());
        droplet = drops[i]->getRainLine();
        pen.setColor(drops.at(i)->getColor());
        paint.setPen(pen);
        paint.drawLine(droplet);
    }
}

void MainWindow::callUpdate() {
    this->update();
}
