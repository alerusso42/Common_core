*This project has been created as part of the 42 curriculum by alerusso.*

# devDoc

DEV_DOC.md — Developer documentation This file must describe how a devel-
oper can:

## Prerequisites

Install docker and docker-compose

https://www.notion.so/odoacr3e/Install-docker-and-docker-compose-297e699f982b80a7b181cefa3741c5d5?source=copy_link

Create the ./srcs/.env file and fill it (see USER.DOC.md)

## Environment

Environment and sensisitive information are stored in the .env file.

## Usage

all: 	up
daemon: up using a daemon process
stop:	shuts down all containers
clean:	stop
fclean: stop and removes volumes
re: 	fclean daemon
logs:	print containers log
		USAGE: make logs cont="container name"/cont=all
exec:	run the /bin/bash command inside a running container 
		USAGE: make exec cont="container name"

## Other commands

### docker volume ls

Shows all active volumes

### docker network ls

Shows all active docker networks

### docker network inspect inception

Shows inception network data 

### Mariadb database info

make exec cont=mariadb          #   enters in the container
mysql -u WP_USER/WP_ADMIN -p    #   log in to mariadb database
WP_USER_PWD/WP_ADMIN_PWD        #   enters password from .env   
SHOW DATABASES ;                #	show all databases
USE wordpress;  			    #	open wordpress database
SHOW TABLES ;                   #	show all tables
SELECT user_login FROM wp_users;#	only with root mode: show all users
SELECT * FROM table_name;	    #	show every content from a table
quit/exit					    #	exits from mariadb
exit                            #   exits from /bin/bash in the container

## Docker Volumes location

/home/alerusso/data/mariadb
/home/alerusso/data/wordpress