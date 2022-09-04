TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        cliente.cpp \
        factura.cpp \
        facturagiga.cpp \
        facturamixta.cpp \
        facturatiempo.cpp \
        gestorclientes.cpp \
        main.cpp

HEADERS += \
    cliente.h \
    factura.h \
    facturagiga.h \
    facturamixta.h \
    facturatiempo.h \
    gestorclientes.h
