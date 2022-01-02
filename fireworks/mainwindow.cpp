#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowTitle("Fireworks");

    QTimer *time = new QTimer();
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
    QPen pen(Qt::white);
    pen.setWidth(4);
    paint.setPen(pen);

    if (2 >= rand.global()->bounded(0, 100))
        fireworks.push_back(new Firework());

    for (int i=0; i<fireworks.length(); i++) {
        if (!fireworks[i]) continue;

        if (!fireworks[i]->update()) {
            pen.setColor(Qt::white);
            pen.setWidth(4);
            paint.setPen(pen);
            paint.drawPoint(fireworks[i]->show(-1));
        }
        else {
            QVector<Particle*> vParticles = fireworks[i]->getParticleArray();
            pen.setColor(fireworks[i]->getColor());
            pen.setWidth(2);
            paint.setPen(pen);
            for (int j=vParticles.length()-1; j>=0; j--) {
                paint.drawPoint(fireworks[i]->show(j));
            }
        }
    }
}

