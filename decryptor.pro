TEMPLATE = app
TARGET = decryptor

QT = core gui widgets

OPENSSL_DIR = "C:/msys64/usr/local"

INCLUDEPATH += $$OPENSSL_DIR/include
LIBS += -L$$OPENSSL_DIR/lib64 -lssl -lcrypto

SOURCES += \
    asym_decryptor.cpp \
    aesdecryptor.cpp \
    aesencryptor.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    asym_decryptor.h \
    aescipher.h \
    aesdecryptor.h \
    aesencryptor.h \
    mainwindow.h \
    sslwrapper.h

