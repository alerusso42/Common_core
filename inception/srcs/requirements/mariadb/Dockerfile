# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 11:58:16 by alerusso42        #+#    #+#              #
#    Updated: 2025/12/16 12:20:02 by alerusso42       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:trixie

# ANCHOR - sources
# https://mariadb.com/docs
# https://mariadb.com/docs/server/mariadb-quickstart-guides/installing-mariadb-server-guide

#/etc/mysql/mariadb.conf.d/50-server.cnf

#ANCHOR - install 
RUN apt update
# Install
RUN apt install -y mariadb-server mariadb-client galera-4 gettext-base

#Verify installation by connecting as root:Bash
#mariadb -u root -p

# Create run directory
RUN mkdir -p /run/mysqld && chown -R mysql:mysql /run/mysqld
RUN chown -R mysql:mysql /var/lib/mysql

# Copy scripts
COPY tools/init.sql /tmp/init.sql
COPY tools/entrypoint.sh /usr/local/bin/entrypoint.sh
RUN chmod 755 /usr/local/bin/entrypoint.sh

EXPOSE 3306

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]

# CMD ["mysqld"]

