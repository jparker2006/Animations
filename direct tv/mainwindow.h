#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QPainter>
#include <QPen>
#include <QTimer>
#include <QRandomGenerator>
#include <QRectF>
#include <QColor>

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
    void updateSlot();
    virtual void paintEvent(QPaintEvent *event);
    void moveRectangle();
    void genColor();
private:
    Ui::MainWindow *ui;
    QRandomGenerator rand;

    QRectF dtvRect;
    float xspeed, yspeed;
    QColor color;
};
#endif // MAINWINDOW_H
