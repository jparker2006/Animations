#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QTimer>
#include <QPainter>
#include <QPen>
#include <QMouseEvent>

#include "ui_mainwindow.h"

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
    void drawPix(QPointF point, float color);
    void updateSlot();
    virtual void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void calcPixels();
private:
    Ui::MainWindow *ui;
    float current[600][400];
    float previous[600][400]; // cols (width) , rows (height)
    float damp = 0.95;
};
#endif // MAINWINDOW_H
