#include <QApplication>
#include <QScreen>
#include "../include/mainwindow.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    // a.setWindowIcon();
    MainWindow w;
    QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();
    w.resize(screenGeometry.width(), screenGeometry.height());
    w.show();
    return QApplication::exec();
}
