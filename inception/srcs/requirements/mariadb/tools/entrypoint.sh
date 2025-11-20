#!/bin/sh
set -e

# First run
if [ ! -d /var/lib/mysql/mysql ]; then
    echo "[INFO] Initializing database..."

    mariadb-install-db --user=mysql --ldata=/var/lib/mysql

    envsubst < /tmp/init.sql > /tmp/init-final.sql

    mysqld --user=mysql --skip-networking &
    pid="$!"

    until mysqladmin ping > /dev/null 2>&1; do
        sleep 1
    done

    mysql < /tmp/init-final.sql

    mysqladmin shutdown
fi

exec mysqld --user=mysql
