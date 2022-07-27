TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        barco.cpp \
        juego.cpp \
        jugador.cpp \
        main.cpp \
        tablero.cpp \
        tableroataques.cpp \
        tablerobarcos.cpp

HEADERS += \
  barco.h \
  info.h \
  juego.h \
  jugador.h \
  lancha.h \
  portaaviones.h \
  submarino.h \
  tablero.h \
  tableroataques.h \
  tablerobarcos.h
