#!/bin/sh
set -e

# First run: init database only first time
if [ ! -e RAYQUAZA ]; then
	touch RAYQUAZA
    echo "[INFO] Initializing database..."

	#init empty database
    mariadb-install-db --user=mysql --ldata=/var/lib/mysql

    envsubst < /tmp/init.sql > /tmp/init-final.sql

	#start database without network
    mysqld --user=mysql --skip-networking &
    pid="$!"

	#wait until it is ready
    until mysqladmin ping > /dev/null 2>&1; do
        sleep 1
    done

	#register database wordpress
    mysql < /tmp/init-final.sql

	#turn down database
    mysqladmin shutdown
fi

exec mysqld --user=mysql
