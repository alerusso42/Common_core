#!/bin/bash
set -e

# ----------------------------------------
# Variabili d'ambiente attese:
# WP_DB, WP_DB_HOST, WP_USER, WP_USER_PWD
# WP_ADMIN, WP_ADMIN_PWD, WP_ADMIN_EMAIL
# WP_TITLE, WP_URL
# ----------------------------------------

echo -e "\033[32m[INIT] Avvio script di bootstrap WordPress\033[0m"

# --- 1. Attendi che MariaDB sia pronto ---
#echo -e "\033[33m[WAIT] Attendo MariaDB...\033[0m"
#until mariadb --host="$WP_DB_HOST" --user="$WP_ADMIN" --password="$WP_ADMIN_PWD" -e "SELECT 1;" >/dev/null 2>&1; do
#    echo -e "\033[33m[WAIT] MariaDB non pronta, attendo 2s...\033[0m"
#    sleep 2
#done
sleep 10
echo -e "\033[32m[OK] MariaDB pronta!\033[0m"

# --- 2. Creazione DB e utenti ---
echo -e "\033[32m[DB] Creazione database e utenti\033[0m"
mariadb --host="$WP_DB_HOST" --user="$WP_ADMIN" --password="$WP_ADMIN_PWD" <<SQL
CREATE DATABASE IF NOT EXISTS ${WP_DB};
CREATE USER IF NOT EXISTS '${WP_USER}'@'%' IDENTIFIED BY '${WP_USER_PWD}';
GRANT ALL PRIVILEGES ON ${WP_DB}.* TO '${WP_USER}'@'%';
FLUSH PRIVILEGES;
SQL
echo -e "\033[32m[OK] DB e utenti pronti\033[0m"

# --- 3. Scarica wp-cli se non esiste ---
if ! command -v wp >/dev/null 2>&1; then
    echo -e "\033[32m[WP-CLI] Installazione wp-cli\033[0m"
    curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
    chmod +x wp-cli.phar
    mv wp-cli.phar /usr/local/bin/wp
fi

# --- 4. Scarica WordPress ---
if [ ! -f /var/www/html/wp-config.php ]; then
    echo -e "\033[32m[WP] Scarico WordPress\033[0m"
    wp core download --allow-root

    # --- 5. Crea wp-config.php ---
    echo -e "\033[32m[WP] Creazione wp-config.php\033[0m"
    wp config create \
        --dbname="$WP_DB" \
        --dbuser="$WP_USER" \
        --dbpass="$WP_USER_PWD" \
        --dbhost="$WP_DB_HOST" \
        --allow-root
    
    sed -i '/Add any custom values between this line and the "stop editing" line./r /dev/stdin' /var/www/html/wp-config.php <<'EOF'

define('FORCE_SSL_ADMIN', true);
$_SERVER['HTTPS'] = 'on';

EOF

    # --- 6. Installa WordPress ---
    echo -e "\033[32m[WP] Installazione WordPress\033[0m"
    wp core install \
        --url="$WP_URL" \
        --title="$WP_TITLE" \
        --admin_user="$WP_ADMIN" \
        --admin_password="$WP_ADMIN_PWD" \
        --admin_email="$WP_ADMIN_EMAIL" \
        --allow-root \
        --skip-email

    # --- 7. Imposta permessi ---
    echo -e "\033[32m[PERM] Aggiorno permessi\033[0m"
    chown -R www-data:www-data /var/www/html
    chmod -R 755 /var/www/html
else
    echo -e "\033[33m[WP] WordPress già installato, salto\033[0m"
fi
# --- 8. Avvia PHP-FPM ---
echo -e "\033[32m[PHP-FPM] Avvio PHP-FPM in foreground\033[0m"
exec /usr/sbin/php-fpm8.4 -F
