#include <QApplication>

#include "mainwindow.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    MainWindow window;
    window.setWindowTitle("Decryptor");
    window.show();

    return app.exec();
}
