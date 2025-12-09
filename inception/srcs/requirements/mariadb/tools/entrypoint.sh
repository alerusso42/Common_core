#!/bin/sh
set -e

# First run: init database only first time
if [ ! -e /var/lib/mysql/RAYQUAZA ]; then
	touch /var/lib/mysql/RAYQUAZA
    echo "[INFO] Initializing database..."

	#init empty database
    mariadb-install-db --user=mysql --ldata=/var/lib/mysql
    #mariadb-upgrade --user=mysql --ldata=/var/lib/mysql

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

sed -i 's/^bind-address.*/bind-address = wordpress/' /etc/mysql/mariadb.conf.d/50-server.cnf
#exec mariadbd-safe --user=mysql
exec mariadbd --user=mysql --console