#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QPainter>
#include <QPen>
#include <QtMath>
#include <QTimer>
#include <QVector>
#include <QMessageBox>
#include <QWheelEvent>

#include "point3.h"
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow:  public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    void updateSlot();
    QVector<QVector<float>> matmul(QVector<QVector<float>> a, QVector<QVector<float>> b);
    QLineF connectEdge(int i, int j);
private:
    Ui::MainWindow *ui;

    Point3 *points[16];
    float fTheta = 0.0;
    float xoff = 300; // this.width / 2
    float yoff = 200; // this.height / 2
    float scale = 100;
    float distance = 1.7;

    Point3 *projected[16];

    QVector<QPointF> connections = { // calc this in a loop lol
        QPointF(0, 1),
        QPointF(2, 7),
        QPointF(3, 5),
        QPointF(2, 3),
        QPointF(2, 7),
        QPointF(1, 6),
        QPointF(0, 4),
        QPointF(4, 5),
        QPointF(6, 7),
        QPointF(8, 9),
        QPointF(10, 15),
        QPointF(11, 13),
        QPointF(10, 11),
        QPointF(10, 15),
        QPointF(9, 14),
        QPointF(8, 12),
        QPointF(12, 13),
        QPointF(14, 15)
    };
};
#endif // MAINWINDOW_H
