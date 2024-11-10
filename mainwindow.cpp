#include "mainwindow.h"

#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QFileDialog>
#include <QFormLayout>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget* centralWidget = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(centralWidget);

    QPushButton* importKeyButton = new QPushButton("Import key", this);
    importKeyButton->setFixedSize(150, 40);
    layout->addWidget(importKeyButton, 0, Qt::AlignCenter);
    connect(importKeyButton, &QPushButton::clicked, this, &MainWindow::showImportKeyDialog);

    QPushButton* decryptButton = new QPushButton("Decrypt file", this);
    decryptButton->setFixedSize(150, 40);
    layout->addWidget(decryptButton, 0, Qt::AlignCenter);
    connect(decryptButton, &QPushButton::clicked, this, &MainWindow::showDecryptFileDiaglog);

    setCentralWidget(centralWidget);
    setWindowTitle("Decryptor");
    setMinimumSize(400, 300);
}

void MainWindow::showImportKeyDialog() {
    QDialog dialog(this);
    dialog.setWindowTitle("Import Key");

    QFormLayout form(&dialog);
    QLineEdit* keyName = new QLineEdit(&dialog);
    QLineEdit* passwd = new QLineEdit(&dialog);
    passwd->setEchoMode(QLineEdit::Password);

    // 使用 QHBoxLayout 包裝 selectKeyFileButton 和 ok 按鍵
    QHBoxLayout* buttonLayout = new QHBoxLayout();

    QPushButton* selectKeyFileButton = new QPushButton("Select file", &dialog);
    selectKeyFileButton->setFixedSize(100, 30); // 設置按鍵大小
    buttonLayout->addWidget(selectKeyFileButton);

    buttonLayout->addStretch(); // 添加彈性空間

    QPushButton* ok = new QPushButton("Import", &dialog);
    ok->setFixedSize(100, 30); // 設置按鍵大小
    buttonLayout->addWidget(ok);

    form.addRow("Key alias:", keyName);
    form.addRow("Password: ", passwd);
    form.addRow(buttonLayout); // 將按鍵佈局添加到表單

    QString keyFile;
    connect(selectKeyFileButton, &QPushButton::clicked, [this, &keyFile]() {
        keyFile = QFileDialog::getOpenFileName(this, "Select key file");
        if (keyFile.isEmpty()) {
            QMessageBox::warning(nullptr, "Error", "Please select a key file");
        }
    });

    connect(ok, &QPushButton::clicked, [this, &dialog, &keyName, &keyFile, &passwd]() {
        if (keyName->text().isEmpty() || keyFile.isEmpty() || passwd->text().isEmpty()) {
            QMessageBox::warning(nullptr, "Error", "All options must be filled!");
        } else {
            QMessageBox::information(this, "Success", "Key is imported.");
            dialog.accept();
        }
    });

    dialog.exec();
}

void MainWindow::showDecryptFileDiaglog() {
    QDialog dialog(this);
    dialog.setWindowTitle("Decryption");

    QFormLayout form(&dialog);
    QLineEdit* keyAlias = new QLineEdit(&dialog);

    QHBoxLayout* buttonLayout = new QHBoxLayout();

    QPushButton* selectFileButton = new QPushButton("Select file", &dialog);
    selectFileButton->setFixedSize(100, 30);
    buttonLayout->addWidget(selectFileButton);

    QPushButton* decrypt = new QPushButton("Decrypt", &dialog);
    decrypt->setFixedSize(100, 30);
    buttonLayout->addWidget(decrypt);

    buttonLayout->addStretch();

    form.addRow("key alias:", keyAlias);
    form.addRow(buttonLayout);

    QString decryptFile;
    connect(selectFileButton, &QPushButton::clicked, [this, &decryptFile]() {
       decryptFile = QFileDialog::getOpenFileName(this, "select decrypt file");
       if (decryptFile.isEmpty()) {
           QMessageBox::warning(nullptr, "Error", "Please select file to decrypt.");
       }
    });

    connect(decrypt, &QPushButton::clicked, [&dialog, &decryptFile, &keyAlias]() {
        if (decryptFile.isEmpty() || keyAlias->text().isEmpty()) {
            QMessageBox::warning(nullptr, "Error", "All options must be filled.");
        } else {
//            decryptFile(decryptFile->text(), keyAlias->text());
            QMessageBox::warning(nullptr, "Ok", "file decrypted.");
            dialog.accept();
        }
    });

    dialog.exec();
}

