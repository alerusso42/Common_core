*This project has been created as part of the 42 curriculum by alerusso.*

# userDoc

USER_DOC.md — User documentation This file must explain, in clear and simple terms, how an end user or administrator can:
◦ Understand what services are provided by the stack.
◦ Start and stop the project.
◦ Access the website and the administration panel.
◦ Locate and manage credentials.
◦ Check that the services are running correctly.

## Services provided

The stack is composed of three main interconnected containers:

    Nginx: The entry point of the infrastructure. A web server configured with TLSv1.2/v1.3 to securely serve the WordPress site over HTTPS.

    MariaDB: The relational database management system that stores all WordPress data (posts, users, and settings).

    WordPress: The content management system (CMS) powered by PHP-FPM, which handles the website logic and communicates with the database.

## Start and stop project

### Install Docker

https://www.notion.so/odoacr3e/Install-docker-and-docker-compose-297e699f982b80a7b181cefa3741c5d5?source=copy_link

### .env file

1.  Create the /srcs/.env file
2.  Format it in this way:
### VARIABLES YOU CAN TOUCH

WP_DOMAIN=example
WP_TITLE=example
WP_URL=https://localhost

WP_ADMIN=example
WP_ADMIN_PWD=example
WP_ADMIN_EMAIL=example@example.com
WP_MARIADB_CON=https://localhost

WP_USER=example
WP_USER_PWD=example
WP_USER_EMAIL=example@example.com

### VARIABLES YOU MUST NOT TOUCH

WP_DB=wordpress
WP_DB_PWD=secret
WP_DB_HOST=mariadb

### Commands:

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

## Access the website and the administration panel.

1.  Run "make all/make daemon"
2.  Connect to localhost (Write "https://localhost/" on browser url)
3.  Write https://localhost/wp-admin/
4.  Insert admin credentials from .env
5.  Use admin page

## Locate and manage credentials

Modify the .env file.

## Check that the services are running correctly

docker volume ls        #   should print mariadb and wordpress 
make logs cont=all      #   should print this line -----*
                                                        |
DATE 0 [Note] mariadbd: ready for connections.