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

    Point3 *points[8];
    float angle = 0.0;
    float xoff = 300;
    float yoff = 200;
    float scale = 100;

    Point3 *projected[8];
};
#endif // MAINWINDOW_H
