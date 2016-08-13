QT += core network websockets sql
QT -= gui
QTPLUGIN += QSQLMYSQL

CONFIG += c++11

TARGET = sqlpi
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
	main.cpp \
	Externals/QJsonWebToken/src/qjsonwebtoken.cpp \
	Connection/Client.cpp \
	Process/Task.cpp \
	Api/Backend.cpp \
	Api/Abstract/SQLite.cpp \
	Api/Abstract/Model.cpp \
	Api/Model/Authorization.cpp \
	Bootstrap.cpp \
	Process/Configuration.cpp \
	Process/Interface.cpp \
	Transport/Tcp.cpp \
	Transport/Abstract/Server.cpp \
	Transport/Abstract/Server.cpp \
	Process/Log.cpp

HEADERS += \
	Externals/QJsonWebToken/src/qjsonwebtoken.h \
	Connection/Client.hpp \
	Process/Task.hpp \
	Api/Backend.hpp \
	Api/Abstract/SQLite.hpp \
	Api/Abstract/Model.hpp \
	Api/Model/Authorization.hpp \
	Bootstrap.hpp \
	Process/Configuration.hpp \
	Process/Interface.hpp \
	Transport/Tcp.hpp \
	Transport/Abstract/Server.hpp \
	Process/Log.hpp

DISTFILES += \
	Sql/SQLite/Connection.sql \
	Sql/SQLite/Authorization.sql \
	Sql/SQLite/Session.sql \
	README.md
