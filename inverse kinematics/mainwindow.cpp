#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setWindowTitle("Kinematics");

    Part *curr = new Part(300, 200, 10, 0);;
    for (int i=0; i<20; i++) {
        Part *next = new Part(curr, 10, 0);
        curr->setChild(next);
        curr = next;
    }
    this->last = curr;

    QTimer *time = new QTimer();
    connect(time, &QTimer::timeout, this, &MainWindow::updateSlot);
    time->start(17);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter paint(this);
    QPen pen;
    pen.setColor(Qt::white);
    pen.setWidth(4);
    paint.setPen(pen);

    last->follow(QWidget::mapFromGlobal(QCursor::pos()));
    last->calcB();
    paint.drawLine(last->getLineCoords());

    Part *next = last->getParent();
    while (nullptr != next) {
        next->follow();
        next->calcB();
        QLineF seg = next->getLineCoords();
        paint.drawLine(seg);
        next = next->getParent();
    }
}

void MainWindow::updateSlot() {
    update(); // paints
}

float MainWindow::map(float num, float min1, float max1, float min2, float max2) {
    return min2 + (max2 - min2) * ((num - min1) / (max1 - min1));
}



