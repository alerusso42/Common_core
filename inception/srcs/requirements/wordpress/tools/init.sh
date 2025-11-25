#!/bin/bash

#https://developer.wordpress.org/advanced-administration/before-install/#howto-install/

#https://wordpress.org/documentation/article/get-started-with-wordpress/

#https://developer.wordpress.org/advanced-administration/upgrade/ftp/

#https://developer.wordpress.org/cli/commands/core/

#!/bin/bash

set -e

until mysql -h mariadb -u"$DB_USER" -p"$DB_PASS" -e "select 1" >/dev/null 2>&1; do
    sleep 1
done

if [ ! -f /var/www/html/wp-config.php ]; then
    wp core download --allow-root
    wp config create ... --allow-root
    wp core install ... --allow-root
fi

# create directory to use in nginx container later and also to setup the wordpress conf
mkdir -p /var/www/html

cd /var/www/html

# remove all the wordpress files if there is something from the volumes to install it again
rm -rf *

# The commands are for installing and using the WP-CLI tool.

# downloads the WP-CLI PHAR (PHP Archive) file from the GitHub repository. The -O flag tells curl to save the file with the same name as it has on the server.
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar 

echo FINO A CURL OK

# makes the WP-CLI PHAR file executable.
chmod +x wp-cli.phar 

# moves the WP-CLI PHAR file to the /usr/local/bin directory, which is in the system's PATH, and renames it to wp. This allows you to run the wp command from any directory
mv wp-cli.phar /usr/local/bin/wp

# downloads the latest version of WordPress to the current directory. The --allow-root flag allows the command to be run as the root user, which is necessary if you are logged in as the root user or if you are using WP-CLI with a system-level installation of WordPress.
wp core download --allow-root

echo FINO A WP CORE DOWNLOAD OK

mv /var/www/html/wp-config-sample.php /var/www/html/wp-config.php

# change the those lines in wp-config.php file to connect with database

#line 23
sed -i -r "s/database/$WP_USER/1"   wp-config.php
#line 26
sed -i -r "s/database_user/$WP_USER/1"  wp-config.php
#line 29
sed -i -r "s/passwod/$WP_USER_PWD/1"    wp-config.php

#line 32
sed -i -r "s/localhost/mariadb/1"    wp-config.php

echo FINO A SED OK

echo $DOMAIN_NAME $WP_TITLE $WP_ADMIN $WP_ADMIN_PWD

# installs WordPress and sets up the basic configuration for the site. The --url option specifies the URL of the site, --title sets the site's title, --admin_user and --admin_password set the username and password for the site's administrator account, and --admin_email sets the email address for the administrator. The --skip-email flag prevents WP-CLI from sending an email to the administrator with the login details.
wp core install --url=$DOMAIN_NAME/ --title=$WP_TITLE --admin_user=$WP_ADMIN --admin_password=$WP_ADMIN_PWD --admin_email=$WP_ADMIN_EMAIL --skip-email --allow-root

echo wp install OK

# creates a new user account with the specified username, email address, and password. The --role option sets the user's role to author, which gives the user the ability to publish and manage their own posts.
wp user create $WP_USER $WP_EMAIL --role=author --user_pass=$WP_PWD --allow-root

echo wp user create OK

# installs the Astra theme and activates it for the site. The --activate flag tells WP-CLI to make the theme the active theme for the site.
wp theme install astra --activate --allow-root

echo wp theme install OK

echo FINO A installation ok

wp plugin install redis-cache --activate --allow-root

echo FINO A redis ok

# uses the sed command to modify the www.conf file in the /etc/php/7.3/fpm/pool.d directory. The s/listen = \/run\/php\/php7.3-fpm.sock/listen = 9000/g command substitutes the value 9000 for /run/php/php7.3-fpm.sock throughout the file. This changes the socket that PHP-FPM listens on from a Unix domain socket to a TCP port.
sed -i 's/listen = \/run\/php\/php7.3-fpm.sock/listen = 9000/g' /etc/php/7.3/fpm/pool.d/www.conf

# creates the /run/php directory, which is used by PHP-FPM to store Unix domain sockets.
mkdir /run/php


wp redis enable --allow-root


# starts the PHP-FPM service in the foreground. The -F flag tells PHP-FPM to run in the foreground, rather than as a daemon in the background.
/usr/sbin/php-fpm7.3 -F