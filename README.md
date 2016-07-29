SqlPi
====
---
SqlPi (Structured Query Language Programming Interface) is a TCP socket that sits on a MySQL, MariaDB, PostgreSQL or SQLite server and provides a JSON API to execute queries using JWT (JSON Web Token) Authentication.

## Requirements
 - Qt 5.7
 - QCA (Qt Cryptographic Architecture) 2.0+

## Ubuntu Installation
    sudo apt update && sudo apt install qt5-default libqt5sql5 libqt5sql5-mysql libqt5sql5-odbc libqt5sql5-psql libqt5sql5-sqlite libqt5sql5-tds geoip-database-contrib libgeoip-dev libqca-qt5-2 libqca-qt5-2-dev libqca-qt5-2-plugins

## ArchLinux Installation

    sudo pacman -Syy qt5 geoip geoip-database postgresql-libs mariadb-clients qca-qt5

## Compilation
        $ cd /tmp
	$ git clone https://bolvarak@bitbucket.org/bolvarak/SqlPi.git
	$ cd SqlPi
	$ qmake sqlpi.pro
	$ make
	$ sudo mv sqlpi /usr/bin

## Usage

| ------------------ | ------------------------ | ------- | ----------------------------------------------------------------------------------------- |
| Command            | Type                     | Default | Description                                                                               |
| ------------------ | ------------------------ | ------- | ----------------------------------------------------------------------------------------- |
| --backend-type     | String                   | None    | This defines the database type that the backend will use (sqlite, mysql, pgsql)           |
| --backend-host     | Hostname<br>IPv4<br>IPv6 | None    | This defines the host in which the backend database resides (Ignored with sqlite)         |
| --backend-port     | Number                   | None    | This defines the port in which the backend database is listening on (Ignored with sqlite) |
| --backend-db       | String                   | None    | This defines the database name for the backend, for sqlite, this should be a file path    |
| --backend-username | String                   | None    | This defines the username for accessing the backend database                              |
| --backend-password | String                   | None    | This defines the password for accessing the backend database                              |
| --log-file         | String                   | stdout  | This defines the filepath for outputting log data to                                      |
| ------------------ | ------------------------ | ------- | ----------------------------------------------------------------------------------------- |

## Systemd Unit
        [Unit]
	Description=SqlPi Database Abstraction Layer
	After=network.target

        [Service]
	Type=forking
	PIDFile=/run/sqlpi.pid

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
