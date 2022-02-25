#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QTimer>
#include <QPainter>
#include <QPen>
#include <QRandomGenerator>

#include "ui_mainwindow.h"
#include "particle.h"
#include "firework.h"

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
private:
    Ui::MainWindow *ui;
    QVector<Firework*> fireworks;
    QRandomGenerator rand;
    int typeCounter;
};
#endif // MAINWINDOW_H
