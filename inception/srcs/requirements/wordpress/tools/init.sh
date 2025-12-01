#!/bin/bash

#https://developer.wordpress.org/advanced-administration/before-install/#howto-install/

#https://wordpress.org/documentation/article/get-started-with-wordpress/

#https://developer.wordpress.org/advanced-administration/upgrade/ftp/

#https://developer.wordpress.org/cli/commands/core/

set -e

# 1. Aspetta MariaDB
echo "Attendo MariaDB..."
sleep 10

# 2. Se WP non è installato, fai il bootstrap
if [ ! -f /var/www/html/wp-config.php ]; then
    echo "Prima installazione di WordPress."

    # Scarica wp-cli
    curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
    chmod +x wp-cli.phar
    mv wp-cli.phar /usr/local/bin/wp

    # Scarica WordPress
    wp core download --allow-root

    # Crea wp-config
    wp config create \
        --dbname="$WP_DB" \
        --dbuser="$WP_USER" \
        --dbpass="$WP_DB_PWD" \
        --dbhost="$WP_DB_HOST" \
        --allow-root \
        --skip-check


    # Installa WordPress solo al primo avvio
    wp core install \
        --url="$WP_URL" \
        --title="$WP_TITLE" \
        --admin_user="$WP_ADMIN" \
        --admin_password="$WP_ADMIN_PWD" \
        --admin_email="$WP_ADMIN_EMAIL" \
        --skip-email \
        --allow-root

        chmod 777 /var/www/html/wp-content
         wp user create $WP_USER $WP_USER_EMAIL --role=author --user_pass=$WP_USER_PWD --allow-root
    wp theme install twentyfifteen

    wp theme activate twentyfifteen

    wp theme update twentyfifteen
else
    echo "WordPress già installato, nessuna modifica."
fi

# 3. Sistema permessi per Nginx + php-fpm
chown -R www-data:www-data /var/www/html

# Assicura che gli errori vadano in foreground
sed -i "s|^;daemonize = yes|daemonize = no|" /etc/php/8.4/fpm/php-fpm.conf

echo "Avvio php-fpm..."
#exec /usr/sbin/php-fpm8.4 --nodaemonize
/usr/sbin/php-fpm8.4 -F