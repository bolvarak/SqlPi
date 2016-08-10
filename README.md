# SqlPi
SqlPi (Structured Query Language Programming Interface) is a TCP socket that sits on a MySQL, MariaDB, PostgreSQL or SQLite server and provides a JSON API to execute queries using JWT (JSON Web Token) Authentication.

## Requirements
 - Qt 5.7
 - QCA (Qt Cryptographic Architecture) 2.0+

## Ubuntu Installation
```
sudo apt update && sudo apt install qt5-default libqt5sql5 libqt5sql5-mysql libqt5sql5-odbc libqt5sql5-psql libqt5sql5-sqlite libqt5sql5-tds geoip-database-contrib libgeoip-dev libqca-qt5-2 libqca-qt5-2-dev libqca-qt5-2-plugins
```

## ArchLinux Installation

```
sudo pacman -Syy qt5 geoip geoip-database postgresql-libs mariadb-clients qca-qt5
```

## MacOS Installation
MacOS installation requires <a href="http://brew.sh/" target="_blank">Homebrew</a>.
```
brew install qt5 qca
```

## Compilation
```
$ cd /tmp
$ git clone https://bolvarak@bitbucket.org/bolvarak/SqlPi.git
$ cd SqlPi
$ qmake sqlpi.pro
$ make
$ sudo mv sqlpi /usr/bin
```

## Usage

| Command            | Type                       | Default   | Description                                                                               |
| ------------------ | -------------------------- | --------- | ----------------------------------------------------------------------------------------- |
| --backend-type     | String                     | Null      | This defines the database type that the backend will use (sqlite, mysql, pgsql)           |
| --backend-host     | localhost<br>IPv4<br>IPv6  | localhost | This defines the host in which the backend database resides (Ignored with sqlite)         |
| --backend-port     | Number                     | 0         | This defines the port in which the backend database is listening on (Ignored with sqlite) |
| --backend-db       | String                     | Null      | This defines the database name for the backend, for sqlite, this should be a file path    |
| --backend-username | String                     | Null      | This defines the username for accessing the backend database                              |
| --backend-password | String                     | Null      | This defines the password for accessing the backend database                              |
| --backend-prefix   | String                     | Null      | This defines the table prefix for SqlPi's tables in the backend                           |
| --log-file         | String                     | stdout    | This defines the filepath for outputting log data to                                      |
| --bind-address     | localhost<br>IPv4<br>IPv6  | Any       | This defines the hostname/IP that the service should bind to                              |
| --bind-port        | Number                     | 1597      | This defines the port that the service should bind to                                     |
| --socket-type      | tcp<br>web<br>cgi          | tcp       | This defines which type of socket to use (TCP, WebSocket or CGI)                          |
| --help             |                            |           | This will display this usage menu in the CLI                                              |

## Systemd Unit
```
[Unit]
Description=SqlPi Database Abstraction Layer
After=network.target

[Service]

## These can and should be changed
User=root
Group=root

## Available types:  mysql, pgsql, sqlite
Environment=SQLPI_BACKEND_TYPE=sqlite

## Only needed for mysql and pgsql
# Environment=SQLPI_BACKEND_HOST=localhost
# Environment=SQLPI_BACKEND_PORT=3306|5432

## For mysql and pgsql, this would be the database name
Environment=SQLPI_BACKEND_DB=/path/to/db.sqlite

## Username for accessing the database/server
# Environment=SQLPI_BACKEND_USER=someUser

## Password for accessing the database/server
# Environment=SQLPI_BACKENT_PASS=superSecretPassword

## Start the service
ExecStart=/usr/bin/sqlpi \
    --backend-type=${SQLPI_BACKEND_TYPE} \
	# --backend-host=${SQLPI_BACKEND_HOST} \
	# --backend-port=${SQLPI_BACKEND_PORT} \
	--backend-db=${SQLPI_BACKEND_DB} \
	# --backend-username=${SQLPI_BACKEND_USER} \
	# --backend-password=${SQLPI_BACKEND_PASS}

[Install]
WantedBy=multi-user.target
```
