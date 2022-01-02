#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowTitle("Cube");

    points[0] = new Point3(-0.5, -0.5, -0.5);
    points[1] = new Point3(0.5, -0.5, -0.5);
    points[2] = new Point3(0.5, 0.5, -0.5);
    points[3] = new Point3(-0.5, 0.5, -0.5);
    points[4] = new Point3(-0.5, -0.5, 0.5);
    points[5] = new Point3(0.5, -0.5, 0.5);
    points[6] = new Point3(0.5, 0.5, 0.5);
    points[7] = new Point3(-0.5, 0.5, 0.5);

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

    // rotation matrices
    QVector<QVector<float>> rotX = {
        { 1, 0, 0 },
        { 0, (float) qCos(fTheta), (float) -qSin(fTheta) },
        { 0, (float) qSin(fTheta), (float) qCos(fTheta) },
    };

    QVector<QVector<float>> rotY = {
        { (float) qCos(fTheta), 0, (float) -qSin(fTheta) },
        { 0, 1, 0 },
        { (float) qSin(fTheta), 0, (float) qCos(fTheta) },
    };

    QVector<QVector<float>> rotZ = {
        { (float) qCos(fTheta), (float) -qSin(fTheta), 0 },
        { (float) qSin(fTheta), (float) qCos(fTheta), 0 },
        { 0, 0, 1 }
    };

    QPainter paint(this);
    QPen pen(Qt::white);
    pen.setWidth(16);
    paint.setPen(pen);

    for (int i=0; i<8; i++) {
        QVector<QVector<float>> curr = {
            { this->points[i]->getX() },
            { this->points[i]->getY() },
            { this->points[i]->getZ() }
        };

        QVector<QVector<float>> rotated;
        rotated = matmul(rotX, curr);
        rotated = matmul(rotY, rotated);
        rotated = matmul(rotZ, rotated);

        float depth = 1 / (this->distance - rotated[2][0]);
        QVector<QVector<float>> projection = {
            {depth, 0, 0},
            {0, depth, 0}
        };

        QVector<QVector<float>> projected2d = matmul(projection, rotated);

        float x = (projected2d[0][0] * this->scale) + xoff;
        float y = (projected2d[1][0] * this->scale) + yoff;
        float z = projected2d[2][0] * this->scale;
        // paint.drawPoint(x, y); // take out if you dont want pointy cube
        projected[i] = new Point3(x, y, z);
    }

    pen.setWidth(2);
    paint.setPen(pen);

    for (int i=0; i<4; i++) {
        paint.drawLine(connectEdge(i, ((i + 1)  % 4)));
        paint.drawLine(connectEdge(i + 4, ((i + 1)  % 4) + 4));
        paint.drawLine(connectEdge(i, i + 4));
    }

    this->fTheta += 0.025;
}

void MainWindow::wheelEvent(QWheelEvent *event) {
    if(event->angleDelta().y() > 0)
        this->distance -= this->distance <= 1.1 ? 0 : 0.15;
    else
        this->distance += this->distance >= 4.1 ? 0 : 0.15;
}

QVector<QVector<float>> MainWindow::matmul(QVector<QVector<float>> a, QVector<QVector<float>> b) {
  int colsA = a[0].size();
  int rowsA = a.size();
  int colsB = b[0].size();
  int rowsB = b.size();

  if (colsA != rowsB) {
      QMessageBox al;
      al.setText(QString::number(colsA) + ", " + QString::number(rowsB));
      al.exec();
      exit(69); // quit program
  }

  QVector<QVector<float>> result = {
      {0},
      {0},
      {0}
  };

  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsB; j++) {
      float sum = 0;
      for (int k = 0; k < colsA; k++) {
        sum += a[i][k] * b[k][j];
      }
      result[i][j] = sum;
    }
  }
  return result;
}

QLineF MainWindow::connectEdge(int i, int j) {
    Point3 *a = this->projected[i];
    Point3 *b = this->projected[j];
    return QLineF(a->getX(), a->getY(), b->getX(), b->getY());
}
