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
    void wheelEvent(QWheelEvent *event);
private:
    Ui::MainWindow *ui;

    Point3 *points[8];
    float fTheta = 0.0;
    float xoff = 300; // this.width / 2
    float yoff = 200; // this.height / 2
    float scale = 100;
    float distance = 1.4;

    Point3 *projected[8];
};
#endif // MAINWINDOW_H
