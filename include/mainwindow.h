#ifndef MAINWINDOW_H
#define MAINWINDOW_
#include "../cmake-build-debug-event-trace/ui_mainwindow.h"
#include "GameFieldLabel.h"
#include <QMainWindow>
#include <QtCore>
#include <QResizeEvent>
#include <QGraphicsDropShadowEffect>
#include <QString>
#include <QPoint>
#include <QBoxLayout>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

void resizeEvent(QResizeEvent *event);


// void resizeEvent(QResizeEvent *event);

~MainWindow() override;


private:
    Ui::MainWindow *ui;
};


#endif //MAINWINDOW_H
