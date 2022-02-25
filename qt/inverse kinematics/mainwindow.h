#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QPainter>
#include <QPen>
#include <QTimer>
#include <QRectF>
#include <QtMath>
#include <QMouseEvent>

#include "ui_mainwindow.h"
#include "part.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow: public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateSlot();
    virtual void paintEvent(QPaintEvent *event);
    float map(float num, float min1, float max1, float min2, float max2);
private:
    Ui::MainWindow *ui;
    Part *last;
};
#endif // MAINWINDOW_H
