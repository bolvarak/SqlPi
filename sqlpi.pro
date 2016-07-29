QT += core network sql
QT -= gui

CONFIG += c++11

TARGET = sqlpi
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
	main.cpp \
	Externals/QJsonWebToken/src/qjsonwebtoken.cpp \
	Transport/Server.cpp \
	Connection/Client.cpp \
	Process/Task.cpp \
	Api/Backend.cpp \
	Api/Abstract/SQLite.cpp \
	Api/Abstract/Model.cpp \
	Api/Model/Authorization.cpp

HEADERS += \
	Externals/QJsonWebToken/src/qjsonwebtoken.h \
	Transport/Server.hpp \
	Connection/Client.hpp \
	Process/Task.hpp \
	Api/Backend.hpp \
	Api/Abstract/SQLite.hpp \
	Api/Abstract/Model.hpp \
	Api/Model/Authorization.hpp

RESOURCES += \
	dependencies.qrc

DISTFILES += \
	Connection.sql \
	Authorization.sql \
	Session.sql \
    README.md
