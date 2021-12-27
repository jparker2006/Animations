#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QPainter>
#include <QPen>
#include <QTimer>
#include <QList>

#include "ui_mainwindow.h"
#include "rain.h"

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
    virtual void paintEvent(QPaintEvent *event);
    void callUpdate();
private:
    Ui::MainWindow *ui;
    QList<Rain *> drops;

};
#endif // MAINWINDOW_H
