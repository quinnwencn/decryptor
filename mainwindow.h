#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLineEdit;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void showImportKeyDialog();
    void showDecryptFileDiaglog();

private:
    QLineEdit* searchBox;
};

#endif // MAINWINDOW_H
