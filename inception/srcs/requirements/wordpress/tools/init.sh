#!/bin/bash

#https://developer.wordpress.org/advanced-administration/before-install/#howto-install/

#https://wordpress.org/documentation/article/get-started-with-wordpress/

#https://developer.wordpress.org/advanced-administration/upgrade/ftp/
#while ! mysqladmin ping -hmariadb --silent \
#  --user=$WP_USER \
#  --password=$WP_USER_PWD; do
#    echo -e "\033[33mTime passed:\t" $timer  "(exit status " $? ")\033[0m"
#    sleep 1
#    timer=$(expr $timer + 1)
#done
#https://developer.wordpress.org/cli/commands/core/

set -e

# 1. Aspetta MariaDB
#timer=0
#echo "Aspetto MariaDB..."
#while ! mariadb --host=mariadb --user=$WP_USER --password=$WP_USER_PWD --execute="SELECT 1;"; do
#    printf "\033[31mTime passed:\t\033[0m%d\033[31m Seconds.\033[0m\n" $timer
##    timer=$(expr $timer + 1)
#    sleep 1
#done
#echo "MariaDB pronta."

sleep 10

# 2. Se WP non è installato, fai il bootstrap
# if [ ! -f /var/www/html/wp-config.php ]; then
if [ ! -f /var/www/html/wp-config.php ]; then

    # Scarica wp-cli
    echo -e "\033[32mSECTION 1: scarica wp-cli\033[0m"
    curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
    chmod +x wp-cli.phar
    mv wp-cli.phar /usr/local/bin/wp

    # Scarica WordPress
    echo -e "\033[32mSECTION 2: scarica wordpress\033[0m"
    wp core download --allow-root

    # Crea wp-config
    echo -e "\033[32mSECTION 3: crea wp config file\033[0m"
    wp config create \
        --dbname="$WP_DB" \
        --dbuser="$WP_USER" \
        --dbpass="$WP_DB_PWD" \
        --dbhost="$WP_DB_HOST" \
        --allow-root \
        --skip-check


    # Installa WordPress solo al primo avvio
    echo -e "\033[32mSECTION 4: Installa wp:\n"\
            "mariadb connection:$WP_MARIADB_CON \n" \
            "title:             $WP_TITLE \n" \
            "admin:             $WP_ADMIN \n" \
            "admin password:    $WP_ADMIN_PWD \n" \
            "admin email:       $WP_ADMIN_EMAIL \n" \
    ":\033[0m"
    wp core install \
        --url=$WP_MARIADB_CON \
        --title="$WP_TITLE" \
        --admin_user="$WP_ADMIN" \
        --admin_password="$WP_ADMIN_PWD" \
        --admin_email="$WP_ADMIN_EMAIL" \
        --skip-email \
        --allow-root

        echo -e "\033[32mSECTION 5: Cambia permessi\033[0m"
        chmod 777 /var/www/html/wp-content
        echo    "\033[32mSECTION 6: Crea utente $WP_USER \
                con email $WP_USER_EMAIL \
                con password $WP_USER_PWD \
                \033[0m"
         wp user create $WP_USER $WP_USER_EMAIL --role=author --user_pass=$WP_USER_PWD --allow-root
    
    echo -e "\033[32mSECTION 7: Installa grafica\033[0m"
    wp theme install twentyfifteen

    wp theme activate twentyfifteen

    wp theme update twentyfifteen
    else
        echo -e "WordPress già installato, nessuna modifica."
        fi

        # 3. Sistema permessi per Nginx + php-fpm
        echo -e "\033[32mSECTION 1.2: Cambia proprietario file\033[0m"
        chown -R www-data:www-data /var/www/html

        # Assicura che gli errori vadano in foreground
        #sed -i "s|^;daemonize = yes|daemonize = no|" /etc/php/8.4/fpm/php-fpm.conf

        echo -e "\033[32mSECTION 1.3: Avvia php-fpm\033[0m"
        #exec /usr/sbin/php-fpm8.4 --nodaemonize
        /usr/sbin/php-fpm8.4 -F