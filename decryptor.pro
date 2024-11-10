TEMPLATE = app
TARGET = hello

QT = core gui widgets network

OPENSSL_DIR = "C:/Program Files/OpenSSL-Win64"

INCLUDEPATH += $$OPENSSL_DIR/include
LIBS += -L$$OPENSSL_DIR/lib/VC/x64/MD -llibssl -llibcrypto

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

