#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowTitle("Water Ripples 2D");

    for (int i=0; i<600; i++) {
        for (int j=0; j<400; j++) {
            current[i][j] = 0;
            previous[i][j] = 0;
        }
    }

    QTimer *t = new QTimer();
    for (int i=0; i<6; i++) { // call func 6 times when timer hits
        connect(t, &QTimer::timeout, this, &MainWindow::calcPixels);
    }
    t->start(17);

    QTimer *time = new QTimer();
    connect(time, &QTimer::timeout, this, &MainWindow::updateSlot);
    time->start(17);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    this->current[event->pos().x()][event->pos().y()] = 255;
}

void MainWindow::calcPixels() {
    for (int x=1; x<599; x++) {
        for (int y=1; y<399; y++) {
            float currPixel = this->previous[x-1][y] + this->previous[x+1][y];
            currPixel += this->previous[x][y+1] + this->previous[x][y-1];
            currPixel /= 2;
            currPixel -= this->current[x][y];
            this->current[x][y] = currPixel * this->damp;
        }
    }

    for (int x=0; x<600; x++) {
        for (int y=0; y<400; y++) {
            float temp = this->previous[x][y];
            this->previous[x][y] = this->current[x][y];
            this->current[x][y] = temp;
        }
    }
}

void MainWindow::updateSlot() {
    update();
}

void MainWindow::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    for (int i=0; i<600; i++) {
        for (int j=0; j<400; j++) {
            float rgb = this->current[i][j];
            QColor color(rgb, rgb, rgb);
            QPainter paint(this);
            paint.setPen(QPen(color));
            paint.drawPoint(i, j);
        }
    }
}
