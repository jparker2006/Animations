#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    this->setWindowTitle("DirectTV Animation");

    this->dtvRect.setRect(rand.global()->bounded(0, this->width()), rand.global()->bounded(0, this->height()), 120, 90);
    this->xspeed = 2.5;
    this->yspeed = 2.5;
    genColor();

    QTimer *time = new QTimer(this);
    connect(time, &QTimer::timeout, this, &MainWindow::updateSlot);
    time->start(17);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::updateSlot() {
    update();
}

void MainWindow::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter paint(this);
    QPen pen(this->color);
    pen.setWidth(1);
    paint.setPen(pen);

    moveRectangle();

    paint.drawRect(this->dtvRect);
    paint.setFont(QFont("Times New Roman", 50));
    paint.drawText(
       this->dtvRect.x(), this->dtvRect.y(),
       this->dtvRect.width(), this->dtvRect.height(),
       Qt::AlignmentFlag::AlignCenter, "JP" // change to text of choice
    );
}

void MainWindow::moveRectangle() {
    this->dtvRect.moveTo(this->dtvRect.x() + this->xspeed, this->dtvRect.y() + this->yspeed);

    if (this->dtvRect.x() <= 0) {
        this->xspeed = -this->xspeed;
        this->dtvRect.moveTo(0, this->dtvRect.y());
        genColor();
    }
    else if (this->dtvRect.x() >= this->width() - this->dtvRect.width()) {
        this->xspeed = -this->xspeed;
        this->dtvRect.moveTo(this->width() - this->dtvRect.width(), this->dtvRect.y());
        genColor();
    }

    if (this->dtvRect.y() <= 0) {
        this->yspeed = -this->yspeed;
        this->dtvRect.moveTo(this->dtvRect.x(), 0);
        genColor();
    }
    else if (this->dtvRect.y() >= this->height() - this->dtvRect.height()) {
        this->yspeed = -this->yspeed;
        this->dtvRect.moveTo(this->dtvRect.x(), this->height() - this->dtvRect.height());
        genColor();
    }
}

void MainWindow::genColor() {
    this->color = QColor(
        rand.global()->bounded(100, 255),
        rand.global()->bounded(100, 255),
        rand.global()->bounded(100, 255)
    );
}
