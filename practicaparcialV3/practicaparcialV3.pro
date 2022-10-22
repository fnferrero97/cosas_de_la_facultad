TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        empresavinos.cpp \
        main.cpp \
        vinoespecial.cpp \
        vinogeneral.cpp \
        vinomesa.cpp \
        vinopremium.cpp

HEADERS += \
    empresavinos.h \
    vinoespecial.h \
    vinogeneral.h \
    vinomesa.h \
    vinopremium.h
